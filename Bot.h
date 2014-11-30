#include <xc.h>
#include "IO_Ports.h"
#include "Stepper.h"
#include "RC_Servo.h"
#include "pwm.h"
#include "serial.h"
#include "AD.h"
#include "BOARD.h"

#define NUM_ANALOG_IN 3
//#define NUM_ANALOG_IN 3
//#define AZIMUTH_POT AD_PORTV5 //A01
//#define X_SLIDER AD_PORTV3 //A00
//#define Y_SLIDER AD_PORTV4 //A06 --- I'm not sure if this is correct. Odd entry in data sheet, may need to change


#define AZIMUTH_POT 0 //A01
#define X_SLIDER 1 //A00
#define Y_SLIDER 2

#define RS485_TRX_EN_TRIS PORTV05_TRIS
#define RS485_TRX_EN PORTV05_BIT

#define AZIMUTH_RC RC_PORTY06 //RC, pin 8

#define SERVO_ENABLE PORTX10_LAT //pin 37, output pin to BJT base
//#define SERVO_ENABLEB PORTX10_BIT //pin 37, output pin to BJT base

#define SERVO_ENABLE_TRIS PORTX10_TRIS

#define X_LIMIT_MIN PORTZ09_BIT //pin 27
#define X_LIMIT_MAX PORTZ10_BIT //pin 1
#define Y_LIMIT_MIN PORTZ11_BIT //pin 26
#define Y_LIMIT_MAX PORTZ12_BIT //pin 0

#define X_LIMIT_MIN_TRIS PORTZ09_TRIS //pin 27
#define X_LIMIT_MAX_TRIS PORTZ10_TRIS //pin 1
#define Y_LIMIT_MIN_TRIS PORTZ11_TRIS //pin 26
#define Y_LIMIT_MAX_TRIS PORTZ12_TRIS //pin 0


static uint16_t ADC_I2C[NUM_ANALOG_IN] = {0, 0, 0};

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/
//User defined declarations
static int addressEE = 0;

void Bot_Init(void);

void setupADRC_Pins(void);

void setup_Pins(void);

void setupMotors(void);

unsigned int ReadXSlider(void);

unsigned int ReadYSlider(void);

unsigned ReadAzimuth(void);

unsigned int Read_Limits(void) ;

char Read_ADC_over_I2C(void);

void uart(void);