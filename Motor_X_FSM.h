/*
 * File: MotorXFSM.h
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 * Modified: Ryan Rodriguez
 */

#ifndef FSM_MotorX_H  // <- This should be changed to your own guard on both
#define FSM_MotorX_H  //    of these lines


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "ES_Configure.h"
#include "Stepper.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
#define AD_DIFF_X 1023
#define XSTEPS 5000
#define AD_SCALE_X XSTEPS/(AD_DIFF_X)
static unsigned int xScaleFactor = 1; //temp, reassigned upon calibration

#define forwardX(x) Stepper_SetSteps(MOTOR_X, FORWARD, x)
#define reverseX(x) Stepper_SetSteps(MOTOR_X, REVERSE, x)

/*******************************************************************************
 * PUBLIC TYPEDEFS                                                             *
 ******************************************************************************/

typedef enum {
    InitRState, selfCalibrateX, waitingToCalibrateX, waitingX, movingBufferX, movingX, movingX_Preset, deceleratingX, haltHardX
} Motor_X_State_t;  // <- Change this name along with your state names

typedef enum {
    reversingX, restingX, forwardingX
} Motor_X_Status_t;

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/
unsigned int getAccelPointX(void);

unsigned int getDecelPointX(void);

uint8_t InitMotorXFSM(uint8_t Priority);

uint8_t PostMotorXFSM(ES_Event ThisEvent);

Motor_X_State_t QueryMotorXFSM(void);

Motor_X_Status_t QueryMotorXStatus(void);

ES_Event RunMotorXFSM(ES_Event ThisEvent);

#endif /* FSM_MotorX_H */

