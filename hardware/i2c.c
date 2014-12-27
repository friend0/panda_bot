#include "i2c.h"
#include <peripheral/adc10.h>
#include <BOARD.h>


char AD_Init(void)
{

    if (I2C_ACTIVE) {
        return ERROR;
    }
    int pin = 0;
    //ensure that the battery monitor is active
    //ActivePins = BAT_VOLTAGE_MONITOR;
    ADActive = TRUE;
    AD_SetPins();
    for (pin = 0; pin < NUM_AD_PINS; pin++) {
        ADValues[pin] = -1;
    }
    INTEnable(INT_AD1, INT_DISABLED);
    INTClearFlag(INT_AD1);
    INTSetVectorPriority(INT_ADC_VECTOR, 1);
    INTSetVectorSubPriority(INT_ADC_VECTOR, 3);
    INTEnable(INT_AD1, INT_ENABLED);
    EnableADC10();
    ADNewData = FALSE;
    //wait for first reading to ensure  battery monitor starts in the right spot
    while (!AD_IsNewDataReady()) {
        #ifdef AD_DEBUG_VERBOSE
                PutChar('.');
        #endif
        }
    //set the first values for the battery monitor filter
    //Filt_BatVoltage = AD_ReadADPin(BAT_VOLTAGE_MONITOR);
    //CurFilt_BatVoltage = Filt_BatVoltage;
    //PrevFilt_BatVoltage = Filt_BatVoltage;

    return SUCCESS;
}