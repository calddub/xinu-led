
#include <xinu.h>

// create the LED device table
struct leddev ledtab[LEDCNT];

devcall ledinit() {

	/*--------------------------*/
	/* Initialize the hardware. */
	/*--------------------------*/
	vGalileoInitializeGpioController();
	vGalileoInitializeLegacyGPIO();
	vGalileoLegacyGPIOInitializationForLED();

	// For a mutli-LED impelemtnnation, we could loop through 0 to LEDcnt
	ledtab[0].openhndl = 0;  // On init, LED device is not open
	ledtab[0].state    = 0;  // On init, LED device is off

	return OK;
}
