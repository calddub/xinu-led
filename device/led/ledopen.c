
#include <xinu.h>


// Need to define in configuration file
//   The LED "device" structure which consistst of device id, openstate, and ledstate
//   This structure and shared  /global variable should be initilized in ledinit

//devcall ledopen( int deviceid ) {
devcall ledopen( ) {

	// variables
	// 1) Check if device already open
	// 2a - T) Return SYSERR
	// 2b - F) set device open ==1
	//         initialize to LED off (?)
	//         return device ID
	//
	if( ledobj[0] == 1 ) {
		return SYSERR;
	}

	ledobj[0] = 1;  // open the device
	ledobj[0].state = 0; // Start in the of position
	vGalileoFlashLEDUsingLegacyGPIO(0);  // FOrce off on open
	return 0;  // send back th device ID (only 1 LED, and it's ID == 0)
}

