/*
 * File: RoachFSM.h
 * Author: Ryan A Rodriguez
 *
 */

/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ES_TattleTale.h"
#include "Bot.h"
#include "BOARD.h"
//#include "BotFrameworkEvents.h"
#include <stdio.h>
#include "Motor_Y_FSM.h"
// #include in any sub-state machines header files here
#include "Presets_FSM.h"
#include "BotFrameworkEvents.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
static int Y_Value = 0;
static int currentPosition = 0;
static int positionDifference = 0;
static int newPosition = 0;

unsigned int initialY = 0;
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

static Motor_Y_State_t CurrentState = InitQState, lastState;
static uint8_t MyPriority;
static ES_Event memEventY;
uint8_t yDirection = 0, lastYDirection = 0;
#define FORWARD  1
#define REVERSE  0

/* Use the Generate_String_Array_From_Enum program on the desktop to generate the
   StateNames array, this will be used with the code trace function. */
static const char *StateNames[] = {"InitQState",
    "selfCalibrateY",
    "waitingToCalibrateY",
    "waitingY",
    "movingBufferY",
    "movingBufferY2",
    "movingY",
    "directionChange",
    "movingY_Preset"};

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
uint8_t InitMotorYFSM(uint8_t Priority) {
    //printf("InitMotorYFSM\n");
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = InitQState;
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
uint8_t PostMotorYFSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function QueryRoachSM(void)
 * @param none
 * @return Current state of the state machine
 * @brief This function is a wrapper to return the current state of the state
 *        machine. Return will match the ENUM above.
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
Motor_Y_State_t QueryMotorYFSM(void) {
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
ES_Event RunMotorYFSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    Motor_Y_State_t nextState;
    ES_Tattle(); // trace call stack
    static unsigned int eventParam = 0;
    static unsigned int i = 0;
    static unsigned int j = 0;

    switch (CurrentState) {
        case InitQState:
            if (ThisEvent.EventType == ES_INIT) {
                nextState = selfCalibrateY;
                makeTransition = TRUE;
            }
            break;

        case selfCalibrateY:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    break;

                case CALIBRATED:
                    if (ThisEvent.EventParam == MOTOR_X) {
                        Stepper_Init(MOTOR_Y, 77);
                        reverseY(4000);
                        ES_Timer_InitTimer(MOTOR_Y_TIMER, 5000);
                    }
                    break;

                case Y_LIMIT:
                    if (ThisEvent.EventParam == Y_MIN_MASK) {
                        initialY = getFilteredAD(Y_SLIDER);
                        newPosition = AD_SCALE_Y * initialY;
                        currentPosition = 0;
                        setStepsTaken(MOTOR_Y, 0);
                        positionDifference = currentPosition - newPosition;

                        if (positionDifference < 0) {
                            //forwardX(abs(positionDifference));
                        } else if (positionDifference > 0) {
                            1; //do nothing, already at zero
                        }
                        Stepper_Halt(MOTOR_Y);
                    }
                    break;
                    //case Y_LIMIT:
                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == MOTOR_Y_TIMER) {
                        initialY = getFilteredAD(Y_SLIDER);
                        //Stepper_Resume(MOTOR_Y);
                        newPosition = AD_SCALE_Y * initialY;
                        currentPosition = 0;
                        setStepsTaken(MOTOR_Y, 0);
                        positionDifference = currentPosition - newPosition;

                        if (positionDifference < 0) {
                            //forwardY(abs(positionDifference));
                        } else if (positionDifference > 0) {
                            1; //do nothing, already at zero
                        }
                        nextState = waitingY;
                        makeTransition = TRUE;

                    }
                    break;

                case ES_EXIT:
                    Stepper_Halt(MOTOR_Y);
                    ES_Timer_StopTimer(MOTOR_Y_TIMER);
                    break;

                default:
                    break;
            }
            break;

        case waitingY:
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:

                        break;

                    case XY_CHANGE:
                        nextState = movingBufferY;
                        makeTransition = TRUE;
                        memEventY = ThisEvent;
                        break;

                    case PRESETCHANGE:
                        //Coming from presetFSM
                        //nextState = movingY_Preset;
                        //makeTransition = TRUE;
                        break;

                    case ES_EXIT:
                        Stepper_Resume(MOTOR_Y);
                        setStepsRate(MOTOR_Y, 77);
                        //ES_Timer_StopTimer(MOTOR_Y_TIMER);
                        break;

                    default:
                        break;
                }
            }
            break;

        case movingBufferY:
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        ES_Timer_InitTimer(MOTOR_Y_TIMER, 200);
                        break;

                    case XY_CHANGE:
                        nextState = movingBufferY;
                        makeTransition = TRUE;
                        memEventY = ThisEvent;
                        break;

                    case ES_TIMEOUT:
                        if (ThisEvent.EventParam = MOTOR_Y_TIMER) {
                            nextState = movingY;
                            makeTransition = TRUE;
                        }
                        break;

                    case ES_EXIT:
                        setStepsRate(MOTOR_Y, 77);
                        break;

                    default:
                        break;
                }
            }
            break;

        case movingY:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    Stepper_Init(MOTOR_Y, 77);
                    newPosition = AD_SCALE_Y * memEventY.EventParam;
                    currentPosition = getStepsTaken(MOTOR_Y);
                    positionDifference = currentPosition - newPosition;
                    if (positionDifference < 0) {
                        yDirection = FORWARD;
                        forwardY(abs(positionDifference));
                    } else {
                        yDirection = REVERSE;
                        reverseY(abs(positionDifference));
                    }

                    break;

                case ALMOSTOUTOFSTEPS:
                    setStepsRate(MOTOR_Y, 15);
                    break;

                case OUTOFSTEPS:
                    Stepper_Halt(MOTOR_Y);
                    ES_Timer_InitTimer(MOTOR_Y_TIMER, 50);
                    setStepsRate(MOTOR_Y, 77);

                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == MOTOR_Y_TIMER) {
                        Stepper_Halt(MOTOR_Y);
                        nextState = waitingY;
                        makeTransition = TRUE;
                    }
                    break;

                case XY_CHANGE:
                    nextState = movingBufferY; 
                    makeTransition = TRUE;
                    memEventY = ThisEvent;
                    break;

                case ES_EXIT:
                    lastYDirection = yDirection;
                    setStepsRate(MOTOR_Y, 77);
                    ES_Timer_StopTimer(MOTOR_Y);
                    break;

                default:
                    nextState = waitingY;
                    makeTransition = TRUE;
                    break;
            }
            break;

        case movingBufferY2:
            //ThisEvent = RunmovingYSubFSM(ThisEvent);
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        //printf("movingBuffer Enter:%d\n", memEventY.EventParam);
                        ES_Timer_InitTimer(MOTOR_Y_TIMER, 200);
                        break;


                    case XY_CHANGE:
                        //printf("Y_CHANGE\n");

                        //determine if a change of direction is about to occur
                        newPosition = AD_SCALE_Y * ThisEvent.EventParam;
                        currentPosition = getStepsTaken(MOTOR_Y);
                        positionDifference = currentPosition - newPosition;
                        if (positionDifference < 0) {
                            yDirection = FORWARD;
                        } else {
                            yDirection = REVERSE;
                        }
                        //if direction change, start slowing down

                        memEventY = ThisEvent;
                        break;

                    case ES_TIMEOUT:
                        if (ThisEvent.EventParam = MOTOR_Y_TIMER) {
                            printf("yDirection:%d, lastYDirection:%d\n", yDirection, lastYDirection);
                            if (yDirection != lastYDirection) {
                                printf("directionChange!\n");
                                //setStepsRate(MOTOR_Y, 15);
                                //make an event instead!
                                //ES_Timer_InitTimer(MOTOR_Y, 150);
                                //while (!(getStepsRate(MOTOR_Y) < 20));
                                nextState = changingDirection;
                                makeTransition = TRUE;
                            } else {
                                nextState = movingY;
                                makeTransition = TRUE;
                            }
                        }
                        break;

                    case ES_EXIT:
                        //Stepper_Init(MOTOR_Y,500);
                        break;

                    default:
                        break;
                }
            }
            break;

        case changingDirection:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //printf("movingBuffer Enter:%d\n", memEventY.EventParam);
                    //ES_Timer_InitTimer(MOTOR_Y_TIMER, 50);
                    Stepper_ChangeStepRate(MOTOR_Y, 15);
                    break;

                case SPEEDMATCH:
                    printf("speedmatch!\n");
                    nextState = movingY;
                    makeTransition = TRUE;
                    break;

                case XY_CHANGE:
                    //printf("Y_CHANGE\n");
                    nextState = movingBufferY2;
                    makeTransition = TRUE;
                    memEventY = ThisEvent;
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam = MOTOR_Y_TIMER) {
                        nextState = movingY;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    //Stepper_Init(MOTOR_Y,500);
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }

    if (makeTransition == TRUE) {
        RunMotorYFSM(EXIT_EVENT);
        lastState = CurrentState;
        CurrentState = nextState;
        RunMotorYFSM(ENTRY_EVENT);
    }
    //printf("Leaving RunMotorYFSM with CurrentState = %d\n", CurrentState);
    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/


