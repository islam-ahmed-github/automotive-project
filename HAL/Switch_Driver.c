


/*
 *   SWITCH_DRIVER.c
 *
 *  Created on: Oct 24, 2022
 *      Author: Islam Ahmed
 */


#include "include/Switch_Driver.h"

 


void Switch_Init(const Switch_t* sw )
{
	uint8 portindex =0;
	// map port to index to suit SYSCTRL driver functions args
	portindex = GPIO_MapPortAddressToIndex((uint32)(sw->portx));
	// enable clock on led gpio port 
	SYSCTRL_SetClk_Gpio( portindex, 1 );
	// enable selected bus for the input port
  SYSCTRL_SetGpioBus(  portindex , GPIO_MapPortAddressToBusId((uint32)(sw->portx)) );
	
	
   GPIO_SetLock( sw->portx, 0);	
   GPIO_SetCommit( sw->portx, sw->pinx , 1);

	// set sw pin as digital I/O
  GPIO_SetPinDIO( sw->portx,  sw->pinx , 1);
	
	// set sw pin direction as input
  GPIO_SetPinDir( sw->portx, sw->pinx  , GPIOPINDIR_IN);	
	
	
}




void Switch_ConfigInterrupt(const Switch_t* sw , const GPIO_PinIntConfig_t*   swint)
{
	 GPIO_ConfigPinInt(sw->portx, sw->pinx , swint);
	
}


 


