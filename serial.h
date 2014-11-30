/*
   File:   serial.h
   Author: mdunne

   Created on November 10, 2011, 8:43 AM
 */

#ifndef SERIAL_H
#define SERIAL_H

#define QUEUESIZE 1024

typedef struct CircBuffer {
    unsigned char buffer[QUEUESIZE];
    int head;
    int tail;
    unsigned int size;
    unsigned char overflowCount;
} CircBuffer;
typedef struct CircBuffer* CBRef;
/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
struct CircBuffer outgoingUart;
CBRef transmitBuffer;
struct CircBuffer incomingUart;
CBRef receiveBuffer;

struct CircBuffer outgoingUart2;
CBRef transmitBuffer2;
struct CircBuffer incomingUart2;
CBRef receiveBuffer2;

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/


/**
 * @Function SERIAL_Init(void)
 * @param none
 * @return none
 * @brief  Initializes the UART subsystem to 115200 and sets up the circular buffer
 * @author Max Dunne, 2011.11.10 */
void SERIAL_Init(void);

/**
 * @Function PutChar(char ch)
 * @param ch - the char to be sent out the serial port
 * @return None.
 * @brief  adds char to the end of the circular buffer and forces the interrupt flag
 * high if nothing is currently transmitting
 * @author Max Dunne, 2011.11.10 */
void PutChar(char ch);

/**
 * @Function GetChar(void)
 * @param None.
 * @return ch - char from the serial port
 * @brief  reads first character from buffer or returns 0 if no chars available
 * @author Max Dunne, 2011.11.10 */
char GetChar(void);

/**
 * @Function IsTransmitEmpty(void)
 * @param None.
 * @return TRUE or FALSE
 * @brief  returns the state of the receive buffer
 * @author Max Dunne, 2011.12.15 */
char IsTransmitEmpty(void);

/**
 * @Function IsReceiveEmpty(void)
 * @param None.
 * @return TRUE or FALSE
 * @brief  returns the state of the receive buffer
 * @author Max Dunne, 2011.12.15 */
char IsReceiveEmpty(void);

unsigned int getLength(CBRef cB);

unsigned int getRcvLength(void);
unsigned int getRcv2Length(void);
void makeEmptyRcv2(void);
unsigned char peakRcv2(void);
void freeCircBufferRcv2();

#endif // serial_h
