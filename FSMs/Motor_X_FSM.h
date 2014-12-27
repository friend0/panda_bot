/**
* @file Motor_X_FSM.h
* @author Ryan Rodriguez
* @date 12/26/14
* @brief X axis FSM
*
* This file runs the state machine for the X axis stepper motor.
* Path planning and accel/decel are handled here
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
 /**
 * @brief The states of the MOTORX FSM
 */
typedef enum {
    InitRState, selfCalibrateX, waitingToCalibrateX, waitingX, movingBufferX, movingX, movingX_Preset, deceleratingX, haltHardX
} Motor_X_State_t;  // <- Change this name along with your state names
/**
* @brief The status of the motor's trajectory
*/
typedef enum {
    reversingX, restingX, forwardingX
} Motor_X_Status_t;

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/
 /**
 * public function to retrieve acceleration point in steps from '0'
 * @return  return the number the acceleration point in steps from '0'
 */
unsigned int getAccelPointX(void);
/**
* public function to retrieve deceleration point in steps from '0'
* @return  return the number the acceleration point in steps from '0'
*/
unsigned int getDecelPointX(void);
/**
* FSM ESFW init
* @param  Priority internal priority
* @return          T/F
*/
uint8_t InitMotorXFSM(uint8_t Priority);
/**
* Post events to this FSMs queue
* @param  ThisEvent [description]
* @return           [description]
*/
uint8_t PostMotorXFSM(ES_Event ThisEvent);
/**
* FSM state
* @return  return the current state
*/
Motor_X_State_t QueryMotorXFSM(void);
/**
* Motor status
* @return  return the current trajectory of the motor
*/
Motor_X_Status_t QueryMotorXStatus(void);
/**
* Run FX for the state machine
*/
ES_Event RunMotorXFSM(ES_Event ThisEvent);

#endif /* FSM_MotorX_H */
