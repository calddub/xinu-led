
#include <xinu.h>

devcall ledclose( int devid ) {

	if( ledtab[devid].openhndl == 0 ) {
		return SYSERR;
	}

	ledtab[devid].state = 0; // Start in the of position
	vGalileoFlashLEDUsingLegacyGPIO(0);  // FOrce off on close
	ledtab[devid].openhndl = 0;  // close the device
	return;   // send control back to calling program
}

