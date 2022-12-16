/*
 *  GPIO_DRIVER.c
 *
 *  Created on: August 25, 2020
 *      Author: Islam Ahmed
 */



#include "GPIO_DRIVER.h"
 



/**********************************************************************************************************/


#define NULL (0)



void GPIOF_Handler(void);

 
// array of pointer to func that takes void and return void, this array will hold the handlers for individual pins in the same port (f)
static void (*GPIOF_CALLBACKS[5])(void) = {NULL, NULL, NULL,NULL,NULL};


// port f handler
void GPIOF_Handler(void)
{
	  
	  // pin 0
	  if(COMMONS_BITS_ReadBit(GPIOPREG_INTSTATUS(GPIOF),0))
		{
         if( NULL!= GPIOF_CALLBACKS[0]) GPIOF_CALLBACKS[0]();
			   GPIO_ClearPinIntFlag(GPIOF,0);
			   
		}
		 // pin 1
	  if(COMMONS_BITS_ReadBit(GPIOPREG_INTSTATUS(GPIOF),1))
		{
         if( NULL!= GPIOF_CALLBACKS[1])  GPIOF_CALLBACKS[1]();
			    GPIO_ClearPinIntFlag(GPIOF,1);
			   
		}
		 // pin 2
	  if(COMMONS_BITS_ReadBit(GPIOPREG_INTSTATUS(GPIOF),2))
		{
         if( NULL!= GPIOF_CALLBACKS[2])  GPIOF_CALLBACKS[2](); 
			   GPIO_ClearPinIntFlag(GPIOF,2);
		}
		
		 // pin 3
	  if(COMMONS_BITS_ReadBit(GPIOPREG_INTSTATUS(GPIOF),3))
		{
         if( NULL!= GPIOF_CALLBACKS[3])  GPIOF_CALLBACKS[3](); 
			   GPIO_ClearPinIntFlag(GPIOF,3);
		}
		
		 // pin 4
	  if(COMMONS_BITS_ReadBit(GPIOPREG_INTSTATUS(GPIOF),4))
		{
         if( NULL!= GPIOF_CALLBACKS[4])  GPIOF_CALLBACKS[4](); 
			   GPIO_ClearPinIntFlag(GPIOF,4);
		}
}




void GPIO_ConfigPinInt( GPIOX_t port, GPIOPINX_t pin ,const GPIO_PinIntConfig_t* IntConfig)
{

		// 1- disable Int to prevent false interrupts 
  	COMMONS_BITS_ClearBit(GPIOPREG_INTMASK(port),pin); 
	
	  //2- reset everything
	  COMMONS_BITS_ClearBit(GPIOPREG_INTEDGES(port),pin); 
	  COMMONS_BITS_ClearBit(GPIOPREG_INTSENSE(port) , pin);
	  COMMONS_BITS_ClearBit(GPIOPREG_PULLUP(port),pin);
	  COMMONS_BITS_ClearBit(GPIOPREG_PULLDOWN(port),pin);
	  COMMONS_BITS_ClearBit(GPIOPREG_INTCLR(port),pin);
 
   //3-  config
   if(GPIO_IntEvent_LEVELS==IntConfig->Event) // levels
		{
			 // set interrupt sense type  -->  1:levels | 0:edges
				 COMMONS_BITS_SetBit(GPIOPREG_INTSENSE(port) , pin); 
		}
		else //edges	
		{		 
			  //set interrupt sense type  -->  1:levels | 0:edges
				 COMMONS_BITS_ClearBit(GPIOPREG_INTSENSE(port) , pin); 
			
				switch(IntConfig->Event)
	      {
				 case GPIO_IntEvent_LEVELS:break;//will not happen but for a compiler warning
				 case GPIO_IntEvent_RISINGEDGE:
					{
							// set int edge --> 1:rising-high level | 0:falling-low level
						 COMMONS_BITS_SetBit(GPIOPREG_INTEVENT(port),pin); 
						 break;				
					}			 
				 case GPIO_IntEvent_FALLINGEDGE:
					{
							// set int edge --> 1:rising-high level | 0:falling-low level
						 COMMONS_BITS_ClearBit(GPIOPREG_INTEVENT(port),pin);
						 break;
					}
				 case GPIO_IntEvent_BOTHEDGES:
					{
						// set int on both edges  --> 1:enable | 0:disable	
						COMMONS_BITS_SetBit(GPIOPREG_INTEDGES(port),pin); 
						break;
					}
	      }// end switch
		}// end else
			 

		// config on chip pull up
	 switch(IntConfig->OnChipPulling)
		{
			// enable on-chip pull up resistor --> 1:enable | 0:disable
      case GPIO_PinInternalPulling_UP:  COMMONS_BITS_SetBit(GPIOPREG_PULLUP(port),pin); break; 
			// enable on-chip pull down resistor --> 1:enable | 0:disable	
			case GPIO_PinInternalPullingt_DOWN: COMMONS_BITS_SetBit(GPIOPREG_PULLDOWN(port),pin); break; 
			case GPIO_PinInternalPulling_DISABLE:break;
		}
	
		
		
    //4- set callback
		switch((uint32)port) // cast for warning
		{
			// select port & pin --> pin is the index of handlers array, passed as argument to this function
      case GPIOF: GPIOF_CALLBACKS[(uint8)pin] = IntConfig->IntHandlerCallBack; break;
			// case other ports........
		}
		

	// 5- re-enable Int on GPIO module	
	COMMONS_BITS_SetBit(GPIOPREG_INTMASK(port),pin); 
		
	// 6- enable GPIO port nvic irqn	
		switch(port)
			{
			  case GPIOF: 
           {
					   NVIC_ENABLE_IRQ(NVICIRQN_GPIOF);
						 break;
					 }	
				// to add other ports here
			}
	 
    
}




