
#include <xinu.h>

devcall ledread( int devid, char *str) {

	char tret = ledgetc( devid );

	if( tret == SYSERR ) 
		return( SYSERR );

	str[0] = tret;
	str[1] = '\0';

	return( strlen(str));
}


