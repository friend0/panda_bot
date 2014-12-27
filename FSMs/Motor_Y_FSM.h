/**
* @file Motor_Y_FSM.h
* @author Ryan Rodriguez
* @date 12/26/14
* @brief Y axis FSM
*
* This file runs the state machine for the Y axis stepper motor.
* Path planning and accel/decel are handled here
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
/**
 * @brief The states of the MOTORY FSM
 */
typedef enum {
    InitQState, selfCalibrateY, waitingToCalibrateY, waitingY, movingBufferY, movingY, movingY_Preset, deceleratingY, haltHardY
} Motor_Y_State_t;  // <- Change this name along with your state names
/**
 * @brief The status of the motor's trajectory
 */
typedef enum {
    reversingY, restingY, forwardingY
} Motor_Y_Status_t;

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/
/**
 * public function to retrieve acceleration point in steps from '0'
 * @return  return the number the acceleration point in steps from '0'
 */
unsigned int getAccelPointY(void);
/**
* public function to retrieve deceleration point in steps from '0'
* @return  return the number the acceleration point in steps from '0'
*/
unsigned int getDecelPointY(void);
/**
 * FSM ESFW init
 * @param  Priority internal priority
 * @return          T/F
 */
uint8_t InitMotorYFSM(uint8_t Priority);
/**
 * Post events to this FSMs queue
 * @param  ThisEvent [description]
 * @return           [description]
 */
uint8_t PostMotorYFSM(ES_Event ThisEvent);

/**
 * FSM state
 * @return  return the current state
 */
Motor_Y_State_t QueryMotorYFSM(void);
/**
 * Motor status
 * @return  return the current trajectory of the motor
 */
Motor_Y_Status_t QueryMotorYStatus(void);
/**
 * Run FX for the state machine
 */
ES_Event RunMotorYFSM(ES_Event ThisEvent);

#endif /* FSM_MotorY_H */
