/*
 * File: RoachHSM.h
 * Author: Gabriel H Elkaim
 *
 * Simple flat state machine framework for the Roach project for CMPE-118 to get
 * you started on the project. The FSM simply ping pongs between two states on a
 * timer.
 */

#ifndef Presets_FSM_H
#define Presets_FSM_H


/*******************************************************************************
 * PUBLIC #INCLUDES                                                            *
 ******************************************************************************/

//#include "ES_Configure.h"
#define DATA_SIZE 16
#define DATA_ARRAY_LENGTH (DATA_SIZE/4)

static int value;

static int DEEdata = 0;
static unsigned short DEEaddr = 0;

#define xPos  1
#define yPos  2
#define aPos  3

#define xMin 0
#define xMax 1
#define yMin 2
#define yMax 3

#define LIMIT_STRUCT DATA_ARRAY_LENGTH

#define XSTATE 1
#define YSTATE 2
#define ASTATE 3

#define MIN 0
#define MAX 1

static char xMatch = FALSE;
static char yMatch = FALSE;
static char aMatch = FALSE;

static unsigned int presetNumber = 0;
static unsigned int eventParam = 0;

typedef enum {
    NOMATCH, MATCH
}presetMatchState_t;

static presetMatchState_t currentXState[4] = {[0 ... DATA_ARRAY_LENGTH-1] = NOMATCH};
static presetMatchState_t currentYState[4] = {[0 ... DATA_ARRAY_LENGTH-1] = NOMATCH};
static presetMatchState_t currentAState[4] = {[0 ... DATA_ARRAY_LENGTH-1] = NOMATCH};

uint8_t getCurrentMatchState(char whichState, unsigned int whichPreset);

typedef struct {
    //0 - presetNumber/xMin;
    //1 - xPos/xMax;
    //2 - yPos/yMin;
    //3 - ePos/yMax;
    unsigned int positionArr[4];
} Position;

//X, Y, E - 1, 2, 3
static Position positionArray[DATA_ARRAY_LENGTH+1]; //+1 for XY_limits numbers
static Position tempStruct;
/*******************************************************************************
 * PUBLIC #DEFINES                                                             *
 ******************************************************************************/
//
//#define forward(x) Stepper_SetSteps(0,FORWARD, x); Stepper_SetSteps(1,REVERSE, x)
//#define reverse(x) Stepper_SetSteps(0,REVERSE, x); Stepper_SetSteps(1,FORWARD, x)

/*******************************************************************************
 * PUBLIC TYPEDEFS                                                             *
 ******************************************************************************/

// typedefs for the states, which are used for the internal definition and also for
// the return of the query function. Be careful that all state names must be unique
// if they are exposed in the header file.

typedef enum {
    InitUState, initCenter, calibratePotsMin, calibratePotsMax, calibrateMotors, noPresets, programming,
            movingFaders, movingFaders2
} Presets_State_t;


/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/


Position getPresetStruct(unsigned int presetNumber);
/**
 * @Function InitRoachHSM(uint8_t Priority)
 * @param Priority - internal variable to track which event queue to use
 * @return TRUE or FALSE
 * @brief This will get called by the framework at the beginning of the code
 *        execution. It will post an ES_INIT event to the appropriate event
 *        queue, which will be handled inside RunRoachHSM function.
 *        Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
uint8_t InitPresetsFSM(uint8_t Priority);

/**
 * @Function PostRoachHSM(ES_Event ThisEvent)
 * @param ThisEvent - the event (type and param) to be posted to queue
 * @return TRUE or FALSE
 * @brief This function is a wrapper to the queue posting function, and its name
 *        will be used inside ES_Configure to point to which queue events should
 *        be posted to. Returns TRUE if successful, FALSE otherwise
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
uint8_t PostPresetsFSM(ES_Event ThisEvent);

/**
 * @Function QueryRoachSM(void)
 * @param none
 * @return Current state of the state machine
 * @brief This function is a wrapper to return the current state of the state
 *        machine. Return will match the ENUM above.
 * @author Gabriel H Elkaim, 2013.09.26 15:33 */
Presets_State_t QueryPresetsFSM(void);

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
ES_Event RunPresetsFSM(ES_Event ThisEvent);

#endif /* RoachHSM_H */

