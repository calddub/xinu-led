
#include <xinu.h>

//devcall ledopen( int deviceid ) {
devcall ledputc( int devid, char state ) {

	if( ledtab[devid].openhndl == 0 ) {
		return SYSERR;
	}

	switch( state ) {
		case 'Y':
			ledtab[devid].state = 1; // Start in the of position
			break;
		case 'N':
			ledtab[devid].state = 0; // Start in the of position
			break;
		default:
			return SYSERR;
	}

	vGalileoFlashLEDUsingLegacyGPIO(ledtab[devid].state);
	return;
}

