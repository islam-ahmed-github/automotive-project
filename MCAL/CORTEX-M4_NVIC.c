/*
 * NVIC.c
 *
 *  Created on: Oct 18, 2022
 *      Author: Islam Ahmed
 */

#include "CORTEX-M4_NVIC.h"


  // irqn/32  = register index relative to group base { EN, DIS, PEND,....}
	// irqn%32  = bit index
  // NVICREG_EN(x/32)|= (1<<(x%32)) 
 
 
void NVIC_ENABLE_IRQ(NVICIRQN_t  irqn) 
{
 
	COMMONS_BITS_SetBit( NVICREG_EN(((uint32)irqn)/32), (((uint32)irqn)%32) );
}



void NVIC_DISABLE_IRQ(NVICIRQN_t irqn)
{
  COMMONS_BITS_SetBit( NVICREG_DIS(((uint32)irqn)/32), (((uint32)irqn)%32) );
}



void NVIC_SET_PENDING_IRQ(NVICIRQN_t irqn) 
{
	  COMMONS_BITS_SetBit( NVICREG_PEND(((uint32)irqn)/32), (((uint32)irqn)%32) );
}



void NVIC_CLR_PENDING_IRQ(NVICIRQN_t irqn) 
{
   COMMONS_BITS_SetBit( NVICREG_UNPEND(((uint32)irqn)/32), (((uint32)irqn)%32) );
}



uint32 NVIC_IS_ACTIVE(NVICIRQN_t irqn) 
{
   return COMMONS_BITS_ReadBit( NVICREG_ACTIVE(((uint32)irqn)/32), (((uint32)irqn)%32) );
}





void NVIC_SET_SWINT(NVICIRQN_t irqn) 
{
    NVIC_SWTRIG = ((uint32)irqn);
}

