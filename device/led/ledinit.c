
#include <xinu.h>


devcall ledinit() {

	/*--------------------------*/
	/* Initialize the hardware. */
	/*--------------------------*/
	vGalileoInitializeGpioController();
	vGalileoInitializeLegacyGPIO();
	vGalileoLegacyGPIOInitializationForLED();

	return OK;
}
