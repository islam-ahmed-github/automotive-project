


/*
 * LED_DRIVER.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Islam Ahmed
 */


#include "include/Led_Driver.h"

 


void Led_Init(const Led_t* led)
{
	uint8 portindex =0;
	// map port to index to suit SYSCTRL driver functions args
	portindex = GPIO_MapPortAddressToIndex((uint32)(led->portx));
	// enable clock on led gpio port 
	SYSCTRL_SetClk_Gpio( portindex, 1 );
	// enable selected bus for the input port
  SYSCTRL_SetGpioBus(  portindex , GPIO_MapPortAddressToBusId((uint32)(led->portx)) );
	// set led pin as digital I/O
	
	 GPIO_SetLock( led->portx, 0);	
   GPIO_SetCommit( led->portx, led->pinx , 1);
	
  GPIO_SetPinDIO( led->portx,  led->pinx , 1);
	// set led pin direction as output
  GPIO_SetPinDir( led->portx, led->pinx  , GPIOPINDIR_OUT);
	// set initial state to low
  Led_Off(led);
}


void Led_On(const Led_t* led)
{
	switch(led->activemode)
	{
		case LedActiveMode_LOW:  COMMONS_BITS_ClearBit(GPIOPREG_DATA(led->portx),led->pinx); break;
		case LedActiveMode_HIGH: COMMONS_BITS_SetBit(GPIOPREG_DATA(led->portx),led->pinx); break;
	}
}




void Led_Off(const Led_t* led)
{
	switch(led->activemode)
	{
		case LedActiveMode_LOW:  COMMONS_BITS_SetBit(GPIOPREG_DATA(led->portx),led->pinx); break;
		case LedActiveMode_HIGH: COMMONS_BITS_ClearBit(GPIOPREG_DATA(led->portx),led->pinx); break;
	}
}



void Led_Toggle(const Led_t* led)
{
	COMMONS_BITS_ToggleBit( GPIOPREG_DATA(led->portx), led->pinx );
}



LedState_t Led_GetState(const Led_t* led)
{
	uint32 value = COMMONS_BITS_ReadBit(GPIOPREG_DATA(led->portx),led->pinx);
	if(( (0==value)&&(LedActiveMode_LOW==led->activemode)) || ((value)&&(LedActiveMode_HIGH==led->activemode)))
	{
		return LedState_ON;
	}
	else
	{
		return LedState_OFF;
	}
 
}



