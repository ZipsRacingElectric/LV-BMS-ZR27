#ifndef CAN_H
#define CAN_H

// ChibiOS
#include "ch.h"

// CAN Configuration ----------------------------------------------------------------------------------------------------------
//
// Author: Jake Nowak
// Date Created: 2026.11.15
//
// Description: Objects related the the LV BMS's CAN interface.

// Functions ------------------------------------------------------------------------------------------------------------------

bool canInterfaceInit(tprio_t prioriity);

#endif // CAN_H 