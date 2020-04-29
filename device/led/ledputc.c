
#include <xinu.h>

//devcall ledopen( int deviceid ) {
devcall ledputc( int devid, char state ) {

	if( ledobj[devid] == 0 ) {
		return SYSERR;
	}
	switch( state ) {
		case 'Y':
			ledobj[devid].state = 1; // Start in the of position
			break;
		case 'N':
			ledobj[devid].state = 0; // Start in the of position
			break;
		default:
			return SYSERR;
	}

	vGalileoFlashLEDUsingLegacyGPIO(ledobj[devid].state);
	return;
}

