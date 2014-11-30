/*
 * File: RoachFSM.h
 * Author: Gabriel H Elkaim
 *
 * Simple flat state machine framework for the Roach project for CMPE-118 to get
 * you started on the project. The FSM simply ping pongs between two states on a
 * timer.
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ES_TattleTale.h"
#include "BOARD.h"
#include "BotFrameworkEvents.h"
//#include "BotFSM.h"
#include <stdio.h>
#include "Bot.h"
#include "Motor_X_FSM.h"
#include "Motor_Y_FSM.h"
#include "Presets_FSM.h"
#include "AccelX_SubFSM.h"
// #include in any sub-state machines header files here


/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/



/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */


/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static Motor_X_Accel_State_t CurrentState = InitAXState;

static uint8_t MyPriority;

/* Use the Generate_String_Array_From_Enum program on the desktop to generate the
   StateNames array, this will be used with the code trace function. */
static const char *StateNames[] = {"InitAXState",
    "AcceleratingX"};


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitRoachFSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunRoachFSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
uint8_t InitMotorX_AccelFSM(uint8_t Priority) {
    //printf("InitMotorXFSM\n");
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = InitAXState;

    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostRoachFSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
uint8_t PostMotorX_AccelFSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function QueryRoachSM(void)
 * @param none
 * @return Current state of the state machine
 * @brief This function is a wrapper to return the current state of the state
 *        machine. Return will match the ENUM above.
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
Motor_X_Accel_State_t QueryMotorX_AccelFSM(void) {
    return (CurrentState);
}

/**
 * @Function RunRoachFSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This is the function that implements the actual state machine; in the
 *        roach case, it is a simple ping pong state machine that will form the
 *        basis of your more complicated exploration. This function will be called
 *        recursively to implement the correct order for a state transition to be:
 *        exit current state -> enter next state using the ES_EXIT and ES_ENTRY
 *        events.
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
ES_Event RunMotorX_AccelFSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    Motor_X_Accel_State_t nextState;

    switch (CurrentState) {
        case InitAXState:
            if (ThisEvent.EventType == ES_INIT) {
                //Just initializing the service, do nothing
            } else {
                nextState = AcceleratingX;
                makeTransition = TRUE;
            }
            break;


        case AcceleratingX:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //Start decceleration
                    setStepsRate(MOTOR_X, 15);
                    ES_Timer_InitTimer(MOTOR_X_TIMER, 1000);
                    //TODO: need to make an event for step rate matching. For now, I'll use a timer
                    break;

                case ES_TIMEOUT:
                    //TODO: sort out hard stop once and for all!
                    Stepper_Halt_Hard(MOTOR_X);
                    nextState = hardStop;
                    makeTransition = TRUE;
                    break;

                case NEARLIMIT:
                    //set a flag if near limit so that ALMOSTSTEPS has a limiting case for deccel
                    break;

                    /*TODO: need to make an event for when we're very near the target. If we've got space, do some overshoot
                      If we're near target, we should already be decellerating. Perhaps figure a way to let this happen, then head to next destination. This will need to be handled in top state?
                case NEARTARGET:

                    break;
                     */

                case ALMOSTOUTOFSTEPS:
                    //If the direction change comes very near desired positionA
                    //Need to see if we've got enough room to make decelleration maneuver
                    break;


                case ES_EXIT:
                    break;

                default:
                    break;
            }
            break;
        case hardStop:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //Start decceleration
                    setStepsRate(MOTOR_X, 15);
                    ES_Timer_InitTimer(MOTOR_X_TIMER, 1000);
                    //TODO: need to make an event for step rate matching. For now, I'll use a timer

                    break;

                case ES_TIMEOUT:
                    //TODO: sort out hard stop once and for all!
                    Stepper_Halt_Hard(MOTOR_X);
                    nextState = hardStop;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }

    if (makeTransition == TRUE) {
        RunMotorX_AccelFSM(EXIT_EVENT);
        CurrentState = nextState;
        RunMotorX_AccelFSM(ENTRY_EVENT);
    }
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/



