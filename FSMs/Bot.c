/**
* @file Bot.c
* @author Ryan Rodriguez
* @date 12/26/14
* @brief Hardware Initialization file
*
* This file is used to initialize GPIO, stepper interrupts, servo, and Uart
* capabilities.
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
#define LIMIT 8

uint8_t temp = 0, i = 0;
static uint8_t LSB = 0, MSB = 0;
static unsigned short AD_VALS[NUM_ANALOG_IN] = {0, 0, 0};
unsigned int hammingWeight = 0, parityBit = 0;

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

    DataEEInit();
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

/**
 * Hamming weight calculation
 * @param  n [bit string to be counted]
   * @return   [the number of ones in n
 */
int count_bits(int n) {
    unsigned int c; // c accumulates the total bits set in v
    for (c = 0; n; c++)
        n &= n - 1; // clear the least significant bit set
    return c;
}

/**
 * Check the parity bit
 * @param  n [bit string to be checked]
 * @return   [returns parity]
 */
BOOL parity_bits(char n) {
    unsigned int c; // c accumulates the total bits set in v
    c = (n & 0x01); //mask parity
    return c;
}

void uart(void) {
    UART1ClearAllErrors();
    i = 0;
    if (getLength(receiveBuffer) < LIMIT + 16) goto END;
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
    } else {
        temp = GetChar();
        temp = peak(receiveBuffer);
        if (temp != 'e') goto END;
        temp = GetChar();
    }

    for (i = 0; i < NUM_ANALOG_IN; i++) {
        temp = (uint8_t) (((peak(receiveBuffer) & 0xF0)) >> 4);
        switch (temp) {
            case 1:
                MSB = GetChar();
                LSB = GetChar();
                hammingWeight = GetChar();
                parityBit = GetChar();
                if ((hammingWeight == (count_bits(MSB) + count_bits(LSB)))
                        && (parityBit == (parity_bits(LSB) + parity_bits(MSB)))) {

                    AD_VALS[0] = ((MSB & 0x0F) << 8 | LSB);

                } else AD_VALS[0] = AD_VALS[0]; //break the filter
                break;

            case 2:
                MSB = GetChar();
                LSB = GetChar();
                hammingWeight = GetChar();
                parityBit = GetChar();
                if ((hammingWeight == (count_bits(MSB) + count_bits(LSB)))
                        && (parityBit == parity_bits(LSB) + parity_bits(MSB))) {

                    AD_VALS[1] = ((MSB & 0x0F) << 8 | LSB);
                } else AD_VALS[1] = AD_VALS[1]; //break the filter
                break;
            case 4:
                MSB = GetChar();
                LSB = GetChar();
                hammingWeight = GetChar();
                parityBit = GetChar();
                if ((hammingWeight == (count_bits(MSB) + count_bits(LSB)))
                        && (parityBit == parity_bits(LSB) + parity_bits(MSB))) {
                    AD_VALS[2] = ((MSB & 0x0F) << 8 | LSB);

                } else AD_VALS[2] = AD_VALS[2]; //break the filter
                break;

            default:
                goto END;
                break;
        }
    }
    /*Dont run this yet - make sure to set up PIC24 for duplexing.
    //If we're here, just receive a set of packets. Change to TrX mode and send ACK
    RS485_TRX_EN = 1;
    PutChar('A');
    PutChar('C');
    PutChar('K');
    RS485_TRX_EN = 0;
     * */
END:
    ;
}
