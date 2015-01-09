/**
* @file BotMain.c
* @author Ryan Rodriguez
* @date 12/26/14
* @brief main function for execution
*
* This file runs the state machine by calling hardware inits, configuring
* uC functions, and running infinite loop.
*/
#include <xc.h>
#include <stdio.h>
#include "ES_Configure.h"
#include "ES_Framework.h"
//#include "ES_Timers.h"
#include "serial.h"
#include "BOARD.h"
#include "peripheral/ports.h"
#include "IO_Ports.h"

// application defines
#define SYS_FREQ      (80000000L)

#pragma config FPLLIDIV 	= DIV_2		//PLL Input Divider
#pragma config FPLLMUL 		= MUL_20	//PLL Multiplier
#pragma config FPLLODIV 	= DIV_1 	//System PLL Output Clock Divid
#pragma config FNOSC 		= PRIPLL	//Oscillator Selection Bits
#pragma config FSOSCEN 		= OFF		//Secondary Oscillator Enable
#pragma config IESO 		= OFF		//Internal/External Switch O
#pragma config POSCMOD 		= XT		//Primary Oscillator Configuration
#pragma config OSCIOFNC 	= OFF		//CLKO Output Signal Active on the OSCO Pin
#pragma config FPBDIV 		= DIV_2		//Peripheral Clock Divisor
#pragma config FCKSM 		= CSECMD	//Clock Switching and Monitor Selection
#pragma config WDTPS 		= PS1		//Watchdog Timer Postscaler
#pragma config FWDTEN		= OFF		//Watchdog Timer Enable
#pragma config ICESEL		= ICS_PGx2	//ICE/ICD Comm Channel Select
#pragma config PWP 			= OFF		//Program Flash Write Protect
#pragma config BWP 			= OFF		//Boot Flash Write Protect bit
#pragma config CP 			= OFF		//Code Protect
#pragma FPBDIV                  = DIV_2

#define CAPABILITIES    (blCapBootLED | blCapDownloadLED | blCapUARTInterface | blCapAutoResetListening | blCapVirtualProgramButton | CAPCOMMON)
// BTN / LED sense
#define LedOn       High
#define BntOn       High
// Boot LED
#define BLedLat     G
#define BLedBit     6
// Download LED
#define DLedLat     F
#define DLedBit     0
// Virtual program button
#define VPBntLat    C
#define VPBntBit    12
// Other capabilities
#define LISTEN_BEFORE_LOAD          2000                // no less than 2 seconds
#define BOOTLOADER_UART             1                   // avrdude program UART
#define BAUDRATE                    115200              // avrdude baudrate
#define _CPU_NAME_                  "32MX320F128H"
#define VEND                        vendDigilent
#define PROD                        prodChipKITUno32
#define F_CPU                       80000000UL
#define F_PBUS                      F_CPU/2
#define FLASH_BYTES                 0x20000             // 128K
#define FLASH_PAGE_SIZE             4096
#define LoadFlashWaitStates()       (CHECON = 2)

void main(void)
{

    ES_Return_t ErrorType;
    BOARD_Init();
    //printf("Starting Intern State Machine \n");
    //printf("using the 2nd Generation Events & Services Framework\n");


    //Hardware Init
    Bot_Init();
    // Framework Init
    ErrorType = ES_Initialize();

    if (ErrorType == Success) {

        ErrorType = ES_Run();
    }

    //if we got to here, there was an error
    switch (ErrorType) {
    case FailedPointer:
        printf("Failed on NULL pointer");
        break;
    case FailedInit:
        printf("Failed Initialization");
        break;
    default:
        printf("Other Failure");
        break;
    }
    for (;;)
        ;

};
