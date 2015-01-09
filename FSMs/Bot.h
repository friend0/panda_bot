/**
* @file Bot.h
* @author Ryan Rodriguez
* @date 12/26/14
* @brief Hardware Initialization file
*
* This file is used to initialize GPIO, stepper interrupts, servo, and Uart
* capabilities.
*/

/*******************************************************************************
* MODULE #INCLUDE
******************************************************************************/
#define _SUPPRESS_PLIB_WARNING

#include <xc.h>
#include "IO_Ports.h"
#include "Stepper.h"
#include "RC_Servo.h"
#include "pwm.h"
#include "serial.h"
#include "AD.h"
#include "BOARD.h"


#define NUM_ANALOG_IN 3
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

/*******************************************************************************
* PRIVATE MODULE VARIABLES
******************************************************************************/
static int addressEE = 0;

/*******************************************************************************
 * PUBLIC FUNCTION PROTOTYPES                                                  *
 ******************************************************************************/

/**
* @brief Function to be called from main().
*
* This function is used for hardware inits, and is to be called in main()
* before the framework is initialized and running.
* @code{.c}
* void main(void){
* Bot_Init();
* .
* .
* .
* }
* @endcode
* @param param1 Void
* @return None.
* @see setupADRC_Pins
* @see setup_Pins
* @see setupMotors
* @warning Do not call outside of main, or more than once.
*/
void Bot_Init(void);
/**
 * @brief AD and Servo Init
 * Used to initialize ADC and RC servo pin functionality
 */
void setupADRC_Pins(void);
/**
 * @brief GPIO init
 * Used to Configure GPIO
 */
void setup_Pins(void);
/**
 * @brief Motor Init
 * Methods for configuring stepper motors. Makes calls to stepper init functions
 */
void setupMotors(void);

/**
* @brief User input X
 * Getter function for X axis slide pot
 * @return  returns a 10bit ADC value.
 * @note This function has been composed of packeted data from the Pic24
 */
unsigned int ReadXSlider(void);

/**
* @brief User Input Y
* Getter function for Y axis slide pot
* @return  returns a 10bit ADC value.
* @note This function has been composed of packeted data from the Pic24
*/unsigned int ReadYSlider(void);

/**
* @brief User Input Az
* Getter function for Azimuthal rotary pot.
* @return  returns a 10bit ADC value.
* @note This function has been composed of packeted data from the Pic24
*/
unsigned ReadAzimuth(void);

/**
* @brief Limit Switches
* Hardware getter function to check the status of the X and Y axis limit
* switches.
* @return  returns a bit string of GPIO values corresponding to the limit switches
* state
*/
unsigned int Read_Limits(void) ;

/**
 * @brief UART packet routing routine
 * This function checks the UART buffer being populated by the serial module.
 * If there are items in the buffer, we check for framing. If framing condition
 * is found, packets are routed and error checked. Good packets are used to update
 * the ADC values.
 */
void uart(void);
