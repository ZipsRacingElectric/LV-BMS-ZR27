// Header
#include "can.h"

// Includes 
#include "can/can_thread.h"
#include "can/receive.h"

// Configuration --------------------------------------------------------------------------------------------------------------

static const canThreadConfig_t CAN1_CONFIG =
{
	.name			= "can1_rx",
	.driver			= &CAND1,
	.period			= TIME_MS2I (10),
	.rxHandler		= receiveMessage,
	.bridgeDriver	= NULL
};

/**
 * @brief Configuration of the CAN 1 peripheral.
 * @note See section 32.9 of the STM32F405 Reference Manual for more details.
 * @note Also see: https://www.canbusdebugger.com/can-bit-timing-calculator.
 */
static const CANConfig CAN_DRIVER_CONFIG =
{
	.mcr = 	CAN_MCR_ABOM |		// Automatic bus-off management.
			CAN_MCR_AWUM |		// Automatic wakeup mode.
			CAN_MCR_TXFP,		// Chronologic FIFI priority.
	.btr =	CAN_BTR_SJW (1) |	// Max 2 TQ resynchronization jump.
			CAN_BTR_TS2 (1) |	// 2 TQ for time segment 2
			CAN_BTR_TS1 (10) |	// 11 TQ for time segment 1
			CAN_BTR_BRP (2)		// Baudrate divisor of 3 (1 Mbps)
};

// Threads --------------------------------------------------------------------------------------------------------------------

static CAN_THREAD_WORKING_AREA (can1RxThreadWa);

// Functions -------------------------------------------------------------------------------------------------------------------

bool canInterfaceInit(tprio_t priority)
{
    // CAN 1 driver intialization
    if (canStart (&CAND1, &CAN_DRIVER_CONFIG) != MSG_OK)
        return false;
    
    // Lave standby mode
    palClearLine (LINE_CAN1_STBY);

	// Create the CAN 1 RX thread
	canThreadStart (can1RxThreadWa, sizeof (can1RxThreadWa), priority, &CAN1_CONFIG);

    return true;
}