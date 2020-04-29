#include <xinu.h>

static void doflash(uint32 state)
{
    vGalileoFlashLEDUsingLegacyGPIO(state);
}

static void help(void)
{
    printf("Usage:\n");
    printf("   led --help\n");
    printf("   led [-p nmsec] N\n\n");

    printf("Flashing the GP LED on the Galileo Gen2board.\n");
    printf("> N: the number of on/off cycles desired (at least 1).\n");
    printf("> -p nmsec: where 1 <= nmsec <= 10000. Default 500 msec\n");
    exit();
}

shellcmd xsh_led(int nargs, char *args[])
{
    int n, msec;

    if (nargs == 2 && strcmp(args[1],"--help") == 0)
	help();

    if (nargs != 2 && nargs != 4)
	help();

    if (nargs == 4) {
	if (strcmp(args[1],"-p") != 0)
	    help();
	msec = atoi(args[2]);
	if (msec < 1 || msec > 10000)
	    help();
	n = atoi(args[3]);
    } else {
	msec = 500;
	n = atoi(args[1]);
    }
    if (n < 1)
	help();

    /*--------------------------*/
    /* Initialize the hardware. */
    /*--------------------------*/
    vGalileoInitializeGpioController();

    vGalileoInitializeLegacyGPIO();

    vGalileoLegacyGPIOInitializationForLED();

    /*------------------*/
    /* Do the blinking. */
    /*------------------*/
    while (n > 0) {
	doflash(1);		/* illuminate the LED */
	sleepms(msec);
	doflash(0);		/* extinguish the LED */
	sleepms(msec);
	n--;
    }
    return 0;
}
