/*
 * File: MotorXFSM.h
 * Author: J. Edward Carryer
 * Modified: Gabriel H Elkaim
 * Modified: Ryan Rodriguez
 */

#ifndef Motor_Y_FSM_H  // <- This should be changed to your own guard on both
#define Motor_Y_FSM_H  //    of these lines


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT

/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
#define AD_DIFF_Y 1023
#define YSTEPS 5000
#define AD_SCALE_Y YSTEPS/(AD_DIFF_Y)
static unsigned int yScaleFactor = 1;

#define forwardY(x) Stepper_SetSteps(MOTOR_Y, FORWARD, x)
#define reverseY(x) Stepper_SetSteps(MOTOR_Y, REVERSE, x)

/*******************************************************************************
 * PUBLIC TYPEDEFS                                                             *
 ******************************************************************************/

// typedefs for the states, which are used for the internal definition and also for
// the return of the query function. Be careful that all state names must be unique
// if they are exposed in the header file.

typedef enum {
    InitQState, selfCalibrateY, waitingToCalibrateY, waitingY, movingBufferY, movingY, movingY_Preset, deceleratingY, haltHardY
} Motor_Y_State_t;  // <- Change this name along with your state names

typedef enum {
    reversingY, restingY, forwardingY
} Motor_Y_Status_t;

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/
unsigned int getAccelPointY(void);

unsigned int getDecelPointY(void);

uint8_t InitMotorYFSM(uint8_t Priority);

uint8_t PostMotorYFSM(ES_Event ThisEvent);

Motor_Y_State_t QueryMotorYFSM(void);

Motor_Y_Status_t QueryMotorYStatus(void);

ES_Event RunMotorYFSM(ES_Event ThisEvent);

#endif /* FSM_MotorY_H */

