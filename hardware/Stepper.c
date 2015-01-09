/*
 * File:   Stepper.c
 * Author: Elkaim
 *
 * Created on January 2, 2012, 9:49 PM
 */
#include <xc.h>
#include <peripheral/timer.h>
#include "Stepper.h"
#include "serial.h"
/*******************************************************************************
 * PRIVATE #DEFINES                                                            *
 ******************************************************************************/
//#define STEPPER_TEST
//#define DEBUG_VERBOSE

#ifdef DEBUG_VERBOSE
#define dbprintf(...) printf(__VA_ARGS__)
#else
#define dbprintf(...)
#endif

/* Note that you need to set the prescalar and periferal clock appropriate to
 * the processor board that you are using. In order to calculate the minimal
 * prescalar: Prescalar = (2000*F_PB/(1000000*0xFFFF))+1, round down */
#ifndef F_CPU
#define F_CPU       80000000L
#define F_PB        (F_CPU/2)
#define F_PB_DIV8   (F_PB/8)
#define F_PB_DIV64  (F_PB/64)
#define ONE_KHZ_RATE  (F_PB_DIV8-1)/1000
#endif

#define MED_HZ_RATE 77
#define LOW_HZ_RATE 10
#define LOW_REP_NUM 64
#define TWENTY_KILOHERTZ 20000

#define MIN_RATE 2
#define INCREMENT_SIZE 1

static uint8_t countX = 0, countY = 0;
/*******************************************************************************
 * PRIVATE VARIABLES                                                           *
 ******************************************************************************/

/*Array way*/
static int stepCounts[NUM_STEPPER_MOTORS] = {0, 0}; //steps left
static unsigned int stepsTaken[NUM_STEPPER_MOTORS] = {0, 0}; //steps taken from neutral(railed to motor side)
static unsigned char stepDirs[NUM_STEPPER_MOTORS] = {FORWARD, FORWARD};
static unsigned long totalStepCounts[NUM_STEPPER_MOTORS] = {0, 0};
static unsigned short overflowReps[NUM_STEPPER_MOTORS] = {0, 0};
static unsigned short overflowPeriod[NUM_STEPPER_MOTORS] = {0, 0};
static unsigned int stepRate[NUM_STEPPER_MOTORS] = {0, 0};
static unsigned int currentRate[NUM_STEPPER_MOTORS] = {0, 0};
static unsigned int rateDifference[NUM_STEPPER_MOTORS] = {0, 0};

static unsigned short timerLoopCount[NUM_STEPPER_MOTORS] = {0, 0};
static int i = 0;

typedef enum {
    step_one, step_two
} coilState_t;

stepperState_t motorStates[2] = {off, off};
coilState_t coilStates[2] = {step_one, step_one};

/*******************************************************************************
 * PRIVATE FUNCTIONS PROTOTYPES                                                *
 ******************************************************************************/
/**
 * @Function: CalculateOverflowPeriod(unsigned short int rate);
 * @param pulse rate is steps per second (0 = 0.5Hz, special case)
 * @return period overflow for timer to match step rate
 * @remark Calculates the overflow period and sets the module variable
 *         overflowReps to match for the right step rate.
 *         Note: rate 0 is a special case corresponding to 0.5Hz
 * @author Gabriel Hugh Elkaim
 * @date 2012.01.28 23:21 */

unsigned short int CalculateOverflowPeriod(unsigned short int motorNumber, unsigned short int rate);

/*******************************************************************************
 * PUBLIC FUNCTIONS                                                           *
 ******************************************************************************/

/* There are three possibilities for the step rate calculation that keep the
   step rate error to under 0.2% of the desired value, from within 0.5 to 2KHz:
   from 78 to 20Khz, Prescale is 1:8, Rollover = (F_PB/8-1)/PPS
   from 10 to 77Hz, Prescale is 1:64, Rollover = (F_PB/64-1)/PPS
   from 0.5 to 10Hz, Set rollover for a constant 1Khz, and increment to reach
   the desired time, Prescale is 1:8, Rollover = (F_PB/8-1)/1000 and the number
   of times to repeat is (1000-1)/PPS + 1
 *
 *                                  */
unsigned int getStepsTaken(unsigned short int motorNumber) {
    return stepsTaken[motorNumber];
}

unsigned int getStepsRate(unsigned short int motorNumber) {
    return currentRate[motorNumber];
}

