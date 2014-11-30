/*
 * File: RoachHSM.h
 * Author: Gabriel H Elkaim
 *
 * Simple flat state machine framework for the Roach project for CMPE-118 to get
 * you started on the project. The FSM simply ping pongs between two states on a
 * timer.
 */

#include "dee_emulation_pic32.h"


/*******************************************************************************
 * MODULE #INCLUDE                                                             *
 ******************************************************************************/

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "ES_TattleTale.h"
#include "BOARD.h"
#include "BotFrameworkEvents.h"
//#include "BotFSM.h"
#include "RC_Servo.h"
#include <stdio.h>
#include "Bot.h"
#include "Presets_FSM.h"
#include "Motor_X_FSM.h"
#include "Motor_Y_FSM.h"
#include "Servo_Azimuth_FSM.h"


//static unsigned int XY_LIMITS[4] = {0};
static char bothXLimits = FALSE, bothYLimits = FALSE;

//Xmin, Xmax, Ymin, Ymax


// #include in any sub-state machines header files here

#pragma config FPLLMUL = MUL_18, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF

#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_2

static unsigned int X_Value_Current = 0;
static unsigned int Y_Value_Current = 0;
static unsigned int A_Value_Current = 0;

static unsigned int X_Value_Preset = 0;
static unsigned int Y_Value_Preset = 0;
static unsigned int A_Value_Preset = 0;

/*******************************************************************************
 * MODULE #DEFINES                                                             *
 ******************************************************************************/
uint8_t getCurrentMatchState(char whichState, unsigned int whichPreset) {
    if (whichState == XSTATE) {
        return currentXState[whichPreset];
    } else if (whichState == YSTATE) {
        return currentYState[whichPreset];
    } else if (whichState == ASTATE) {
        return currentAState[whichPreset];
    } else return ERROR;
}

/*******************************************************************************
 * PRIVATE FUNCTION PROTOTYPES                                                 *
 ******************************************************************************/
/* Prototypes for private functions for this machine. They should be functions
   relevant to the behavior of this state machine */

#define DriveX(x) xSpeed(x)
#define DriveY(x) ySpeed(x)
#define DriveA(x) aSpeed(x)

/*******************************************************************************
 * PRIVATE MODULE VARIABLES                                                            *
 ******************************************************************************/
/* You will need MyPriority and the state variable; you may need others as well.
 * The type of state variable should match that of enum in header file. */

static Presets_State_t CurrentState = InitUState;
static uint8_t MyPriority;
/* Use the Generate_String_Array_From_Enum program on the desktop to generate the
   StateNames array, this will be used with the code trace function. */
static const char *StateNames[] = {"InitUState",
    "initCenter",
    "calibratePotsMin",
    "calibratePotsMax",
    "calibrateMotors",
    "startupSequence",
    "noPresets",
    "programming",
    "movingFaders"};

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                            *
 ******************************************************************************/


Position getPresetStruct(unsigned int presetNumber) {
    switch (presetNumber) {
        case 1:
            return positionArray[0];
            break;

        case 2:
            return positionArray[1];
            break;

        case 3:
            return positionArray[2];
            break;

        case 4:
            return positionArray[3];
            break;

        case 5:
            return positionArray[4];
            break;


        default:
            //error
            break;
    }
}

