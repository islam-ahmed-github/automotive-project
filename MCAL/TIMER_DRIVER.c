/*
 * TIMERS_DRIVER.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Islam Ahmed
 */


#include "TIMER_DRIVER.h"

#define NULL (0)

void SysTick_Handler(void);




 
static void(*CALL_BACK)(void)= NULL;
	

void SysTick_Handler(void)
{
	  if( NULL!= CALL_BACK)  CALL_BACK();
}

 
/////////////////////////////////////////////////////////////////////////////////////////////////////

 void SysTim_SetCounterState(SysTimCounterState_t cs)
{
	// control timer at bit 0
	 switch(cs)
	{
		case SysTimCounterState_OFF: COMMONS_BITS_ClearBit(SYSTIMERREG_STCTRL,0); break;
		case SysTimCounterState_ON:  COMMONS_BITS_SetBit(SYSTIMERREG_STCTRL,0);   break;
	} 
}




 void SysTim_SetIntState(SysTimIntState_t is)
{
	// control timer interrupt at bit 1
	 switch(is)
	{
		case SysTimIntState_OFF:  COMMONS_BITS_ClearBit(SYSTIMERREG_STCTRL,1); break;
		case SysTimIntState_ON:   COMMONS_BITS_SetBit(SYSTIMERREG_STCTRL,1);   break;
	} 
}



uint32 SysTim_GetRelaodVal()
{
	return SYSTIMERREG_STRELOAD;
}


uint32 SysTim_GetCurrentVal()
{
	return SYSTIMERREG_STCURRENT;
}


void SysTim_SetRelaodVal(uint32 val)
{
	SYSTIMERREG_STRELOAD = val;
}


void SysTim_SetCurrentVal(uint32 val)
{
	 SYSTIMERREG_STCURRENT = val;
}


 
void SysTim_Init(const SysTimConfig_t * timconfig)
{
	// set reload value
	SYSTIMERREG_STRELOAD = timconfig->ReloadValue;
	// set current value
	SYSTIMERREG_STCURRENT = timconfig->CurrentValue;
	
	// config clk src at bit 2
	switch(timconfig->ClkSrc)
	{
		case SysTimClkSrc_PIOSCDIV4:  COMMONS_BITS_ClearBit(SYSTIMERREG_STCTRL,2); break;
		case SysTimClkSrc_SYSCLK:   COMMONS_BITS_SetBit(SYSTIMERREG_STCTRL,2);   break;
	}
	
	// set ISR call back 
	if(NULL!=timconfig->CALL_BACK)  CALL_BACK= (timconfig->CALL_BACK);
	
	// config interrupt 
	SysTim_SetIntState(timconfig->IntState);

	// enable timer at bit 0
	 COMMONS_BITS_SetBit(SYSTIMERREG_STCTRL,0);
}





// deinit sys timer- assign reset values 
 void SysTim_Deinit()
{
	// reset control register
	SYSTIMERREG_STCTRL = SYSTIMER_STCTRL_RSTVAL;
	// reset call back 
	CALL_BACK= NULL;
}
/**********************************************************************************************************************************/