unsigned int setCurrentStepsRate(unsigned short int motorNumber, unsigned int rate) {
    return currentRate[motorNumber] = rate;
}

unsigned int getStepsRateFinal(unsigned short int motorNumber) {
    return stepRate[motorNumber];
}

unsigned int setStepsRate(unsigned short int motorNumber, unsigned int rate) {
    return stepRate[motorNumber] = rate;
}


char setStepsTaken(unsigned short int motorNumber, unsigned int steps) {
    stepsTaken[motorNumber] = steps;
    return SUCCESS;
}

char Stepper_Init(unsigned short int motorNumber, unsigned int rate) {
    if (motorNumber < 0 || motorNumber > NUM_STEPPER_MOTORS) return ERROR;
    if (rate > TWENTY_KILOHERTZ) return ERROR;
    stepCounts[motorNumber] = 0;
    stepRate[motorNumber] = rate;
    currentRate[motorNumber] = MIN_RATE;
    overflowPeriod[motorNumber] = CalculateOverflowPeriod(motorNumber, MIN_RATE);
    if (motorNumber == MOTOR_X) {

        TRIS_STEPPER_BOARD0_DIRECTION = 0;
        TRIS_STEPPER_BOARD0_ENABLE = 0;
        TRIS_STEPPER_BOARD0_STEP = 0;

        STEPPER_BOARD0_ENABLE = 0;
        STEPPER_BOARD0_DIRECTION = 0;
        STEPPER_BOARD0_STEP = 0;

        OpenTimer5(T5_ON | T5_SOURCE_INT | T5_PS_1_8, overflowPeriod[MOTOR_X]);
        ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_3);
        mT5IntEnable(1);
        motorStates[MOTOR_X] = inited;
    } else if (motorNumber == MOTOR_Y) {
        TRIS_STEPPER_BOARD1_DIRECTION = 0;
        TRIS_STEPPER_BOARD1_ENABLE = 0;
        TRIS_STEPPER_BOARD1_STEP = 0;

        STEPPER_BOARD1_ENABLE = 0;
        STEPPER_BOARD1_DIRECTION = 0;
        STEPPER_BOARD1_STEP = 0;

        OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_8, overflowPeriod[MOTOR_Y]);
        ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_3);
        mT4IntEnable(1);
        motorStates[MOTOR_Y] = inited;
    } else return ERROR;

    return SUCCESS;
}

char Steppers_Init(unsigned short int rate) {
    stepRate[MOTOR_X] = rate;
    stepRate[MOTOR_Y] = rate;
    currentRate[MOTOR_X] = MIN_RATE;
    currentRate[MOTOR_Y] = MIN_RATE;

    if (rate > TWENTY_KILOHERTZ) return ERROR;

    STEPPER_BOARD0_ENABLE = 0;
    STEPPER_BOARD0_DIRECTION = 0;
    STEPPER_BOARD0_STEP = 0;

    TRIS_STEPPER_BOARD0_DIRECTION = 0;
    TRIS_STEPPER_BOARD0_ENABLE = 0;
    TRIS_STEPPER_BOARD0_STEP = 0;

    STEPPER_BOARD1_ENABLE = 0;
    STEPPER_BOARD1_DIRECTION = 0;
    STEPPER_BOARD1_STEP = 0;

    TRIS_STEPPER_BOARD1_DIRECTION = 0;
    TRIS_STEPPER_BOARD1_ENABLE = 0;
    TRIS_STEPPER_BOARD1_STEP = 0;

    for (i = 0; i < NUM_STEPPER_MOTORS; i++) {
        motorStates[i] = inited;
        stepCounts[i] = 0;
        overflowPeriod[i] = CalculateOverflowPeriod(i, MIN_RATE);
    }

    OpenTimer5(T5_ON | T5_SOURCE_INT | T5_PS_1_8, overflowPeriod[MOTOR_X]);
    ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_3);
    mT5IntEnable(1);

    OpenTimer4(T4_ON | T4_SOURCE_INT | T4_PS_1_8, overflowPeriod[MOTOR_Y]);
    ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_3);
    mT4IntEnable(1);

    return SUCCESS;
}

