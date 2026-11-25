#ifndef CAN_H
#define CAN_H

// ChibiOS
#include "ch.h"

// CAN Configuration ----------------------------------------------------------------------------------------------------------
//
// Author: Jake Nowak
// Date Created: 2024.11.15
//
// Description: Objects related the the LV BMS's CAN interface.

// Functions ------------------------------------------------------------------------------------------------------------------

/// @brief The LV BMS does not currently receive and CAN messages, does not use a CAN thread.
bool canInterfaceInit(tprio_t prioriity);

#endif // CAN_H 