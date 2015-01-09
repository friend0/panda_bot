/*
 * File:   Stepper.h
 * Author: Elkaim
 *
 * Software module to drive a stepper motor through a normal H-bridge in full-step drive
 * mode. The module uses TIMER3 and is capable of generated 1/2 to 20,000 steps per second.
 * The nominal port used is PORTZ and can be changed by changing the appropriate #defines
 * below.
 *
 * NOTE: Module uses TIMER3 for its interrupts. When using this module to directly drive
 *       the DRV8811 stepper board, it will be stepping at 1/2 the rate specified due to
 *       to toggling the pin on every entry to the ISR (board steps on rising edge).
 *
 * STEPPER_TEST (in the .c file) conditionally compiles the test harness for the code.
 * Make sure it is commented out for module useage.
 *
 * Created on January 2, 2012, 9:36 PM
 */

#ifndef Stepper_H
#define Stepper_H

#include "IO_Ports.h"


/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/

#ifndef SUCCESS
#define SUCCESS 1
#define ERROR -1
#endif

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#ifndef FORWARD
#define FORWARD 1
#define REVERSE 0
#endif

#define NUM_STEPPER_MOTORS 2
#define MOTOR_X 0
#define MOTOR_Y 1

#define ACCEL_RATE 2

static unsigned int TOTAL_X_STEPS = 0;
static unsigned int TOTAL_Y_STEPS = 0;

typedef enum {
    off, inited, stepping, halted, waiting
} stepperState_t;

////Motor x,  pin 30, 4, 29
//#define TRIS_STEPPER_BOARD0_ENABLE TRISEbits.TRISE4  // portz3
//#define TRIS_STEPPER_BOARD0_DIRECTION TRISFbits.TRISF1 // portz4
//#define TRIS_STEPPER_BOARD0_STEP TRISEbits.TRISE3 // portz5
//
//#define STEPPER_BOARD0_ENABLE PORTEbits.RE4
//#define STEPPER_BOARD0_DIRECTION PORTFbits.RF1
//#define STEPPER_BOARD0_STEP PORTEbits.RE3
//
////Motor Y, pin 3, 28, 2
//#define TRIS_STEPPER_BOARD1_ENABLE TRISDbits.TRISD0 // portz6
//#define TRIS_STEPPER_BOARD1_DIRECTION TRISEbits.TRISE2 // portz7
//#define TRIS_STEPPER_BOARD1_STEP TRISDbits.TRISD8 // portz8
//
//#define STEPPER_BOARD1_ENABLE PORTDbits.RD0
//#define STEPPER_BOARD1_DIRECTION PORTEbits.RE2
//#define STEPPER_BOARD1_STEP PORTDbits.RD8

//Motor Y
//step pin 4, z4
//dir pin 30, z3
//en y pin 29, z5
#define UART_BRD

#ifdef ANALOG_BRD
#define TRIS_STEPPER_BOARD1_STEP PORTZ04_TRIS
#define TRIS_STEPPER_BOARD1_DIRECTION PORTZ03_TRIS
#define TRIS_STEPPER_BOARD1_ENABLE PORTZ05_TRIS

#define STEPPER_BOARD1_STEP PORTZ04_BIT
#define STEPPER_BOARD1_DIRECTION PORTZ03_BIT
#define STEPPER_BOARD1_ENABLE PORTZ05_BIT


//step pin28, z7
//dir, pin 3, z6
//en x pin2, z8

//Motor X

#define TRIS_STEPPER_BOARD0_STEP PORTZ07_TRIS // pin28
#define TRIS_STEPPER_BOARD0_DIRECTION PORTZ06_TRIS // pin3
#define TRIS_STEPPER_BOARD0_ENABLE PORTZ08_TRIS // pin2

#define STEPPER_BOARD0_STEP PORTZ07_BIT
#define STEPPER_BOARD0_DIRECTION PORTZ06_BIT
#define STEPPER_BOARD0_ENABLE PORTZ08_BIT
#endif

#ifdef UART_BRD

//TODO: Need to make sure that the stepper halt Hard works with the Lat...
//consider changing them all to LAT
//Motor Y
#define TRIS_STEPPER_BOARD0_STEP PORTY09_TRIS   //pin32
#define TRIS_STEPPER_BOARD0_DIRECTION PORTY10_TRIS  //pin6
#define TRIS_STEPPER_BOARD0_ENABLE PORTY12_TRIS     //pin5

#define STEPPER_BOARD0_STEP PORTY09_BIT
#define STEPPER_BOARD0_DIRECTION PORTY10_BIT

#define STEPPER_BOARD0_ENABLE PORTY12_BIT
//#define STEPPER_BOARD0_ENABLE PORTY12_LAT

//Motor X
#define TRIS_STEPPER_BOARD1_STEP PORTZ04_TRIS // pin4
#define TRIS_STEPPER_BOARD1_DIRECTION PORTY11_TRIS // pin31
#define TRIS_STEPPER_BOARD1_ENABLE PORTZ03_TRIS // pin30

#define STEPPER_BOARD1_STEP PORTZ04_BIT
#define STEPPER_BOARD1_DIRECTION PORTY11_BIT

//#define STEPPER_BOARD1_ENABLE PORTZ03_BIT
#define STEPPER_BOARD1_ENABLE PORTZ03_LAT
#endif


#define ShutDownDrive0() STEPPER_BOARD0_ENABLE = 1
#define ShutDownDrive1() STEPPER_BOARD1_ENABLE = 1
#define ShutDownDrives() STEPPER_BOARD0_ENABLE = 1; STEPPER_BOARD1_ENABLE = 1

#define TurnOnDrive0() STEPPER_BOARD0_ENABLE = 0
#define TurnOnDrive1() STEPPER_BOARD1_ENABLE = 0
#define TurnOnDrives() STEPPER_BOARD0_ENABLE = 0; STEPPER_BOARD1_ENABLE = 0


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/
unsigned int setStepsRate(unsigned short int motorNumber, unsigned int rate);

unsigned int setCurrentStepsRate(unsigned short int motorNumber, unsigned int rate);

unsigned int getStepsTaken(unsigned short int motorNumber);

unsigned int getStepsRate(unsigned short int motorNumber);

unsigned int getStepsRateFinal(unsigned short int motorNumber);

char setStepsTaken(unsigned short int motorNumber, unsigned int steps);

char acceleration(unsigned int motorNumber);

void Stepper_AddStepCounts(unsigned short int motorNumber, short int steps);

char Stepper_GetState(unsigned short int motorNumber);

char Steppers_Init(unsigned short int rate);

char Stepper_ChangeStepRate(unsigned short int motorNumber, unsigned short int rate);

char Stepper_SetSteps(unsigned short int motorNumber, char direction, unsigned int steps);

char Stepper_IncrementSteps(unsigned short int motorNumber, char direction, unsigned int steps);

char Stepper_GetDirection(unsigned short int motorNumber);

unsigned int Stepper_GetRemainingCount(unsigned short int motorNumber);

char Stepper_Halt(unsigned short int motorNumber);

char Stepper_Halt_Hard(unsigned short int motorNumber);

char Drive_Halt(void);

char Stepper_Resume(unsigned short int motorNumber);

#endif
