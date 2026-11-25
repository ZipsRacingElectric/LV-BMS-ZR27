#ifndef EEPROM_MAP_H
#define EEPROM_MAP_H

// EEPROM Map -----------------------------------------------------------------------------------------------------------------
//
// Author: Jake Nowak
// Date Created: 2026.11.14
//
// Description: Structure mapping of EEPROM data to variables

// Includes -------------------------------------------------------------------------------------------------------------------

#include "peripherals/adc/analog_linear.h"

// Constants ------------------------------------------------------------------------------------------------------------------

/// @brief The magic string of the EEPROM. Update this every time the memory map changes to force manual re-programming.
#define EEPROM_MAP_STRING "LV_BMS_2026_11_14" 

// Datatypes ------------------------------------------------------------------------------------------------------------------

typedef struct 
{
    /// @brief First 16 bytes on EEPROM reserved for magic string.
    uint8_t pad0 [16];

} eepromMap_t;

// Functions ------------------------------------------------------------------------------------------------------------------

/// @brief Handles a write to the 'write-only' section of the device's virtual EEPROM.
/// @note Currently is not implemented.
bool writeonlyWrite (void* eeprom, uint16_t addr, const void* data, uint16_t dataCount);

/// @brief Handles a read from the 'read-only' section of the device's virtual EEPROM.
/// @note Used for reading temporary data.
bool readonlyRead (void* eeprom, uint16_t addr, const void* data, uint16_t dataCount);

#endif // EEPROM_MAP_H