char Stepper_ChangeStepRate(unsigned short int motorNumber, unsigned short int rate) {
    if (motorNumber < 0 || motorNumber > NUM_STEPPER_MOTORS) return ERROR;
    if ((rate > TWENTY_KILOHERTZ)) {
        return ERROR;
    }
    overflowPeriod[motorNumber] = CalculateOverflowPeriod(motorNumber, rate);
    dbprintf("\nChanging step rate, motor %d", motorNumber);
    if (motorNumber == MOTOR_X) {
        T5CONbits.ON = 0;
        WritePeriod5(overflowPeriod[motorNumber]);
        if (motorStates[MOTOR_X] != halted) {
            T5CONbits.ON = 1;
        }
    } else if (motorNumber == MOTOR_Y) {
        T4CONbits.ON = 0;
        WritePeriod4(overflowPeriod[motorNumber]);
        if (motorStates[MOTOR_Y] != halted) {
            T4CONbits.ON = 1;
        }
    }
    return SUCCESS;
}

/*Array Way*/
char Stepper_SetSteps(unsigned short int motorNumber, char direction, unsigned int steps) {
    if (motorStates[motorNumber] == off)return ERROR;
    if ((motorNumber < 0) || (motorNumber > NUM_STEPPER_MOTORS)) return ERROR;
    if ((direction == FORWARD) || (direction == REVERSE)) {
        stepDirs[motorNumber] = direction;
        if (motorNumber == MOTOR_X) {
            STEPPER_BOARD0_DIRECTION = stepDirs[motorNumber];
        } else if (motorNumber == MOTOR_Y) {
            STEPPER_BOARD1_DIRECTION = stepDirs[motorNumber];
        }
        stepCounts[motorNumber] = steps * 2;
        switch (motorStates[motorNumber]) {
            case waiting:
                motorStates[motorNumber] = stepping;
                break;
            case inited:
                motorStates[motorNumber] = stepping;
                break;
            default:
                break;
        }
        return SUCCESS;
    }
    return ERROR;
}

char Stepper_IncrementSteps(unsigned short int motorNumber, char direction, unsigned int steps) {
    if (motorNumber < 0 || motorNumber > NUM_STEPPER_MOTORS) return ERROR;
    unsigned int tempSteps;

    if ((motorStates[motorNumber] == off) || (stepCounts[motorNumber] == 0)) return ERROR;
    if ((direction == FORWARD) || (direction == REVERSE)) {
        if ((direction == FORWARD) && (stepDirs[motorNumber] == FORWARD)) {
            stepCounts[motorNumber] += steps;
        }
        if ((direction == REVERSE) && (stepDirs[motorNumber] == REVERSE)) {
            stepCounts[motorNumber] += steps;

        }
        if ((direction == FORWARD) && (stepDirs[motorNumber] == REVERSE)) {
            if (steps > stepCounts[motorNumber]) {
                tempSteps = steps - stepCounts[motorNumber];
                stepDirs[motorNumber] = FORWARD;
                stepCounts[motorNumber] = tempSteps;
            } else {
                stepCounts[motorNumber] -= steps;
            }
        }
        if ((direction == REVERSE) && (stepDirs[motorNumber] == FORWARD)) {
            if (steps > stepCounts[motorNumber]) {
                tempSteps = steps - stepCounts[motorNumber];
                stepDirs[motorNumber] = REVERSE;
                stepCounts[motorNumber] = tempSteps;
            } else {
                stepCounts[motorNumber] -= steps;
            }
        }
    }
    if (motorStates[motorNumber] != halted) {
        if (stepCounts[motorNumber] > 0) motorStates[motorNumber] = stepping;
        else {
            motorStates[motorNumber] = waiting;
            switch (motorStates[motorNumber]) {
                case 0:
                    ShutDownDrive0();
                    break;

                case 1:
                    ShutDownDrive1();
                    break;
            }
        }
    }
    return SUCCESS;
}

/*Array Way*/
char Stepper_GetDirection(unsigned short int motorNumber) {
    return stepDirs[motorNumber];
}

/*Array Way*/
unsigned int Stepper_GetRemainingCount(unsigned short int motorNumber) {
    return stepCounts[motorNumber];
}

void Stepper_AddStepCounts(unsigned short int motorNumber, short int steps) {
    if (motorNumber > 0 && motorNumber < NUM_STEPPER_MOTORS) {
        stepCounts[motorNumber] = stepCounts[motorNumber] + steps;
    }
}

char Stepper_GetState(unsigned short int motorNumber) {
    return motorStates[motorNumber];
}

