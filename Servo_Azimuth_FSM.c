/*
 * File: RoachHSM.h
 * Author: Ryan A Rodriguez *
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
//#include "BotFrameworkEvents.h"
#include "RC_Servo.h"
#include <stdio.h>
#include "Stepper.h"
#include "Bot.h"
#include "Servo_Azimuth_FSM.h"
#include "AD.h"
#include "Presets_FSM.h"

// #include in any sub-state machines header files here

ES_Event MemEventAz;
static int E_Value = 0;
static int currentPosition = 0;
static int positionDifference = 0;
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

static Servo_Azimuth_State_t CurrentState = InitSState;
static uint8_t MyPriority;
/* Use the Generate_String_Array_From_Enum program on the desktop to generate the
   StateNames array, this will be used with the code trace function. */
static const char *StateNames[] = {"InitSState",
    "holdingAzimuth",
    "movingAzimuth",
    "movingAzimuthPreset"};

static unsigned int pulseTime = 0;


/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/

/**
 * @Function InitRoachHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunRoachHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
uint8_t InitServoAzimuthFSM(uint8_t Priority) {
    //printf("InitservoAzimuthHSM\n");
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = InitSState;
    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @Function PostRoachHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
uint8_t PostServoAzimuthFSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function QueryRoachSM(void)
 * @param none
 * @return Current state of the state machine
 * @brief This function is a wrapper to return the current state of the state
 *        machine. Return will match the ENUM above.
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
Servo_Azimuth_State_t QueryServoAzimuthFSM(void) {
    return (CurrentState);
}

/**
 * @Function RunRoachHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be responded.
 * @return Event - return event (type and param), in general should be ES_NO_EVENT
 * @brief This is the function that implements the actual state machine; in the
 *        roach case, it is a simple ping pong state machine that will form the
 *        basis of your more complicated exploration. This function will be called
 *        recursively to implement the correct order for a state transition to be:
 *        exit current state -> enter next state using the ES_EXIT and ES_ENTRY
 *        events.
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
ES_Event RunServoAzimuthFSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    Servo_Azimuth_State_t nextState;
    //printf("Entering RunservoAzimuthHSM() and current state is %d with Event: %d\n", CurrentState, ThisEvent.EventType);
    ES_Tattle(); // trace call stack
    static unsigned int eventParam = 0;
    static Position tempStruct;
    static unsigned int i = 0;
    static unsigned int j = 0;

    switch (CurrentState) {
        case InitSState:
            if (ThisEvent.EventType == ES_INIT) {
                //printf("Azimuth Init \n");
                nextState = holdingAzimuth;
                makeTransition = TRUE;
            }
            break;

        case holdingAzimuth:
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        SERVO_ENABLE_TRIS = 1;
                        //SERVO_ENABLEB = 0;
                        break;

                    case AZIMUTH_ELEVATION_CHANGE:
                        MemEventAz = ThisEvent;
                        nextState = azimuthBuffer;
                        makeTransition = TRUE;
                        break;

                    case PRESETCHANGE:
                        //Coming from presetHSM
                        //printf("Preset detected at Stepper\n");
                        eventParam = ThisEvent.EventParam;
                        nextState = movingAzimuthPreset;
                        makeTransition = TRUE;
                        break;

                    case ES_EXIT:
                        break;

                    default:
                        break;
                }
            }
            break;

        case azimuthBuffer:
            //ThisEvent = RunmovingYSubFSM(ThisEvent);
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        //printf("movingBuffer Enter:%d\n", memEventY.EventParam);
                        ES_Timer_InitTimer(SERVO_A_TIMER, 2);
                        break;


                    case AZIMUTH_ELEVATION_CHANGE:
                        MemEventAz = ThisEvent;
                        nextState = azimuthBuffer;
                        makeTransition = TRUE;
                        break;

                    case ES_TIMEOUT:
                        if (ThisEvent.EventParam = SERVO_A_TIMER) {
                            nextState = movingAzimuth;
                            makeTransition = TRUE;
                        }
                        break;

                    case ES_EXIT:
                        break;

                    default:
                        break;
                }
            }
            break;

        case movingAzimuth:
            //ThisEvent = RunmovingYSubHSM(ThisEvent);
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    SERVO_ENABLE_TRIS = 0;
                    SERVO_ENABLE = 1;
                    //SERVO_ENABLEB = 1;
                    ES_Timer_InitTimer(SERVO_A_TIMER, 1000);
                    //TODO: need to make sure that the servo linearization works for input range
                    pulseTime = (unsigned int) (MemEventAz.EventParam * .887 - 6.2);
                    RC_SetPulseTime(AZIMUTH_RC, MAXPULSE - pulseTime);
                    break;

                case AZIMUTH_ELEVATION_CHANGE:
                    nextState = azimuthBuffer;
                    makeTransition = TRUE;
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam = SERVO_A_TIMER) {
                        nextState = holdingAzimuth;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    break;

                default:
                    break;
            }
            break;

        case movingAzimuthPreset:
            //ThisEvent = RunmovingYSubHSM(ThisEvent);
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(SERVO_A_TIMER, 250);
                    //                    printf("Changing pulse \n");
                    RC_SetPulseTime(AZIMUTH_RC, MAXPULSE - pulseTime);
                    nextState = holdingAzimuth;
                    makeTransition = TRUE;
                    break;

                case AZIMUTH_ELEVATION_CHANGE:
                    SERVO_ENABLE = 1;
                    //SERVO_ENABLEB = 1;

                    pulseTime = 1 * ThisEvent.EventParam;
                    nextState = movingAzimuth;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    SERVO_ENABLE = 0;
                    //SERVO_ENABLEB = 0;

                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam = SERVO_A_TIMER) {
                        nextState = holdingAzimuth;
                        makeTransition = TRUE;
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    if (makeTransition == TRUE) {
        RunServoAzimuthFSM(EXIT_EVENT);
        CurrentState = nextState;
        RunServoAzimuthFSM(ENTRY_EVENT);
    }
    //printf("Leaving RunservoAzimuthHSM with CurrentState = %d\n", CurrentState);
    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/


