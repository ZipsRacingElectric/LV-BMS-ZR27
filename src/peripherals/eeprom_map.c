#include "eeprom_map.h"

bool eepromWriteonlyWrite (void* eeprom, uint16_t addr, const void* data, uint16_t dataCount)
{
	(void) eeprom;
	(void) addr;
	(void) data;
	(void) dataCount;

	return false;
}

bool eepromReadonlyRead(void *eeprom, uint16_t addr, void *data, uint16_t dataCount)
{
    (void) eeprom;
    (void) addr;
    (void) data;
    (void) dataCount;

    return false;
}