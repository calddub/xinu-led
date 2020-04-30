
// Sets the max number of LED devices in the LEDtable
#ifndef LEDCNT
#define LEDCNT 1
#endif

// STrcuture depicting each LED device entry in the LED Table
struct leddev {
	int openhndl;  // Handle / flag indicating this object is open
	int state;     // 0 == LED off, 1 == LED on
}

// Actual LED table global variable
extern struct leddev ledtab[];



