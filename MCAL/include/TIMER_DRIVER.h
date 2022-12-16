/*
 * TIMERS_DRIVER.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Islam Ahmed
 */


#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

#include "COMMONS.h"
#include "STD_DATA_TYPES.h"




/*********************************  SYS TIMER BASE ADDRESSES   ************************************************/

#define  SYSTIMER_BASE   (0xE000E000)


/***********************************  SYS TIMER REGISTERS > OFFSET ADDRESSES *************************************/


#define   SYSTIMER_STCTRL_OFFSET          (0x10) 
#define   SYSTIMER_STRELOAD_OFFSET        (0x14)  
#define   SYSTIMER_STCURRENT_OFFSET       (0x18)  


#define   SYSTIMER_STCTRL_RSTVAL          (0x00000004)



#define    SYSTIMERREG_STCTRL            (*((volatile uint32*)((SYSTIMER_BASE)+(SYSTIMER_STCTRL_OFFSET))))
#define    SYSTIMERREG_STRELOAD          (*((volatile uint32*)((SYSTIMER_BASE)+(SYSTIMER_STRELOAD_OFFSET))))
#define    SYSTIMERREG_STCURRENT         (*((volatile uint32*)((SYSTIMER_BASE)+(SYSTIMER_STCURRENT_OFFSET))))
 



/*********************************  enums & typedefs **************************/

 typedef enum{
	 
	 SysTimClkSrc_PIOSCDIV4,/*0*/
	 SysTimClkSrc_SYSCLK/*1*/
	 
 }SysTimClkSrc_t;

 
 typedef enum{
	 
	 SysTimCounterState_OFF,/*0*/
	 SysTimCounterState_ON  /*1*/
 }SysTimCounterState_t;
 
 
 
  typedef enum{
	 
	 SysTimIntState_OFF,/*0*/
	 SysTimIntState_ON  /*1*/
 }SysTimIntState_t;
 
 
 typedef struct{
	 uint32 ReloadValue ;
	 uint32 CurrentValue ;
	 SysTimClkSrc_t ClkSrc ;
	 SysTimIntState_t IntState;
	 void(*CALL_BACK)(void);
	 
 } SysTimConfig_t;


 
 
 
 

 

/**************************************************  API  *********************************************/


// init & config
 void SysTim_Init(const SysTimConfig_t * timconfig);
 
 
// run time control
void   SysTim_SetCounterState(SysTimCounterState_t cs);
void   SysTim_SetIntState(SysTimIntState_t is);
uint32 SysTim_GetRelaodVal(void);
uint32 SysTim_GetCurrentVal(void);
void   SysTim_SetRelaodVal(uint32 val);
void   SysTim_SetCurrentVal(uint32 val);

 
 
 
// deinit
 void SysTim_Deinit(void);



#endif /* TIMER_DRIVER_H_ */
