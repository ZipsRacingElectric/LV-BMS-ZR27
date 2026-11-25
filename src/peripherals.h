#ifndef PERIPHERALS_H
#define PERIPHERALS_H

// LV BMS Peripherals --------------------------------------------------------------------------------------------------------
//
// Author: Jake Nowak
// Date Created: 2026.11.14
//
// Description: Global objects representing onboard hardware of the LV BMS

// Includes -------------------------------------------------------------------------------------------------------------------

#include "peripherals/i2c/mc24lc32.h"
#include "peripherals/eeprom_map.h"

#include "peripherals/adc/stm_adc.h"

// Globals --------------------------------------------------------------------------------------------------------------------

/// @brief ADC responsible for sampling all on-board analog inputs ( @c currentShunt & @c packVoltage )
extern stmAdc_t adc;

/// @brief The device's 'virtual' EEPROM. This aggregates the physical EEPROM's memory with readonly / writeonly EEPROM's memory.
extern virtualEeprom_t virtualEeprom;

/// @brief A 'virtual' EEPROM used for reading temporary data or executing commands.
extern eeprom_t readonlyWriteonlyEeprom;

/// @brief The actual EEPROM installed on the device. This used for storing permanent data.
extern mc24lc32_t physicalEeprom;

/// @brief A 'map' of the physical EEPROM's memory. Used for reading data from its cache.
static eepromMap_t* const physicalEepromMap = (eepromMap_t*) physicalEeprom.cache;

// Functions --------------------------------------------------------------------------------------------------------------------

/**
 * @brief Initializes the LV BMS peripherals.
 * @return False if a fatal peripheral failed to initalize, true otherwise. 
 */
 bool peripheralsInit (void);

 /**
 * @brief Re-initializes the LV BMS's peripherals after a change has been made to the on-board EEPROM.
 * @param caller Ignored. Used to make function signature compatible with EEPROM dirty hook.
 */
void peripheralsReconfigure (void* caller);

/**
 * @brief Samples all of the peripheral sensors.
 * @param timePrevious The time at which this function was last called (last value provided to @c timeCurrent ).
 * @param timeCurrent The current system time.
 */
void peripheralsSample (systime_t timePrevious, systime_t timeCurrent);


#endif // PERIPHERALS_H
