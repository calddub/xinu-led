
#include <xinu.h>

//devcall ledopen( int deviceid ) {
char ledgetc( int devid ) {

	char val;

	if( ledtab[devid].openhndl == 0 ) {
		return SYSERR;
	}

	switch( ledtab[devid].state ) {
		case 1:
			val = 'Y';
			break;
		case 0:
			val = 'N';
			break;
		default:
			return SYSERR;
	}

	return val;
}

