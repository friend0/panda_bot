/*
 * File:   Bot.c
 * Author: ryarodri
 *
 * Created on December 17, 2013, 11:25 PM
 */
#include "bot.h"
#include "ES_Configure.h"
#include "dee_emulation_pic32.h"
#include "i2c_master.h"
#include "ES_Timers.h"
#include <plib.h>
#include <string.h>
//#include "timers.h"

/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
//#define LEFT_PWM PWM_PORTZ06
//#define RIGHT_PWM PWM_PORTY12

#define NOPCOUNT 150
#define DELAY() for(i=0; i< NOPCOUNT; i++) __asm("nop")
#define THRESHOLD 250
uint8_t lh_byte = 0, temp = 0, channel = 0, i = 0, j = 0;
volatile uint8_t lo_byte = 0, hi_byte = 0, idx = 0;
BOOL Success = TRUE, rcvFlag = FALSE;
static unsigned short AD_VALS[NUM_ANALOG_IN] = {0, 0, 0};
static unsigned int AD_VALS_BYTEWISE[NUM_ANALOG_IN * 2] = {0};
static unsigned int CRC[NUM_ANALOG_IN * 4] = {0}; //2 parity bytes per byte, two bytes per word
static unsigned int currentTime = 0, transitionTime = 0;

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                           *
 ******************************************************************************/
int actualClock;

void Bot_Init(void) {
    //show the world you got a bubble butt
    PORTX05_TRIS = 0;
    PORTX05_BIT = 0;

    //PWM_AddPins(LEFT_PWM | RIGHT_PWM);
    //Hardware Inits
    //TIMERS_Init();
    setupADRC_Pins();
    setup_Pins();
    //Steppers_Init(77);
    //Stepper_Init(MOTOR_X, 76);
    //DELAY();
    //DELAY();
    //Stepper_Init(MOTOR_Y, 76);

    DataEEInit();
    //actualClock = I2CSetFrequency(PIC24_I2C_BUS, GetPeripheralClock(), I2C_CLOCK_FREQ);
    //I2CEnable(PIC24_I2C_BUS, TRUE);
    //I2CSetSlaveAddress(I2C1, PIC24_ADDRESS, 0, I2C_USE_7BIT_ADDRESS);

}

void setupADRC_Pins(void) {
    //PORTSetPinsDigitalOut(IOPORT_B, PIN3);
    mPORTBSetPinsDigitalOut(BIT_3);
    mPORTBClearBits(BIT_3);
    RS485_TRX_EN_TRIS = 1; //set as input, pull trx_en to grnd(receive mode)
    RS485_TRX_EN = 0;
    SERVO_ENABLE_TRIS = 1; //set servo enable pin to input
    RC_Init();
    RC_AddPins(AZIMUTH_RC);
}

void setup_Pins(void) {
    X_LIMIT_MIN_TRIS = 1;
    X_LIMIT_MAX_TRIS = 1;
    Y_LIMIT_MIN_TRIS = 1;
    Y_LIMIT_MAX_TRIS = 1;
}

unsigned int ReadAzimuth(void) {
    static unsigned int currentState = 0;
    if (currentState < 0) return 0;
    else
        currentState = (AD_VALS[AZIMUTH_POT]);
    return currentState;
}

unsigned int ReadXSlider(void) {
    static int currentState = 0;
    currentState = AD_VALS[X_SLIDER];
    return currentState;
}

unsigned int ReadYSlider(void) {
    static int currentState = 0;
    currentState = AD_VALS[Y_SLIDER];
    return currentState;
}

unsigned int Read_Limits(void) {
    unsigned int presetState = 0x00000000;
    presetState = (X_LIMIT_MIN + ((X_LIMIT_MAX) << 1)+((Y_LIMIT_MIN) << 2)+((Y_LIMIT_MAX) << 3));
    return presetState;
}

struct lsbMsb {
    unsigned int LSB;
    unsigned int MSB;

};

struct lsbMsb lsbMsbArr[4];

char Read_ADC_over_I2C(void) {

    //I2C_FORMAT_7_BIT_ADDRESS(SlaveAddress, PIC24_ADDRESS, I2C_WRITE);
    //uart();
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {

            if (!StartTransfer(FALSE)) {
                //while(1);
                DBPRINTF("Error: Sent byte was not acknowledged\n");
                printf("Error: Sent byte was not acknowledged\n");
                Success = FALSE;
                goto END;
            }

            // Transmit the address with the READ bit set
            //I2C_FORMAT_7_BIT_ADDRESS(SlaveAddress, PIC24_ADDRESS, I2C_READ);

            if (TransmitOneByte(SlaveAddress.byte)) {
                // Slave ACK
                if (!I2CByteWasAcknowledged(PIC24_I2C_BUS)) {
                    DBPRINTF("Error: Sent byte was not acknowledged\n");
                    printf("error2\n");
                    Success = FALSE;
                    goto END;
                }
            } else {
                Success = FALSE;
                printf("error3\n");
                goto END;
            }

            if (I2CReceiverEnable(PIC24_I2C_BUS, TRUE) == I2C_RECEIVE_OVERFLOW) {
                DBPRINTF("Error: I2C Receive 1 Overflow\r\n");
                printf("Error: I2C Receive 1 Overflow\r\n");

                Success = FALSE;
                goto END;
            } else {
                while (!I2CReceivedDataIsAvailable(PIC24_I2C_BUS));
                if (j == 0) {
                    lsbMsbArr[i].LSB = I2CGetByte(PIC24_I2C_BUS);
                } else lsbMsbArr[i].MSB = I2CGetByte(PIC24_I2C_BUS);

            }

            StopTransfer(); //Done receiving, send a NACK, terminate session
        }
        ADC_I2C[i] = lsbMsbArr[i].MSB << 8 | lsbMsbArr[i].LSB;
        //printf("ADC_CHAN[%d]:%d\n:", i, ADC_I2C[i]);
        //printf("lobyte:%x\n hibyte:%x\n", lsbMsbArr[i].LSB, lsbMsbArr[i].MSB);
    }
