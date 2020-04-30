
#include <xinu.h>

devcall ledwrite( int devid, char *str) {
	if( strlen( str ) > 1 || strlen(str) == 0  ) {
		return SYSERR;
	}

	return( ledputc( devid, str[0] ));
}


