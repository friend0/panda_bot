/* 
 * File:   BotFrameworkEvents.h
 * Author: mdunne
 *
 * Created on January 3, 2013, 4:53 PM
 */

#ifndef BOTFRAMEWORKEVENTS_H
#define	BOTFRAMEWORKEVENTS_H

//typedef enum {
//    AZIMUTH_CHANGE, ELEVATION_CHANGE
//}azimuthElevationState_t;

#define X_PRESET_POS 1
#define Y_PRESET_POS 2
#define A_PRESET_POS 3

#define ARRAY_LENGTH 4
#define SHIFT_ITERATIONS 2 //log base 2 arrLen

static unsigned short X_LIMIT_MASK = 0x00000011;
static unsigned short Y_LIMIT_MASK = 0x00001100;

static unsigned short X_MIN_MASK = 0x00000001;
static unsigned short X_MAX_MASK = 0x00000010;
static unsigned short Y_MIN_MASK = 0x00000100;
static unsigned short Y_MAX_MASK = 0x00001000;



static unsigned short filteredAz = 0;
static unsigned short filteredX = 0;
static unsigned short filteredY = 0;
static unsigned short azArray[ARRAY_LENGTH] = {[0 ... ARRAY_LENGTH-1] = 0};
static unsigned short xArray[ARRAY_LENGTH] = {[0 ... ARRAY_LENGTH-1] = 0};
static unsigned short yArray[ARRAY_LENGTH] = {[0 ... ARRAY_LENGTH-1] = 0};
static unsigned short xAvg[ARRAY_LENGTH] = {0};
static unsigned short yAvg[ARRAY_LENGTH] = {0};

static unsigned short xm1 = 0;
static unsigned short xm2 = 0;
static unsigned short xm3 = 0;
static unsigned short xm4 = 0;

unsigned short getFilteredAD(uint8_t filterNumber);

uint8_t check_Steps(void);
uint8_t check_Almost_Steps(void);
uint8_t check_SpeedMatch(void);
uint8_t check_Limits(void);
uint8_t check_NearLimits(void);
uint8_t check_XY_Sliders(void);
uint8_t check_Azimuth(void);
uint8_t check_Azimuth(void);
uint8_t check_Decel_Point(void);
uint8_t check_Accel_Point(void);


#endif	/* ROACHFRAMEWORKEVENTS_H */