END:
    if (Success == FALSE) {
        //StopTransfer();
        Success = TRUE; //reset Succes flag?
        return FALSE;
    } else return TRUE;
    //If not success...
}

typedef enum {
    START = 0,
    LENGTH,
    RECEIVING_DATA,
    CHECK,
    FINISH

} uart_st;

static uart_st uart_state = 15, lastState = START;
static uint8_t LSB = 0, MSB = 0;

int count_bits(int n) {
    unsigned int c; // c accumulates the total bits set in v
    for (c = 0; n; c++)
        n &= n - 1; // clear the least significant bit set
    return c;
}

BOOL parity_bits(char n) {
    unsigned int c; // c accumulates the total bits set in v
    c = (n & 0x01); //mask parity
    return c;
}
unsigned int count = 0;
#define LIMIT 8

unsigned int hammingWeight = 0, parityBit = 0;

unsigned short get_AD_VALS(uint8_t index) {
    switch (index) {
        case AZIMUTH_POT:
            return AD_VALS[AZIMUTH_POT];
            break;


        case X_SLIDER:
            return AD_VALS[X_SLIDER];
            break;

        case Y_SLIDER:
            return AD_VALS[Y_SLIDER];
            break;

        default:
            return -1;
    }
}

int ix = 0;
BOOL first = FALSE;

void uart(void) {
    //PutChar2('A');
    UART1ClearAllErrors();
    //while(!IsTransmitEmpty2());
    //temp = GetChar();
    //printf("stream:%d\n", temp);

    if (getLength(receiveBuffer) < LIMIT + 16) goto END;

    //temp = ((peak(receiveBuffer) & 0xf0)) >> 4; //what if the peak is misaligned?
    temp = peak(receiveBuffer);

    if (temp != ('z')) {
        do {
            temp = GetChar();
            temp = (peak(receiveBuffer));
        } while ((i++ <= LIMIT) && (temp != 'z'));
        temp = GetChar();
        temp = peak(receiveBuffer);
        if (temp != 'e') goto END;
        temp = GetChar();
        //PORTX05_BIT = 1;

    } else {
        temp = GetChar();
        temp = peak(receiveBuffer);
        if (temp != 'e') goto END;
        temp = GetChar();
        //PORTX05_BIT = 1;

    }

    for (i = 0; i < NUM_ANALOG_IN; i++) {

        temp = (uint8_t) (((peak(receiveBuffer) & 0xF0)) >> 4);

        switch (temp) {

            case 1:
                //printf("First\n");
                MSB = GetChar();
                LSB = GetChar();
                hammingWeight = GetChar();
                parityBit = GetChar();

                //printf("%d, %d, %d\n", LSB, MSB, ((MSB & 0x0f) << 8 | LSB));
                if ((hammingWeight == (count_bits(MSB) + count_bits(LSB)))
                        && (parityBit == (parity_bits(LSB) + parity_bits(MSB)))) {

                    AD_VALS[0] = ((MSB & 0x0F) << 8 | LSB);

                } else AD_VALS[0] = AD_VALS[0]; //break the filter
                break;

            case 2:
                //printf("Second\n");
                MSB = GetChar();
                LSB = GetChar();
                hammingWeight = GetChar();
                parityBit = GetChar();
                //printf("%d,%d, %d\n", LSB, MSB, ((MSB & 0x0f) << 8 | LSB));
                if ((hammingWeight == (count_bits(MSB) + count_bits(LSB)))
                        && (parityBit == parity_bits(LSB) + parity_bits(MSB))) {

                    AD_VALS[1] = ((MSB & 0x0F) << 8 | LSB);
                } else AD_VALS[1] = AD_VALS[1]; //break the filter
                break;
            case 4:
                //printf("Third\n");
                MSB = GetChar();
                LSB = GetChar();
                hammingWeight = GetChar();
                parityBit = GetChar();
                //printf("%d,%d, %d\n", LSB, MSB, ((MSB & 0x0f) << 8 | LSB));
                if ((hammingWeight == (count_bits(MSB) + count_bits(LSB)))
                        && (parityBit == parity_bits(LSB) + parity_bits(MSB))) {
                    AD_VALS[2] = ((MSB & 0x0F) << 8 | LSB);

                } else AD_VALS[2] = AD_VALS[2]; //break the filter
                break;

                /*
            case 8:
                //printf("Fourth\n");
                MSB = GetChar();
                LSB = GetChar();
                hammingWeight = GetChar();
                parityBit = GetChar();
                //printf("%d,%d, %d\n\n", LSB, MSB, ((MSB & 0x0f) << 8 | LSB));
                if ((hammingWeight == (count_bits(MSB) + count_bits(LSB)))
                        && (parityBit == parity_bits(LSB) + parity_bits(MSB))) {
                    AD_VALS[3] = ((MSB & 0x0f) << 8 | LSB);
                } else AD_VALS[3] = 1024; //break the filter

                break;
                 */
            default:
                goto END;
                break;
        }
    }

    for (i = 0; i < NUM_ANALOG_IN; i++) {
        if(AD_VALS[i] != 0){
        }
        else{
        }
        //printf("ADVALS[%d]:%d \n", i, (unsigned int) AD_VALS[i]);
    }

END:
    ;
    //PORTX05_BIT = 1;

}