/*ARRAY WAY*/
char Stepper_Halt(unsigned short int motorNumber) {
    if ((motorStates[motorNumber] == off) || (motorStates[motorNumber] == halted)) return ERROR;
    dbprintf("\nHalting Stepper drive");
    motorStates[motorNumber] = halted;
    if (motorNumber == MOTOR_X) {
        ShutDownDrive0();
        T5CONbits.ON = 0;
    } else if (motorNumber == MOTOR_Y) {
        ShutDownDrive1();
        T4CONbits.ON = 0;
    } else return ERROR;
    return SUCCESS;
}

char Stepper_Halt_Hard(unsigned short int motorNumber) {
    if ((motorStates[motorNumber] == off) || (motorStates[motorNumber] == halted)) return ERROR;
    dbprintf("\nHalting Stepper drive");
    motorStates[motorNumber] = halted;
    if (motorNumber = MOTOR_X) {
        TurnOnDrive0();
        T5CONbits.ON = 0;
    } else if (motorNumber = MOTOR_Y) {
        TurnOnDrive1();
        T4CONbits.ON = 0;
    } else return ERROR;
    return SUCCESS;
}

char Stepper_Resume(unsigned short int motorNumber) {
    if (motorStates[motorNumber] != halted) return ERROR;
    dbprintf("\nResuming Stepper drive");
    currentRate[motorNumber] = MIN_RATE;
    if (stepCounts[motorNumber] > 0) {
        motorStates[motorNumber] = stepping;
    } else {
        motorStates[motorNumber] = waiting;
    }
    if (motorNumber == MOTOR_X) T5CONbits.ON = 1;
    else if (motorNumber == MOTOR_Y) T4CONbits.ON = 1;
    else return ERROR;
    return SUCCESS;
}

/*Array Way*/
char Stepper_End(unsigned short int motorNumber) {
    if (motorNumber < 0 || motorNumber > NUM_STEPPER_MOTORS) return ERROR;
    if (motorStates[motorNumber] == off) return ERROR;
    dbprintf("\nTerminating Stepper module");
    motorStates[motorNumber] = off;
    overflowReps[motorNumber] = 0;
    stepCounts[motorNumber] = 0;
    coilStates[motorNumber] = step_one;
    if (motorNumber == MOTOR_X) {
        ShutDownDrive0();
        T5CONbits.ON = 0;
        CloseTimer5();
    } else if (motorNumber == MOTOR_Y) {
        ShutDownDrive1();
        T4CONbits.ON = 0;
        CloseTimer4();
    } else return ERROR;
    return SUCCESS;
}

/*******************************************************************************
 * PRIVATE FUNCTIONS                                                           *
 ******************************************************************************/

unsigned short int CalculateOverflowPeriod(unsigned short int motorNumber, unsigned short int rate) {
    dbprintf("\nCalculating Overflow period");
    if (rate == 0) {
        overflowReps[motorNumber] = 2000;
        return (ONE_KHZ_RATE);
    }
    if (rate > MED_HZ_RATE) {
        overflowReps[motorNumber] = 0;
        return ((F_PB_DIV8 - 1) / rate);
    }
    if (rate > LOW_HZ_RATE) {
        overflowReps[motorNumber] = LOW_REP_NUM;
        return ((F_PB_DIV64 - 1) / rate);
    }
    // rate is less than 10Hz, switch to counted 1KHz pulses
    overflowReps[motorNumber] = (1000 - 1) / rate + 1;
    return ONE_KHZ_RATE;
}