/**
 * @Function InitRoachHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunRoachHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
uint8_t InitPresetsFSM(uint8_t Priority) {
    //printf("InitpresetsHSM\n");
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = InitUState;
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
uint8_t PostPresetsFSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

/**
 * @Function QueryRoachSM(void)
 * @param none
 * @return Current state of the state machine
 * @brief This function is a wrapper to return the current state of the state
 *        machine. Return will match the ENUM above.
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
Presets_State_t QueryPresetsFSM(void) {
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
ES_Event RunPresetsFSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE;
    Presets_State_t nextState;
    //printf("Entering RunpresetsHSM() and current state is %d with Event: %d\n", CurrentState, ThisEvent.EventType);
    ES_Tattle(); // trace call stack

    static unsigned int eventParam = 0;
    static Position tempStruct;
    static unsigned int i = 0;
    static unsigned int j = 0;

    switch (CurrentState) {
        case InitUState:
            if (ThisEvent.EventType == ES_INIT) {
                //                for (i = 0; i < 4; i++) {
                //                    for (i = 0; j < 4; j++) {
                //                        if (DataEERead(&value, DEEaddr) != 0) {
                //                            printf("Error:%d\n", DataEERead(&value, DEEaddr));
                //                        }
                //                        positionArray[i].positionArr[j] = value;
                //                        DEEaddr++;
                //                    }
                //                }

                //                    DEEdata = 1;
                //                    eventParam = 0;
                //                    for (i = 0; i < 4; i++) {
                //                        for (j = 0; j < 4; j++) {
                //                            if (DataEEWrite(DEEdata, DEEaddr) != 0) {
                //                                printf("error\n");
                //                            }
                //                            DEEaddr++;
                //                        }
                //                    }
                //                    printf("It is written\n");
                DEEaddr = 0;
                DEEdata = 0;


                //TODO: should probably have it calibrate upon every startup...
                //Change branch upon read eeprom structure
                char INITIAL_START_FLAG = TRUE;
                //load all data in emulated eeprom to working memory
                //making changes here!! (< -> <=)
                for (i = 0; i < DATA_ARRAY_LENGTH; i++){
                    for (j = 0; j < 4; j++) {
                        //                        printf("ErrorB:%d\t valAddr:%p\n", DataEERead(&value, DEEaddr), &value);
                        if (DataEERead(&value, DEEaddr) != 0) {
                            //                            printf("ErrorB:%d\t valAddr:%p\n", DataEERead(&value, DEEaddr), &value);
                        }
                        //                        printf("Value:%d\n", value);

                        else{
                        positionArray[i].positionArr[j] = value;
                        DEEaddr++;
                        }
                    }
                }
                nextState = noPresets;
                makeTransition = TRUE;
                //load xy limits if not first bootup or total reset

            }
            break;


        case calibratePotsMax:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //wait for both XY pots to hit a minimum
                    break;
                    //need to write checker to do this
                case XY_POT_MAX:
                    positionArray[DATA_ARRAY_LENGTH].positionArr[xMax] = getFilteredAD(X_SLIDER);
                    positionArray[DATA_ARRAY_LENGTH].positionArr[yMax] = getFilteredAD(Y_SLIDER);

                    break;



               default:
                    break;
            }
            break;

        case calibratePotsMin:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //wait for both XY pots to hit a minimum
                    break;

                case XY_POT_ZERO:
                    positionArray[DATA_ARRAY_LENGTH].positionArr[xMin] = getFilteredAD(X_SLIDER);
                    positionArray[DATA_ARRAY_LENGTH].positionArr[yMin] = getFilteredAD(Y_SLIDER);

                    nextState = calibrateMotors;
                    makeTransition = TRUE;
                    break;



               default:
                    break;
            }
            break;


        case calibrateMotors:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //zero x and y motors
                    ThisEvent.EventType = CALIBRATE;
                    ThisEvent.EventParam = MIN;
                    //Post the PRESETCHANGE EVENTS to actuators
                    PostMotorXFSM(ThisEvent);
                    ThisEvent.EventType = CALIBRATE;
                    ThisEvent.EventParam = MIN;
                    PostMotorYFSM(ThisEvent);

                    break;

                case X_LIMIT:
                    if(ThisEvent.EventParam = MAX){

                        bothXLimits = TRUE;
                        if (bothXLimits && bothYLimits){
                            nextState = initCenter;
                            //potentially should do this:
                            //nextState = noPresets;
                            makeTransition = TRUE;

                            ThisEvent.EventType = CALIBRATED;
                            PostMotorXFSM(ThisEvent);
                            PostMotorYFSM(ThisEvent);
                            }
                    }
                    break;

                case Y_LIMIT:
                    if(ThisEvent.EventParam = MAX){

                        bothYLimits = TRUE;
                        if (bothXLimits && bothYLimits){
                            nextState = initCenter;
                            //potentially should do this:
                            //nextState = noPresets;
                            makeTransition = TRUE;

                            ThisEvent.EventType = CALIBRATED;
                            PostMotorXFSM(ThisEvent);
                            PostMotorYFSM(ThisEvent);
                        }
                    }
                    break;

               default:
                    break;
            }
            break;



        case initCenter:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    RC_SetPulseTime(AZIMUTH_RC, SERVOCENTER);
                    ES_Timer_InitTimer(PRESET_TIMER, 2000);
                    break;

                case ES_TIMEOUT:
                    if (ThisEvent.EventParam == PRESET_TIMER) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                    }
                    break;
                default:
                    break;
            }
            break;

        case noPresets:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //                    printf("Preset HSM Waiting\n");
                    DEEaddr = 0;
                    DEEdata = 0;

                    //This is just for debugging
                    for (j = 1; j <= DATA_ARRAY_LENGTH; j++) {
                        Position temp = getPresetStruct(j);
                        for (i = 0; i < 4; i++) {
                            printf("PRESET:%d\tPOSITION%d:\t%d\n", j, i, temp.positionArr[i]);
                        }
                    }
                    break;

                case PRESETCHANGE:
                    eventParam = ThisEvent.EventParam;
                    //Post the PRESETCHANGE EVENTS to actuators
                    PostMotorXFSM(ThisEvent);
                    PostMotorYFSM(ThisEvent);
                    PostServoAzimuthFSM(ThisEvent);

                    nextState = movingFaders;
                    makeTransition = TRUE;
                    break;

                case LONG_PRESETCHANGE:
                    //                    printf("There was a programing event");
                    eventParam = ThisEvent.EventParam;
                    nextState = programming;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    DEEaddr = 0;
                    DEEdata = 0;
                    break;

                default:
                    break;
            }
            break;

        case programming:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    //tempStruct.positionArr[1] = ReadXSlider();
                    //CHANGE THIS!!!!!! pos 1 should be x slider. Like this for testing only!!
                    tempStruct.positionArr[X_PRESET_POS] = getFilteredAD(AZIMUTH_POT);
                    tempStruct.positionArr[Y_PRESET_POS] = getFilteredAD(Y_SLIDER);
                    tempStruct.positionArr[A_PRESET_POS] = getFilteredAD(AZIMUTH_POT);
                    //load the proper position of the array
                    //                    printf("Switch Event param:%d\n", eventParam);
                    switch (eventParam) {
                        case 1:
                            tempStruct.positionArr[0] = 1;
                            for (i = 0; i < 4; i++) {
                                positionArray[0].positionArr[i] = tempStruct.positionArr[i];
                                printf("loadVal:%d\n", positionArray[0].positionArr[i]);
                            }
                            break;
                        case 2:
                            tempStruct.positionArr[0] = 2;
                            for (i = 0; i < 4; i++) {
                                positionArray[1].positionArr[i] = tempStruct.positionArr[i];
                                printf("loadVal2:%d\n", positionArray[1].positionArr[i]);

                            }
                            break;
                        case 3:
                            tempStruct.positionArr[0] = 3;
                            for (i = 0; i < 4; i++) {
                                positionArray[2].positionArr[i] = tempStruct.positionArr[i];
                            }
                            break;
                        case 4:
                            tempStruct.positionArr[0] = 4;
                            for (i = 0; i < 4; i++) {
                                positionArray[3].positionArr[i] = tempStruct.positionArr[i];
                            }
                            break;
                        case 5:
                            tempStruct.positionArr[0] = 5;
                            for (i = 0; i < 4; i++) {
                                positionArray[4].positionArr[i] = tempStruct.positionArr[i];
                            }
                            break;
                        case 6:
                            tempStruct.positionArr[0] = 6;
                            for (i = 0; i < 4; i++) {
                                positionArray[5].positionArr[i] = tempStruct.positionArr[i];
                            }
                            break;
                        default:
                            break;
                    }
                    //load EEPROM now
                    DEEdata = 0;
                    DEEaddr = 0;
                    for (i = 0; i < DATA_ARRAY_LENGTH; i++) {
                        for (j = 0; j < 4; j++) {
                            if ((4 * i >= 4 * (eventParam - 1)) && ((4 * i + j) <= 4 * (eventParam - 1) + 4)) {
                                DEEdata = positionArray[eventParam - 1].positionArr[j];
                                if (DataEEWrite(DEEdata, DEEaddr) != 0) {
                                    printf("error\n");
                                }
                            } else {
                                DEEdata = positionArray[i].positionArr[j];
                                if (DataEEWrite(DEEdata, DEEaddr) != 0) {
                                    printf("error\n");
                                }
                            }
                            DEEaddr++;
                        }
                    }
                    //                    printf("EEPROM loaded\n");
                    nextState = noPresets;
                    makeTransition = TRUE;
                    break;

                case ES_EXIT:
                    DEEaddr = 0;
                    DEEdata = 0;
                    break;

                default:
                    break;
            }
            break;

        case movingFaders:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    tempStruct = getPresetStruct(eventParam);

                    X_Value_Preset = tempStruct.positionArr[1];
                    Y_Value_Preset = tempStruct.positionArr[2];
                    A_Value_Preset = tempStruct.positionArr[3];

                    X_Value_Current = getFilteredAD(X_SLIDER);
                    Y_Value_Current = getFilteredAD(Y_SLIDER);
                    A_Value_Current = getFilteredAD(AZIMUTH_POT);

                    if (getCurrentMatchState(XSTATE, eventParam)) xMatch = TRUE;
                    else xMatch = FALSE;
                    if (getCurrentMatchState(YSTATE, eventParam)) yMatch = TRUE;
                    else yMatch = FALSE;
                    if (getCurrentMatchState(ASTATE, eventParam)) aMatch = TRUE;
                    else aMatch = FALSE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                        goto final;
                    }
                    if ((X_Value_Current - X_Value_Preset) > 0)DriveX(3);
                    else if ((X_Value_Current - X_Value_Preset) < 0) DriveX(-3);

                    if ((Y_Value_Current - Y_Value_Preset) > 0)DriveY(3);
                    else if ((Y_Value_Current - Y_Value_Preset) < 0) DriveY(-3);

                    if ((A_Value_Current - A_Value_Preset) > 0)DriveA(3);
                    else if ((A_Value_Current - A_Value_Preset) < 0)DriveA(-3);

                    //Change this. Needs to respond to match events from here
                    nextState = noPresets;
                    makeTransition = TRUE;

final:
                    break;

                case PRESETMATCHX:
                    DriveX(0);
                    xMatch = TRUE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                    }
                    break;

                case PRESETMATCHY:
                    DriveY(0);
                    yMatch = TRUE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                    }
                    break;

                case PRESETMATCHA:
                    DriveA(0);
                    aMatch = TRUE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    xMatch = FALSE;
                    yMatch = FALSE;
                    aMatch = FALSE;
                    break;

                default:
                    break;
            }

        case movingFaders2:
            switch (ThisEvent.EventType) {
                case ES_ENTRY:
                    tempStruct = getPresetStruct(eventParam);

                    X_Value_Preset = tempStruct.positionArr[1];
                    Y_Value_Preset = tempStruct.positionArr[2];
                    A_Value_Preset = tempStruct.positionArr[3];

                    X_Value_Current = getFilteredAD(X_SLIDER);
                    Y_Value_Current = getFilteredAD(Y_SLIDER);
                    A_Value_Current = getFilteredAD(AZIMUTH_POT);

                    if (getCurrentMatchState(XSTATE, eventParam)) xMatch = TRUE;
                    else xMatch = FALSE;
                    if (getCurrentMatchState(YSTATE, eventParam)) yMatch = TRUE;
                    else yMatch = FALSE;
                    if (getCurrentMatchState(ASTATE, eventParam)) aMatch = TRUE;
                    else aMatch = FALSE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                        goto final2;
                    }
                    if ((X_Value_Current - X_Value_Preset) > 0)DriveX(1);
                    else if ((X_Value_Current - X_Value_Preset) < 0) DriveX(-1);

                    if ((Y_Value_Current - Y_Value_Preset) > 0)DriveY(1);
                    else if ((Y_Value_Current - Y_Value_Preset) < 0) DriveY(-1);

                    if ((A_Value_Current - A_Value_Preset) > 0)DriveA(1);
                    else if ((A_Value_Current - A_Value_Preset) < 0)DriveA(-1);

                    //Change this. Needs to respond to match events from here
                    nextState = noPresets;
                    makeTransition = TRUE;

final2:
                    break;

                case PRESETMATCHX:
                    DriveX(0);
                    xMatch = TRUE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                    }
                    break;

                case PRESETMATCHY:
                    DriveY(0);
                    yMatch = TRUE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                    }
                    break;

                case PRESETMATCHA:
                    DriveA(0);
                    aMatch = TRUE;
                    if (xMatch && yMatch && aMatch) {
                        nextState = noPresets;
                        makeTransition = TRUE;
                    }
                    break;

                case ES_EXIT:
                    xMatch = FALSE;
                    yMatch = FALSE;
                    aMatch = FALSE;
                    break;

                default:
                    break;
            }
            break;
        default:
            break;
    }



    if (makeTransition == TRUE) {
        RunPresetsFSM(EXIT_EVENT);
        CurrentState = nextState;
        RunPresetsFSM(ENTRY_EVENT);
    }
    //printf("Leaving RunpresetsHSM with CurrentState = %d\n", CurrentState);
    ES_Tail(); // trace call stack end
    return ThisEvent;
}


/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/



