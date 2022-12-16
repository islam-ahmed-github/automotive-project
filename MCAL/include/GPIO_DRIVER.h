/*
 *  GPIO_DRIVER.h
 *
 *  Created on: Oct 16, 2022
 *  Author: Islam Ahmed
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_


#include "COMMONS.h"
#include "STD_DATA_TYPES.h"
#include "CORTEX-M4_NVIC.h"


/*****************************************************GPIO_BASE_ADDRESSES*******************************************************/
 

#define  PORTA_APB_BASE_ADDRESS   (0x40004000)
#define  PORTA_AHB_BASE_ADDRESS   (0x40058000)
#define  PORTB_APB_BASE_ADDRESS   (0x40005000)
#define  PORTB_AHB_BASE_ADDRESS   (0x40059000)
#define  PORTC_APB_BASE_ADDRESS   (0x40006000)
#define  PORTC_AHB_BASE_ADDRESS   (0x4005A000)
#define  PORTD_APB_BASE_ADDRESS   (0x40007000)
#define  PORTD_AHB_BASE_ADDRESS   (0x4005B000)
#define  PORTE_APB_BASE_ADDRESS   (0x40024000)
#define  PORTE_AHB_BASE_ADDRESS   (0x4005C000)
#define  PORTF_APB_BASE_ADDRESS   (0x40025000)
#define  PORTF_AHB_BASE_ADDRESS   (0x4005D000)


 
//#define  PORTA_BASE_APB   PORTA_APB_BASE_ADDRESS
#define  PORTA_BASE_AHB   PORTA_AHB_BASE_ADDRESS
//#define  PORTB_BASE_APB   PORTB_APB_BASE_ADDRESS
#define  PORTB_BASE_AHB   PORTB_AHB_BASE_ADDRESS
//#define  PORTC_BASE_APB   PORTC_APB_BASE_ADDRESS
#define  PORTC_BASE_AHB   PORTC_AHB_BASE_ADDRESS
//#define  PORTD_BASE_APB  PORTD_APB_BASE_ADDRESS
#define  PORTD_BASE_AHB   PORTD_AHB_BASE_ADDRESS
//#define  PORTE_BASE_APB  PORTE_APB_BASE_ADDRESS
#define  PORTE_BASE_AHB   PORTE_AHB_BASE_ADDRESS
#define  PORTF_BASE_APB   PORTF_APB_BASE_ADDRESS
//#define  PORTF_BASE_AHB   PORTF_AHB_BASE_ADDRESS
 



/**************************************************  GPIO_OFFSET_ADDRESSES **************************************************/


#define   PORTX_GPIODEN_OFFSET           (0x051C)   /* enable digital IO, 1:enable, 0:disable */
#define   PORTX_GPIODIR_OFFSET           (0x0400)   /* set dir, 1:output, 0:input */ 
#define   PORTX_DATA_OFFSET              (0x00)     /* bit value WR*/
#define   PORTX_LOCK_OFFSET              (0x520)
#define   PORTX_COMMIT_OFFSET            (0x524)
/////// 
#define   PORTX_INTSENSE_OFFSET          (0x404) // set interrupt sense type  -->  1: levels |  0: edges
#define   PORTX_INTEDGES_OFFSET          (0x408) // set int on both edges  --> 1: enable | 0: disable
#define   PORTX_INTEVENT_OFFSET          (0x40C) // set int edge --> 1: rising- high level | 0: falling-low level
#define   PORTX_INTMASK_OFFSET           (0x410) // interrupt mask--> enable send gpio interrupt to nvic --> 1: enable | 0: disable
#define   PORTX_INTCLR_OFFSET            (0x41C) // clear interrupt flag --> 1: clear | 0: no effect
#define   PORTX_PULLUP_OFFSET            (0x510) // enable on-chip pull up resistor --> 1: enable | 0: disable
#define   PORTX_PULLDOWN_OFFSET          (0x514) // enable on-chip pull down resistor --> 1: enable | 0: disable
#define   PORTX_INTSTATUS_OFFSET         (0x418) // read int status --> 1: int trigered | 0: not trigered or masked






#define    GPIOPREG_GPIODEN(PORTBASE)      (*((volatile uint32*)((PORTBASE)+(PORTX_GPIODEN_OFFSET))))
#define    GPIOPREG_GPIODIR(PORTBASE)      (*((volatile uint32*)((PORTBASE)+(PORTX_GPIODIR_OFFSET))))
#define    GPIOPREG_COMMIT(PORTBASE)       (*((volatile uint32*)((PORTBASE)+(PORTX_COMMIT_OFFSET))))
#define    GPIOPREG_LOCK(PORTBASE)         (*((volatile uint32*)((PORTBASE)+(PORTX_LOCK_OFFSET))))	
#define    GPIOPREG_DATA(PORTBASE)         (*((volatile uint32*)((PORTBASE)+(PORTX_DATA_OFFSET))))
////// 


