
/*
 *  SWITCH_DRIVER.h
 *
 *  Created on: Oct 24, 2022
 *      Author: Islam Ahmed
 */
 
 
#include "SYSCTRL.h"
#include "GPIO_DRIVER.h"


// Switch_Active_Mode depends on switch physical connection 
typedef enum
{
  SwitchActiveMode_LOW, //0 with gpio pin pulled up at the idle state
	SwitchActiveMode_HIGH //1 with gpio pin pulled down at the idle state
}SwitchActiveMode_t;


  
typedef struct
{
	GPIOX_t     portx;
	GPIOPINX_t  pinx;
	SwitchActiveMode_t  activemode;
}Switch_t;


 
/*********************************************************** API *****************************************************/
void Switch_Init(const Switch_t* sw);
void Switch_ConfigInterrupt(const Switch_t* sw  ,  const GPIO_PinIntConfig_t* swint);




