/*********************************************************************
 *
 *      PIC32MX I2C Example
 *
 *********************************************************************
 * FileName:        i2c_master.c
 * Dependencies:    plib.h
 *
 * Processor:       PIC32MX
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PIC32MX Microcontroller is intended
 * and supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *********************************************************************
 * Change History:
 * Name        Date            Changes
 * A Rafiq     2/7/07          Initial Version
 * JM          2/7/09          Updated
 *
 * $Id: i2c_master.c 9558 2008-07-04 10:08:49Z deshmukha $
 *
 * Demo Code Description:
 * This example interfaces with a 24LC256 serial eeprom on
 * I2C channel 1. The code writes to a location and then
 * verifies the contents of the eeprom. I2C Channel 1 is
 * hooked up to 24LC256, while the address lines of the
 * eeprom are all tied to Vss.
 ********************************************************************/
#include "i2c_master.h"

// DEVICE Constants
// EEPROM Constants


/*******************************************************************************
  Function:
    BOOL StartTransfer( BOOL restart )

  Summary:
    Starts (or restarts) a transfer to/from the EEPROM.

  Description:
    This routine starts (or restarts) a transfer to/from the EEPROM, waiting (in
    a blocking loop) until the start (or re-start) condition has completed.

  Precondition:
    The I2C module must have been initialized.

  Parameters:
    restart - If FALSE, send a "Start" condition
            - If TRUE, send a "Restart" condition
    
  Returns:
    TRUE    - If successful
    FALSE   - If a collision occured during Start signaling
    
  Example:
    <code>
    StartTransfer(FALSE);
    </code>

  Remarks:
    This is a blocking routine that waits for the bus to be idle and the Start
    (or Restart) signal to complete.
  *****************************************************************************/
BOOL Succ = TRUE;
BOOL StartTransfer( BOOL restart )
{
    I2C_STATUS  status;

    // Send the Start (or Restart) signal
    if(restart)
    {
        I2CRepeatStart(PIC24_I2C_BUS);
    }
    else
    {
        // Wait for the bus to be idle, then start the transfer
        while( !I2CBusIsIdle(PIC24_I2C_BUS) );

        if(I2CStart(PIC24_I2C_BUS) != I2C_SUCCESS)
        {
            DBPRINTF("Error: Bus collision during transfer Start\n");
            printf("bus coll\n");
            //Succ = FALSE;
            //goto RECOVER;
        }
    }

    // Wait for the signal to complete
    do
    {
        status = I2CGetStatus(PIC24_I2C_BUS);
        //printf("waiting for signal\n");

    } while ( !(status & I2C_START) );

RECOVER:
    //if(!Succ) return FALSE;
    //else return TRUE;
return TRUE;
}


/*******************************************************************************
  Function:
    BOOL TransmitOneByte( UINT8 data )

  Summary:
    This transmits one byte to the EEPROM.

  Description:
    This transmits one byte to the EEPROM, and reports errors for any bus
    collisions.

  Precondition:
    The transfer must have been previously started.

  Parameters:
    data    - Data byte to transmit

  Returns:
    TRUE    - Data was sent successfully
    FALSE   - A bus collision occured

  Example:
    <code>
    TransmitOneByte(0xAA);
    </code>

  Remarks:
    This is a blocking routine that waits for the transmission to complete.
  *****************************************************************************/

BOOL TransmitOneByte( UINT8 data )
{
    char Success = TRUE;
    // Wait for the transmitter to be ready
    while(!I2CTransmitterIsReady(PIC24_I2C_BUS));

    // Transmit the byte
    if(I2CSendByte(PIC24_I2C_BUS, data) == I2C_MASTER_BUS_COLLISION)
    {
        DBPRINTF("Error: I2C Master Bus Collision\n");
        printf("bus coll\n");
        goto END2;
        Success = FALSE;
    }

    // Wait for the transmission to finish
    while(!I2CTransmissionHasCompleted(PIC24_I2C_BUS));
END2:
    if(Success == FALSE){return FALSE;}
    else return TRUE;
}


/*******************************************************************************
  Function:
    void StopTransfer( void )

  Summary:
    Stops a transfer to/from the EEPROM.

  Description:
    This routine Stops a transfer to/from the EEPROM, waiting (in a 
    blocking loop) until the Stop condition has completed.

  Precondition:
    The I2C module must have been initialized & a transfer started.

  Parameters:
    None.
    
  Returns:
    None.
    
  Example:
    <code>
    StopTransfer();
    </code>

  Remarks:
    This is a blocking routine that waits for the Stop signal to complete.
  *****************************************************************************/

void StopTransfer( void )
{
    I2C_STATUS  status;

    // Send the Stop signal
    I2CStop(PIC24_I2C_BUS);

    // Wait for the signal to complete
    do
    {
        status = I2CGetStatus(PIC24_I2C_BUS);

    } while ( !(status & I2C_STOP) );
}

int RcvData(unsigned int address) {
	StartI2C1();				//Send line start condition
	IdleI2C1();			        //Wait to complete
	MasterWriteI2C1((address << 1) | 1);	//Write out slave address OR 1 (read command)
	IdleI2C1();				//Wait to complete
	int rcv = MasterReadI2C1();		//Read in a value
	StopI2C1();				//Send line stop condition
	IdleI2C1();				//Wait co complete
	return rcv;				//Return read value
}

void SendData (int data, unsigned int address){
	StartI2C1();	        //Send the Start Bit
	IdleI2C1();		//Wait to complete

	MasterWriteI2C1((address << 1) | 0);  //Sends the slave address over the I2C line.  This must happen first so the
                                             //proper slave is selected to receive data.
	IdleI2C1();	        //Wait to complete

	MasterWriteI2C1(data);  //Sends data byte over I2C line
	IdleI2C1();		//Wait to complete

	StopI2C1();	        //Send the Stop condition
	IdleI2C1();	        //Wait to complete

} //end function


// ****************************************************************************
// ****************************************************************************
// Application Main Entry Point
// ****************************************************************************
// ****************************************************************************