#define    GPIOPREG_INTSENSE(PORTBASE)     (*((volatile uint32*)((PORTBASE)+(PORTX_INTSENSE_OFFSET))))
#define    GPIOPREG_INTEDGES(PORTBASE)     (*((volatile uint32*)((PORTBASE)+(PORTX_INTEDGES_OFFSET))))
#define    GPIOPREG_INTEVENT(PORTBASE)     (*((volatile uint32*)((PORTBASE)+(PORTX_INTEVENT_OFFSET))))
#define    GPIOPREG_INTMASK(PORTBASE)      (*((volatile uint32*)((PORTBASE)+(PORTX_INTMASK_OFFSET))))
#define    GPIOPREG_INTCLR(PORTBASE)       (*((volatile uint32*)((PORTBASE)+(PORTX_INTCLR_OFFSET))))
#define    GPIOPREG_PULLUP(PORTBASE)       (*((volatile uint32*)((PORTBASE)+(PORTX_PULLUP_OFFSET))))
#define    GPIOPREG_PULLDOWN(PORTBASE)     (*((volatile uint32*)((PORTBASE)+(PORTX_PULLDOWN_OFFSET))))	
#define    GPIOPREG_INTSTATUS(PORTBASE)    (*((volatile uint32*)((PORTBASE)+(PORTX_INTSTATUS_OFFSET))))


/****************************************************** typedefs & enums ************************************************/


 
typedef enum{
	
#ifdef PORTA_BASE_APB
GPIOA = PORTA_BASE_APB,
#elifdef PORTA_BASE_AHB
GPIOA = PORTA_BASE_AHB,
#endif


#ifdef	PORTB_BASE_APB
GPIOB = PORTB_BASE_APB,
#elifdef PORTB_BASE_AHB
GPIOB = PORTB_BASE_AHB,
#endif
	
	
#ifdef	PORTC_BASE_APB
GPIOC = PORTC_BASE_APB,
#elifdef PORTC_BASE_AHB
GPIOC = PORTC_BASE_AHB,
#endif
	
	
	
#ifdef	PORTD_BASE_APB
GPIOD = PORTD_BASE_APB,
#elifdef PORTD_BASE_AHB
GPIOD = PORTD_BASE_AHB,
#endif 


#ifdef	PORTE_BASE_APB
GPIOE = PORTE_BASE_APB,
#elifdef PORTE_BASE_AHB
GPIOE = PORTE_BASE_AHB,
#endif
 
 
#ifdef PORTF_BASE_APB
GPIOF = PORTF_BASE_APB,
#elifdef PORTF_BASE_AHB
GPIOF = PORTF_BASE_AHB
#endif
	
}GPIOX_t;





typedef enum{
 GPIOPIN_0,/*0*/
 GPIOPIN_1,
 GPIOPIN_2,
 GPIOPIN_3,
 GPIOPIN_4,
 GPIOPIN_5,
 GPIOPIN_6,
 GPIOPIN_7 
}GPIOPINX_t;


  

typedef enum{
 GPIOPINDIR_IN, /*0*/
 GPIOPINDIR_OUT /*1*/
}GPIOPINDIR_t;



typedef enum{
 GPIOPIN_LEVEL_LOW, /*0*/
 GPIOPIN_LEVEL_HIGH /*1*/
}GPIOPIN_LEVEL_t;





typedef enum{
	
	  
	  GPIO_PinInternalPulling_UP,//0
	  GPIO_PinInternalPullingt_DOWN,//1
	  GPIO_PinInternalPulling_DISABLE,//2
	 
}GPIO_PinInternalPulling_t;



typedef enum{
	
	  GPIO_IntEvent_LEVELS,//0
	  GPIO_IntEvent_RISINGEDGE,//1
	  GPIO_IntEvent_FALLINGEDGE,//2
	  GPIO_IntEvent_BOTHEDGES,//3
	
}GPIO_IntEvent_t;



typedef struct{
	
	 GPIO_IntEvent_t Event;
	 GPIO_PinInternalPulling_t OnChipPulling;
	 void(*IntHandlerCallBack)(void);
	
}GPIO_PinIntConfig_t;






/****************************************************** API ****************************************************************/

void GPIO_ConfigPinInt( GPIOX_t port, GPIOPINX_t pin, const GPIO_PinIntConfig_t* IntConfig);
void GPIO_EnablePinInt( GPIOX_t port, GPIOPINX_t pin , bool enable);
uint32 GPIO_GetPinIntStatus( GPIOX_t port, GPIOPINX_t pin);
void GPIO_ClearPinIntFlag( GPIOX_t port, GPIOPINX_t pin );




void GPIO_SetCommit( GPIOX_t port, GPIOPINX_t pin , bool commit);
void GPIO_SetLock( GPIOX_t port, bool lock);


void GPIO_SetPinDIO( GPIOX_t port, GPIOPINX_t pin , bool DigitalIO);
void GPIO_SetPinDir( GPIOX_t port, GPIOPINX_t pin , GPIOPINDIR_t dir);
GPIOPIN_LEVEL_t GPIO_ReadPin( GPIOX_t port, GPIOPINX_t pin);
void GPIO_WritePin( GPIOX_t port, GPIOPINX_t pin, GPIOPIN_LEVEL_t level );
void GPIO_TogglePin( GPIOX_t port, GPIOPINX_t pin );

uint8 GPIO_MapPortAddressToIndex(uint32 address);
uint8 GPIO_MapPortAddressToBusId(uint32 address);

#endif



