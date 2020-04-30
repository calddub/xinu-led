
#include <xinu.h>

devcall ledread( int devid, char *str) {

	char tmpret = ledgetc( devid );

	if( tmpret == SYSERR ) 
		return( SYSERR );

	str[0] = tmpret;
	str[1] = '\0';

	return( strlen(str));
}


