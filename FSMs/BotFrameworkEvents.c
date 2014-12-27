#include "Bot.h"
#include "BOARD.h"
#include "BotFrameworkEvents.h"
#include "ES_ServiceHeaders.h"
#include "ES_Events.h"
#include "ES_Configure.h"
#include "ES_Timers.h"
#include <stdio.h>
#include "Motor_X_FSM.h"
#include "Motor_Y_FSM.h"

#ifndef MAX
#define MIN 0
#define MAX 1
#endif


static unsigned int PRESET1_MASK = 0b0001;
static unsigned int PRESET2_MASK = 0b0010;
static unsigned int PRESET3_MASK = 0b0100;
static unsigned int PRESET4_MASK = 0b1000;

static unsigned int X_Value_Current = 0;
static unsigned int Y_Value_Current = 0;
static unsigned int A_Value_Current = 0;

static unsigned int X_Value_Preset = 0;
static unsigned int Y_Value_Preset = 0;
static unsigned int A_Value_Preset = 0;

static unsigned int i = 0;
static unsigned int j = 0;

int abs(int n) {
    const int ret[2] = {n, -n};
    return ret [n < 0];
}

unsigned short getFilteredAD(uint8_t filterNumber) {
    if (filterNumber == AZIMUTH_POT) {
        return filteredAz;
    } else if (filterNumber == X_SLIDER) {
        return filteredX;
    } else if (filterNumber == Y_SLIDER) {
        return filteredY;
    } else return -1;
}

uint8_t check_Steps(void) {
    static unsigned int lastStepperState1 = 0x00000000;
    static unsigned int lastStepperState2 = 0x00000000;
    unsigned int currentStepperState1 = Stepper_GetRemainingCount(0);
    unsigned int currentStepperState2 = Stepper_GetRemainingCount(1);
    ES_Event ThisEvent1;
    ES_Event ThisEvent2;
    uint8_t returnVal = FALSE;

    if (Stepper_GetRemainingCount(MOTOR_X) == 0) {
        if (currentStepperState1 != lastStepperState1) {
            ThisEvent1.EventType = OUTOFSTEPS;
            returnVal = TRUE;
            PostMotorXFSM(ThisEvent1);
        }
    }
    if (Stepper_GetRemainingCount(MOTOR_Y) == 0) {
        if (currentStepperState2 != lastStepperState2) {
            ThisEvent2.EventType = OUTOFSTEPS;
            returnVal = TRUE;
            PostMotorYFSM(ThisEvent2);
        }
    }
    lastStepperState1 = currentStepperState1;
    lastStepperState2 = currentStepperState2;
    return returnVal;
}

uint8_t check_Decel_Point(void) {

    unsigned int xDecelPoint = getDecelPointX();
    unsigned int yDecelPoint = getDecelPointY();

    ES_Event ThisEvent1;
    ES_Event ThisEvent2;
    uint8_t returnVal = FALSE;

    if (QueryMotorXStatus() == reversingX) {
        if (getStepsTaken(MOTOR_X) <= getDecelPointX()) {
            ThisEvent1.EventType = DECELPOINT;
            returnVal = TRUE;
            PostMotorXFSM(ThisEvent1);
        }
    } else if (QueryMotorXStatus() == forwardingX) {
        if (getStepsTaken(MOTOR_X) >= getDecelPointX()) {
            ThisEvent1.EventType = DECELPOINT;
            returnVal = TRUE;
            PostMotorXFSM(ThisEvent1);
        }
    }


    if (QueryMotorYStatus() == reversingY) {
        if (getStepsTaken(MOTOR_Y) <= getDecelPointY()) {
            ThisEvent2.EventType = DECELPOINT;
            returnVal = TRUE;
            PostMotorYFSM(ThisEvent2);
        }
    } else if (QueryMotorYStatus() == forwardingY) {
        if (getStepsTaken(MOTOR_Y) >= getDecelPointY()) {
            ThisEvent2.EventType = DECELPOINT;
            returnVal = TRUE;
            PostMotorYFSM(ThisEvent2);
        }
    }

    return returnVal;
}