void GPIO_EnablePinInt( GPIOX_t port, GPIOPINX_t pin , bool enable)
{

  if(enable)
	{
		 COMMONS_BITS_SetBit(GPIOPREG_INTMASK(port),pin); 
	}
	else
  {
	  COMMONS_BITS_ClearBit(GPIOPREG_INTMASK(port),pin);  
	}
}



uint32 GPIO_GetPinIntStatus( GPIOX_t port, GPIOPINX_t pin)
{
   return COMMONS_BITS_ReadBit(GPIOPREG_INTSTATUS(port),pin); 
}



void GPIO_ClearPinIntFlag( GPIOX_t port, GPIOPINX_t pin )
{
	COMMONS_BITS_SetBit(GPIOPREG_INTCLR(port),pin);   
}
















void GPIO_SetLock( GPIOX_t port, bool lock)
{
	
 if(lock)
 {
	  GPIOPREG_LOCK(port)=0;
 }
 else
 {
	  GPIOPREG_LOCK(port)=0x4C4F434B;
 }
	
}




void GPIO_SetCommit( GPIOX_t port, GPIOPINX_t pin , bool commit)
{
	
 if(commit)
 {
	  COMMONS_BITS_SetBit( GPIOPREG_COMMIT(port), pin);
 }
 else
 {
	  COMMONS_BITS_ClearBit( GPIOPREG_COMMIT(port), pin);
 }
	
}



void GPIO_SetPinDIO( GPIOX_t port, GPIOPINX_t pin , bool DigitalIO)
{
	
 if(DigitalIO)
 {
	  COMMONS_BITS_SetBit( GPIOPREG_GPIODEN(port), pin);
 }
 else
 {
	  COMMONS_BITS_ClearBit( GPIOPREG_GPIODEN(port), pin);
 }
	
}



void GPIO_SetPinDir( GPIOX_t port, GPIOPINX_t pin , GPIOPINDIR_t dir)
{
	
 if(GPIOPINDIR_IN==dir) 
 {
	 COMMONS_BITS_ClearBit( GPIOPREG_GPIODIR(port), pin); 
 }
 else 
 {
	  COMMONS_BITS_SetBit( GPIOPREG_GPIODIR(port), pin);
 }
	
}




GPIOPIN_LEVEL_t GPIO_ReadPin( GPIOX_t port, GPIOPINX_t pin)
{
	
	  if(COMMONS_BITS_ReadBit(GPIOPREG_DATA(port), pin))
		{
			return GPIOPIN_LEVEL_HIGH;
		}
		else
    {
			return GPIOPIN_LEVEL_LOW;
		}

}



void GPIO_WritePin( GPIOX_t port, GPIOPINX_t pin, GPIOPIN_LEVEL_t level )
{
	
	  if(GPIOPIN_LEVEL_LOW == level) 
		{
			 COMMONS_BITS_ClearBit( GPIOPREG_DATA(port), pin);
		}
		else
    {
			 COMMONS_BITS_SetBit( GPIOPREG_DATA(port), pin); 
		}

}

 

void GPIO_TogglePin( GPIOX_t port, GPIOPINX_t pin )
{
	 COMMONS_BITS_ToggleBit( GPIOPREG_DATA(port), pin);
}

/*********************************************************************************************************************/


// adapter function to map a port address to port index: {A,...,F} -> {0,...,5} to suit other functions args in other drivers
uint8 GPIO_MapPortAddressToIndex(uint32 address)
{
   switch(address)
	{
		case  PORTA_APB_BASE_ADDRESS: return 0;
		case  PORTA_AHB_BASE_ADDRESS: return 0;
		case  PORTB_APB_BASE_ADDRESS: return 1;
		case  PORTB_AHB_BASE_ADDRESS: return 1;
		case  PORTC_APB_BASE_ADDRESS: return 2;
		case  PORTC_AHB_BASE_ADDRESS: return 2;
		case  PORTD_APB_BASE_ADDRESS: return 3;
		case  PORTD_AHB_BASE_ADDRESS: return 3;
		case  PORTE_APB_BASE_ADDRESS: return 4;
		case  PORTE_AHB_BASE_ADDRESS: return 4;
		case  PORTF_APB_BASE_ADDRESS: return 5;
		case  PORTF_AHB_BASE_ADDRESS: return 5; 
	}
	
	return 255;
}




// adapter function to map a port address to a bus: 0-> APB and 1-> AHB, to suit other functions args in other drivers
uint8 GPIO_MapPortAddressToBusId(uint32 address)
{
   switch(address)
	{
		case  PORTA_APB_BASE_ADDRESS: return 0;
		case  PORTA_AHB_BASE_ADDRESS: return 1;
		case  PORTB_APB_BASE_ADDRESS: return 0;
		case  PORTB_AHB_BASE_ADDRESS: return 1;
		case  PORTC_APB_BASE_ADDRESS: return 0;
		case  PORTC_AHB_BASE_ADDRESS: return 1;
		case  PORTD_APB_BASE_ADDRESS: return 0;
		case  PORTD_AHB_BASE_ADDRESS: return 1;
		case  PORTE_APB_BASE_ADDRESS: return 0;
		case  PORTE_AHB_BASE_ADDRESS: return 1;
		case  PORTF_APB_BASE_ADDRESS: return 0;
		case  PORTF_AHB_BASE_ADDRESS: return 1;
	}
	
	return 255;
}



