/* 
 * File:   i2c_master.h
 * Author: ryanarodriguez
 *
 * Created on August 1, 2014, 1:46 AM
 */

#ifndef I2C_MASTER_H
#define	I2C_MASTER_H
#endif

#include <plib.h>
#include "i2c.h"

I2C_7_BIT_ADDRESS SlaveAddress;
#define PIC24_I2C_BUS               I2C1
#define PIC24_ADDRESS               0xA2        //not yet known - probably hard coded by pic24

#define SYS_FREQ (80000000L)
#define GetSystemClock()           (SYS_FREQ)
#define GetPeripheralClock()       (SYS_FREQ/1)
#define GetInstructionClock()      (SYS_FREQ)
#define I2C_CLOCK_FREQ             100000




BOOL StartTransfer( BOOL restart );

BOOL TransmitOneByte( UINT8 data );

void StopTransfer( void );
