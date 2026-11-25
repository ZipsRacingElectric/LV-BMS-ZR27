// Includes -------------------------------------------------------------------------------------------------------------------

// Includes
#include "debug.h"
#include "peripherals.h"
#include "can.h"

// ChibiOS
#include "ch.h"
#include "hal.h"

// Entrypoint -----------------------------------------------------------------------------------------------------------------

void hardFaultCallback (void)
{
	// Do nothing for now
}

int main (void)
{
	// ChibiOS Initialization
	halInit ();
	chSysInit ();

	// Debug Initialization
	ioline_t ledLine = LINE_LED_HEARTBEAT;
	debugHeartbeatStart (&ledLine, LOWPRIO);
	debugSerialInit (&SD1, NULL);

	// Peripherals Initialization
	if (!peripheralsInit())
	{
		hardFaultCallback();
		while (true);
	}

	// Initialize CAN interface
	if (!canInterfaceInit(NORMALPRIO))
	{
		hardFaultCallback();
		while(true);
	}

	// Do nothing.
	while (true)
		chThdSleepMilliseconds (500);
}