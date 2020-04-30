
#include <xinu.h>


// Need to define in configuration file
//   The LED "device" structure which consistst of device id, openstate, and ledstate
//   This structure and shared  /global variable should be initilized in ledinit

//devcall ledopen( int deviceid ) {
devcall ledopen( ) {

	int32 defdev = 0;  // Only 1 LED device, we're calling dev=0

	// variables
	// 1) Check if device already open
	// 2a - T) Return SYSERR
	// 2b - F) set device open ==1
	//         initialize to LED off (?)
	//         return device ID
	//
	if( ledtab[0].openhndl == 1 ) {
		return SYSERR;
	}

	ledtab[defdev].openhndl = 1;  // open the device
	ledtab[defdev].state = 0; // Start in the of position
	vGalileoFlashLEDUsingLegacyGPIO(0);  // Force off on open
	return defdev;  // send back th device ID (only 1 LED, and it's ID == 0)
}