uint8_t check_Accel_Point(void) {
    static unsigned int lastStepperState1 = 0x00000000;
    static unsigned int lastStepperState2 = 0x00000000;
    unsigned int currentStepperState1 = Stepper_GetRemainingCount(0);
    unsigned int currentStepperState2 = Stepper_GetRemainingCount(1);
    ES_Event ThisEvent1;
    ES_Event ThisEvent2;
    uint8_t returnVal = FALSE;

    if (Stepper_GetRemainingCount(MOTOR_X) == 0) {
        if (currentStepperState1 != lastStepperState1) {
            ThisEvent1.EventType = OUTOFSTEPS;
            returnVal = TRUE;
            PostMotorXFSM(ThisEvent1);
        }
    }
    if (Stepper_GetRemainingCount(MOTOR_Y) == 0) {
        if (currentStepperState2 != lastStepperState2) {
            ThisEvent2.EventType = OUTOFSTEPS;
            returnVal = TRUE;
            PostMotorYFSM(ThisEvent2);
        }
    }
    lastStepperState1 = currentStepperState1;
    lastStepperState2 = currentStepperState2;
    return returnVal;
}

uint8_t check_SpeedMatch(void) {
    unsigned int currentStepperSpeedX = getStepsRate(MOTOR_X);
    unsigned int currentStepperSpeedY = getStepsRate(MOTOR_Y);
    ES_Event ThisEvent1;
    ES_Event ThisEvent2;
    uint8_t returnVal = FALSE;

    if (currentStepperSpeedX == getStepsRateFinal(MOTOR_X)) {
        ThisEvent1.EventType = SPEEDMATCH;
        returnVal = TRUE;
        PostMotorXFSM(ThisEvent1);
    }
    if (currentStepperSpeedY == getStepsRateFinal(MOTOR_Y)) {
        ThisEvent2.EventType = SPEEDMATCH;
        returnVal = TRUE;
        PostMotorYFSM(ThisEvent2);
    }

    return returnVal;
}

uint8_t check_Almost_Steps(void) {
    static unsigned int lastStepperStateX = 0x00000000;
    static unsigned int lastStepperStateY = 0x00000000;
    unsigned int currentStepperStateX = Stepper_GetRemainingCount(MOTOR_X);
    unsigned int currentStepperStateY = Stepper_GetRemainingCount(MOTOR_Y);
    ES_Event ThisEvent1;
    ES_Event ThisEvent2;
    uint8_t returnVal = FALSE;


    if (Stepper_GetRemainingCount(MOTOR_X) <= (77 - 5)*2 * 2) {
        if (currentStepperStateX != lastStepperStateX) {
            ThisEvent1.EventType = ALMOSTOUTOFSTEPS;
            returnVal = TRUE;
            PostMotorXFSM(ThisEvent1);
        }
    }
    if (Stepper_GetRemainingCount(MOTOR_Y) <= (77 - 5)*2 * 2) {
        if (currentStepperStateY != lastStepperStateY) {
            ThisEvent2.EventType = ALMOSTOUTOFSTEPS;
            returnVal = TRUE;
            PostMotorYFSM(ThisEvent2);
        }
    }
    lastStepperStateX = currentStepperStateX;
    lastStepperStateY = currentStepperStateY;
    return returnVal;
}

uint8_t check_Limits() {
    static unsigned int lastLimits = 0;
    unsigned int currentLimits = Read_Limits();
    ES_Event ThisEvent;
    uint8_t returnVal = FALSE;

    if (currentLimits != lastLimits) {
        //check x
        if ((currentLimits & X_LIMIT_MASK) != 0) {
            if (currentLimits & X_MIN_MASK) {
                ThisEvent.EventType = X_LIMIT;
                ThisEvent.EventParam = MIN;
                PostMotorXFSM(ThisEvent);
            } else if ((currentLimits & X_MAX_MASK)) {
                ThisEvent.EventType = X_LIMIT;
                ThisEvent.EventParam = MAX;
                PostMotorXFSM(ThisEvent);
            }
        }

        if ((currentLimits & Y_LIMIT_MASK) != 0) {
            if (currentLimits & Y_MIN_MASK) {
                ThisEvent.EventType = Y_LIMIT;
                ThisEvent.EventParam = MIN;
                PostMotorXFSM(ThisEvent);
            } else if (currentLimits & Y_MAX_MASK) {
                ThisEvent.EventType = Y_LIMIT;
                ThisEvent.EventParam = MAX;
                PostMotorXFSM(ThisEvent);
            }
        }
    }

}

