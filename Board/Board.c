#include "Board.h"
#include <stdint.h>
#include <stdbool.h>
// TivaWare includes
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
// FreeRTOS includes
#include "FreeRTOSConfig.h"

void Board_init(){
    // Initialize system clock to 120 MHz
    if( SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ | SYSCTL_OSC_MAIN |
        					SYSCTL_USE_PLL | SYSCTL_CFG_VCO_480),
        					SYSTEM_CLOCK) !=
		SYSTEM_CLOCK )
	{
		__error__(__FILE__,__LINE__);
	}
}

///  ASSERT() Error function
void __error__(char *pcFilename, uint32_t ui32Line)
{
    for(;;)
	{}
}
