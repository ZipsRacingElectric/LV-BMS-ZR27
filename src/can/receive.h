#ifndef RECEIVE_H
#define RECEIVE_H

// VCU CAN Receive Handler ----------------------------------------------------------------------------------------------------
//
// Author: Jake Nowak
// Date Created: 2026.11.17
//
// Description: Functions for handling CAN messages that don't belong to a CAN node. These messages are not transmitted
//   periodically, but are rather used to configure the VCU.

// Includes -------------------------------------------------------------------------------------------------------------------

// ChibiOS
#include "hal.h"

// Functions ------------------------------------------------------------------------------------------------------------------

/**
 * @brief Handles the received CAN message, if it is intended for the VCU.
 * @param configPtr The config of the calling CAN thread.
 * @param frame The received CAN message.
 * @return 0 if handled, -1 otherwise.
 */
int8_t receiveMessage (void* configPtr, CANRxFrame* frame);

#endif // RECEIVE_H