void __ISR(_TIMER_5_VECTOR, ipl3) Timer5IntHandler() {

    //STEPPER_BOARD0_STEP = ~STEPPER_BOARD0_STEP;
    if (++(timerLoopCount[MOTOR_X]) > overflowReps[MOTOR_X]) {
        timerLoopCount[MOTOR_X] = 0;
        switch (motorStates[MOTOR_X]) {
            case off: // should not get here
                dbprintf("\noff");
                T5CONbits.ON = 0;
                ShutDownDrive0();
                CloseTimer5();
                break;

            case inited:
                currentRate[MOTOR_X] = MIN_RATE;
                break;

            case halted:
                currentRate[MOTOR_X] = MIN_RATE;
                break;

            case waiting:
                currentRate[MOTOR_X] = MIN_RATE;
                ShutDownDrive0();
                if (stepCounts[MOTOR_X] < 0) stepCounts[MOTOR_X] = 0;
                break;

            case stepping:
                if (--stepCounts[MOTOR_X] <= 0) {
                    motorStates[MOTOR_X] = waiting;
                    //printf("waiting\n");
                }
                if (stepCounts[MOTOR_X] <= 0) currentRate[MOTOR_X] = MIN_RATE;
                TurnOnDrive0();
                STEPPER_BOARD0_DIRECTION = stepDirs[MOTOR_X];
                switch (coilStates[MOTOR_X]) {
                    case step_one:
                        STEPPER_BOARD0_STEP = 1;
                        if (stepDirs[MOTOR_X] == FORWARD) {
                            coilStates[MOTOR_X] = step_two;
                            stepsTaken[MOTOR_X]++;
                            //printf("Steps Taken X: %d \n", stepsTaken[MOTOR_X]);
                        } else {
                            //printf("We in this thang bruh\n");
                            coilStates[MOTOR_X] = step_two;
                            //                            if (stepsTaken[MOTOR_X] > 0) {
                            stepsTaken[MOTOR_X]--;
                            //printf("Steps Taken: %d \n", stepsTaken[MOTOR_X]);

                            //                            }
                        }

                        if (currentRate[MOTOR_X] < stepRate[MOTOR_X]) {
                            countX++;
                            if(currentRate[MOTOR_X] <= 25){
                                if (((countX % ACCEL_RATE) == 0) && (countX != 0)) {
                                    countX = 0;
                                    currentRate[MOTOR_X] += INCREMENT_SIZE;
                                    Stepper_ChangeStepRate(MOTOR_X, currentRate[MOTOR_X]);
                                }
                            }
                            else{
                                if (((countX % ACCEL_RATE) == 0) && (countX != 0)) {
                                    countX = 0;
                                    currentRate[MOTOR_X] += INCREMENT_SIZE*2;
                                    Stepper_ChangeStepRate(MOTOR_X, currentRate[MOTOR_X]);
                                }
                            }
                        }//deccelerating
                        else if (currentRate[MOTOR_X] > stepRate[MOTOR_X]) {
                            countX++;
                            if (currentRate[MOTOR_X] >= 25){
                                if (((countX % ACCEL_RATE*2) == 0) && (countX != 0)) {
                                    countX = 0;
                                    currentRate[MOTOR_X] -= INCREMENT_SIZE;
                                    Stepper_ChangeStepRate(MOTOR_X, currentRate[MOTOR_X]);
                                }
                            }
                            else{
                                if (((countX % ACCEL_RATE) == 0) && (countX != 0)) {
                                    countX = 0;
                                    currentRate[MOTOR_X] -= INCREMENT_SIZE;
                                    Stepper_ChangeStepRate(MOTOR_X, currentRate[MOTOR_X]);
                                }
                            }
                        }
                        break;

                    case step_two:
                        STEPPER_BOARD0_STEP = 0;
                        if (stepDirs[MOTOR_X] == FORWARD) coilStates[MOTOR_X] = step_one;
                        else coilStates[MOTOR_X] = step_one;
                        break;
                }
                break;
        }
        mT5ClearIntFlag();
    }
}

