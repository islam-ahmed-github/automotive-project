
/*
 * LED_DRIVER.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Islam Ahmed
 */
 
 
#include "SYSCTRL.h"
#include "GPIO_DRIVER.h"



typedef enum
{
  LedActiveMode_LOW, //0
	LedActiveMode_HIGH //1
	
}LedActiveMode_t;



typedef enum
{
  LedState_OFF, //0
	LedState_ON //1
	
}LedState_t;

 
typedef struct
{
	GPIOX_t    portx;
	GPIOPINX_t pinx;
	LedActiveMode_t activemode;
	
}Led_t;


/*********************************************************** API *****************************************************/
void Led_Init(const Led_t* led);
void Led_On(const Led_t* led);
void Led_Off(const Led_t* led);
void Led_Toggle(const Led_t* led);
LedState_t Led_GetState(const Led_t* led);


