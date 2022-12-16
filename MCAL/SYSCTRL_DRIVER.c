/*
 *  SYSCTRL_DRIVER.c
 *
 *  Created on: Oct 14, 2022
 *      Author: Islam Ahmed
 */



#include "SYSCTRL.h"






void SYSCTRL_SetClk_Gpio( SYSCTRL_PERICLK_GPIOX_t gpiox, bool ClkState)
{
   if(ClkState) COMMONS_BITS_SetBit(SYSCTRLREG_RCGCGPIO,gpiox);       
   else COMMONS_BITS_ClearBit(SYSCTRLREG_RCGCGPIO,gpiox);    

}



void SYSCTRL_SetGpioBus( SYSCTRL_PERICLK_GPIOX_t gpiox, SYSCTRL_GPIOXBUS_t bus)
{
   if( SYSCTRL_GPIOXBUS_AHB == bus ) COMMONS_BITS_SetBit(SYSCTRLREG_GPIOHBCTL,gpiox);       
   else if ( SYSCTRL_GPIOXBUS_APB == bus ) COMMONS_BITS_ClearBit(SYSCTRLREG_GPIOHBCTL,gpiox); 
}