void __ISR(_TIMER_4_VECTOR, ipl3) Timer4IntHandler() {
    //static unsigned short timerLoopCount = 0;
    if (++(timerLoopCount[MOTOR_Y]) > overflowReps[MOTOR_Y]) {
        timerLoopCount[MOTOR_Y] = 0;
        switch (motorStates[MOTOR_Y]) {
            case off:
                dbprintf("\noff");
                T4CONbits.ON = 0; // halt Timer3
                ShutDownDrive1();
                CloseTimer4();
                break;

            case inited:
                currentRate[MOTOR_Y] = MIN_RATE;
                break;

            case halted:
                currentRate[MOTOR_Y] = MIN_RATE;
                break;

            case waiting:
                currentRate[MOTOR_Y] = MIN_RATE;
                ShutDownDrive1();
                if (stepCounts[MOTOR_Y] < 0) stepCounts[MOTOR_Y] = 0;
                break;

            case stepping:
                printf("Stepping Y\n");
                if (--stepCounts[MOTOR_Y] <= 0) motorStates[MOTOR_Y] = waiting;
                if (stepCounts[MOTOR_Y] <= 0) currentRate[MOTOR_Y] = MIN_RATE;
                TurnOnDrive1();
                STEPPER_BOARD1_DIRECTION = stepDirs[MOTOR_Y];

                switch (coilStates[MOTOR_Y]) {
                    case step_one:
                        STEPPER_BOARD1_STEP = 1;
                        if (stepDirs[MOTOR_Y] == FORWARD) {
                            coilStates[MOTOR_Y] = step_two;
                            stepsTaken[MOTOR_Y]++;
                            //printf("Steps Taken Y:%d\n", stepsTaken[MOTOR_Y]);
                        } else {
                            coilStates[MOTOR_Y] = step_two;
                            //if (motorStates[MOTOR_Y] == stepping) {
                            stepsTaken[MOTOR_Y]--;
                            //}
                        }//accelerating
                        if (currentRate[MOTOR_Y] < stepRate[MOTOR_Y]) {
                            countY++;
                            if ((countY % 3) == 0) {
                                countY = 0;
                                currentRate[MOTOR_Y] += INCREMENT_SIZE;
                                Stepper_ChangeStepRate(MOTOR_Y, currentRate[MOTOR_Y]);
                            }
                        }//deccelerating
                        else if (currentRate[MOTOR_Y] > stepRate[MOTOR_Y]) {
                            countY++;
                            if ((countY % 3) == 0) {
                                countY = 0;
                                currentRate[MOTOR_Y] -= INCREMENT_SIZE;
                                Stepper_ChangeStepRate(MOTOR_Y, currentRate[MOTOR_Y]);
                            }
                        }
                        break;

                    case step_two:
                        STEPPER_BOARD1_STEP = 0;
                        if (stepDirs[MOTOR_Y] == FORWARD) coilStates[MOTOR_Y] = step_one;
                        else coilStates[MOTOR_Y] = step_one;
                        break;
                }
                break;
        }
        mT4ClearIntFlag();
    }
}
/*******************************************************************************
 * TEST HARNESS                                                                *
 ******************************************************************************/
#ifdef STEPPER_TEST

#define NOPCOUNT 150000
#define DELAY() for(i=0; i< NOPCOUNT; i++) __asm("nop")

void harness(unsigned short int motorNumber);

int main(void) {
    int motorNumber = 0;
    int i;
    unsigned short pattern;
    char j, k;

    SERIAL_Init();
    AD1PCFG = 0xFF;
    INTEnableSystemMultiVectoredInt();


    if (Steppers_Init(250) == SUCCESS) {
        printf("Success1 - Motors Inited\n");
        DELAY();

    } else {
        printf("Failure - motors not inited\n");
    }

    if (Stepper_SetSteps(0, REVERSE, 20000) == SUCCESS) {
        printf("Success - Steps have been set\n");
        printf("Motor State: %d", motorStates[motorNumber]);

    } else {
        printf("Failure - Steps have not been set");
    }
    if (Stepper_SetSteps(1, FORWARD, 20000) == SUCCESS) {
        printf("Success - Steps have been set\n");
        printf("Motor State: %d", motorStates[motorNumber]);

    } else {
        printf("Failure - Steps have not been set");
    }

    if (Stepper_SetSteps(2, FORWARD, 20000) == SUCCESS) {
        printf("Success - Steps have been set\n");
        printf("Motor State: %d", motorStates[motorNumber]);

    } else {
        printf("Failure - Steps have not been set");
    }

    while (Stepper_GetRemainingCount(motorNumber) > 1 || Stepper_GetRemainingCount(1) > 1) {
        //printf("+");
        DELAY();
    }
    DELAY();

    printf("Finished Stepping");
    //harness(motorNumber);
    DELAY();
    return 0;
}

void harness(unsigned short int motorNumber) {
    int j, i;
    while (1) {

        printf("\nStepping forward 1000 steps");
        Stepper_SetSteps(motorNumber, FORWARD, 1000);

        while (Stepper_GetRemainingCount(motorNumber) > 1) {
            printf("+");
            DELAY();
        }
        printf("\nForward steps done");

        printf("\nStepping backward 1000 steps");

        if (Stepper_SetSteps(motorNumber, FORWARD, 10000)) {
            printf("Success - Steps have been set");
        }
        while (Stepper_GetRemainingCount(motorNumber) > 1) {
            //printf("+");
            DELAY();
        }
    }
}
#endif


