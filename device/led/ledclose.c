
#include <xinu.h>

//devcall ledopen( int deviceid ) {
devcall ledopen( ) {

	// variables
	// 1) Check if device already open
	// 2a - T) Return SYSERR
	// 2b - F) set device open ==1
	//         initialize to LED off (?)
	//         return device ID
	//
	if( ledobj[0] == 0 ) {
		return SYSERR;
	}

	ledobj[0].state = 0; // Start in the of position
	vGalileoFlashLEDUsingLegacyGPIO(0);  // FOrce off on close
	ledobj[0] = 0;  // close the device
	return;   // send control back to calling program
}