uint8_t check_Azimuth(void) {
    static unsigned short temp = 0, *shifter, lastAD_StateA = 0,
            currentAD_StateA = 0, i = 0, difference = 0, count = 0;
    unsigned int sum = 0;
    uint8_t returnVal = FALSE;
    ES_Event ThisEvent1;

    uart();

    currentAD_StateA = ReadAzimuth();

    for (i = 1; i < ARRAY_LENGTH; i++) {
        count++;
        shifter = &azArray[(ARRAY_LENGTH - i - 1)];
        temp = *shifter;
        *(shifter + 1) = temp;
        sum = sum + temp;

        if (i == (ARRAY_LENGTH - 1)) {
            azArray[0] = currentAD_StateA;
            sum = sum + currentAD_StateA;
        }
    }
    currentAD_StateA = sum >> SHIFT_ITERATIONS;
    filteredAz = (lastAD_StateA - (lastAD_StateA * .05)) + (currentAD_StateA * .05);
    currentAD_StateA = filteredAz;

    if ((currentAD_StateA != lastAD_StateA)) {
        ThisEvent1.EventType = AZIMUTH_ELEVATION_CHANGE;
        ThisEvent1.EventParam = currentAD_StateA;
        PostServoAzimuthFSM(ThisEvent1);
        returnVal = TRUE;
    }
    lastAD_StateA = currentAD_StateA;
    return returnVal;
}

uint8_t check_XY_Sliders() {
    uint8_t returnVal = FALSE;
    //Is this going to cause problems?
    ES_Event ThisEvent1, ThisEvent2;

    static unsigned short lastAD_StateX = 0, temp = 0, *shifter, count = 0,
            lastAD_StateX2 = 0;
    static unsigned short lastAD_StateY = 0, temp1 = 0, *shifter1, i = 0,
            currentTime = 0;
    unsigned int currentAD_StateX = ReadXSlider(), sum = 0;
    unsigned int currentAD_StateY = ReadYSlider(), sum1 = 0;


    //printf("states:%d,%d\n",currentAD_StateX, currentAD_StateY);

    /*
    for (i = 1; i < ARRAY_LENGTH; i++) {
        count++;
        shifter = &xArray[(ARRAY_LENGTH - i - 1)];
        temp = *shifter;
     *(shifter + 1) = temp;
        sum = sum + temp;

        shifter1 = &yArray[(ARRAY_LENGTH - i - 1)];
        temp1 = *shifter1;
     *(shifter1 + 1) = temp1;
        sum1 = sum1 + temp1;
        if (i == (ARRAY_LENGTH - 1)) {
            xArray[0] = currentAD_StateX;
            yArray[0] = currentAD_StateY;

            sum = sum + xArray[0];
            sum1 = sum1 + yArray[0];
        }
    }

    currentAD_StateX = sum >> SHIFT_ITERATIONS;
    currentAD_StateY = sum1 >> SHIFT_ITERATIONS;

    //give 87.5% weight to past input, 12.5% to the current input - this is the filtered value
    filteredX = lastAD_StateX - (lastAD_StateX >> 3) + (currentAD_StateX >> 3);
    filteredY = lastAD_StateY - (lastAD_StateY >> 3) + (currentAD_StateY >> 3);

    currentAD_StateX = filteredX;
    currentAD_StateY = filteredY;
     */

    //if (((currentAD_StateX) != lastAD_StateX) && (count > 2000)) {
    if (((currentAD_StateX) != lastAD_StateX)) {

        ThisEvent1.EventType = XY_CHANGE;
        ThisEvent1.EventParam = currentAD_StateX;
        //       printf("xFilt:%d\n", currentAD_StateX);
        PostMotorXFSM(ThisEvent1);
        returnVal = TRUE;

    }

    //if (((currentAD_StateY) != lastAD_StateY) && (count > 2000)) {
    if (((currentAD_StateY) != lastAD_StateY)) {

        ThisEvent2.EventType = XY_CHANGE;
        ThisEvent2.EventParam = currentAD_StateY;
        //        printf("YFilt:%d\n", currentAD_StateY);
        PostMotorYFSM(ThisEvent2);
        returnVal = TRUE;

    }

    lastAD_StateX = currentAD_StateX;
    lastAD_StateY = currentAD_StateY;


    return returnVal;
}

