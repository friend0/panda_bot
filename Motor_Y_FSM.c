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
#include <stdio.h>
#include "Motor_Y_FSM.h"
#include "Presets_FSM.h"
#include "BotFrameworkEvents.h"

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
#define FORWARD  1
#define REVERSE  0
uint8_t yDirection = 0, lastYDirection = 0;
static int Y_Value = 0;
static int currentPosition = 0;
static int positionDifference = 0;
static int newPosition = 0;

unsigned int initialY = 0;
/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/

void setAccelPointY(unsigned int accelPoint);
void setDecelPointY(unsigned int decelPoint);


/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
static Motor_Y_State_t CurrentState = InitQState;
static Motor_Y_Status_t CurrentStatus = restingY;

static uint8_t MyPriority;
static ES_Event memEventY;
static unsigned int AccelPointY = 0, DecelPointY = 0;


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

unsigned int getAccelPointY(void) {
    return AccelPointY;
}

unsigned int getDecelPointY(void) {
    return DecelPointY;
}

uint8_t InitMotorYFSM(uint8_t Priority) {
    MyPriority = Priority;
    CurrentState = InitQState;
    CurrentStatus = restingY;

    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

uint8_t PostMotorYFSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

Motor_Y_State_t QueryMotorYFSM(void) {
    return (CurrentState);
}

Motor_Y_Status_t QueryMotorYStatus(void) {
    return (CurrentState);
}

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
                        CurrentStatus = restingY;
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
                        if (CurrentStatus == reversingY) {
                            nextState = deceleratingY;
                            makeTransition = TRUE;
                            goto END_ENTRY_MOVING_Y;
                        }
                        setStepsRate(MOTOR_Y, 45);
                        forwardY(abs(positionDifference));
                        CurrentStatus = forwardingY;
                    } else {
                        if (CurrentStatus == forwardingY) {
                            nextState = deceleratingY;
                            makeTransition = TRUE;
                            goto END_ENTRY_MOVING_Y;
                        }
                        setStepsRate(MOTOR_Y, 45);
                        reverseY(abs(positionDifference));
                        CurrentStatus = reversingY;
                    }
END_ENTRY_MOVING_Y:
                    break;

                case ALMOSTOUTOFSTEPS:
                    setStepsRate(MOTOR_Y, 5);
                    break;

                case OUTOFSTEPS:
                    Stepper_Halt(MOTOR_Y);
                    ES_Timer_InitTimer(MOTOR_Y_TIMER, 250);
                    break;

/*
                case Y_LIMIT:
                    Stepper_Halt_Hard(MOTOR_X);
                    nextState = waitingX;
                    makeTransition = TRUE;
                    break;
 */
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
                    ES_Timer_StopTimer(MOTOR_Y);
                    break;

                default:
                    nextState = waitingY;
                    makeTransition = TRUE;
                    break;
            }
            break;

        case deceleratingY:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    setStepsRate(MOTOR_X, 5);
                    ES_Timer_InitTimer(MOTOR_X_TIMER, 1000);
                    break;

                case XY_CHANGE:
                    memEventY = ThisEvent;
                    break;
                    /*Ï

                    case X_LIMIT:
                        Stepper_Halt_Hard(MOTOR_X);
                        nextState = haltHard;
                        makeTransition = TRUE;
                        break;

                     * * */

                case OUTOFSTEPS:
                    Stepper_Halt_Hard(MOTOR_X);
                    //nextState = haltHard;
                    //makeTransition = TRUE;
                    //ES_Timer_InitTimer(MOTOR_X_TIMER, 55);
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam = MOTOR_X_TIMER) {
                        Stepper_Halt(MOTOR_X);
                        nextState = haltHardY;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    break;

                default:
                    break;
            }
            break;


        case haltHardY:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    ES_Timer_InitTimer(MOTOR_Y_TIMER, 250);
                    break;

                case XY_CHANGE:
                    memEventY = ThisEvent;
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam = MOTOR_Y_TIMER) {
                        Stepper_Halt(MOTOR_Y);
                        nextState = movingY;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    setStepsRate(MOTOR_Y, 5);
                    CurrentStatus = restingY;
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
        CurrentState = nextState;
        RunMotorYFSM(ENTRY_EVENT);
    }
    //printf("Leaving RunMotorYFSM with CurrentState = %d\n", CurrentState);
    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                            *
 ******************************************************************************/

void setAccelPointY(unsigned int accelPoint){
    if((accelPoint >= 0) && (accelPoint <= YSTEPS)){
    AccelPointY = accelPoint;
    }
}

void setDecelPointY(unsigned int decelPoint){
    if((decelPoint >= 0) && (decelPoint <= YSTEPS)){
    AccelPointY = decelPoint;
    }
}

