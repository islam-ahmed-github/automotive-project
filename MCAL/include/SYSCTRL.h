/*
 *  SYSCTRL.h
 *
 *  Created on: Oct 17, 2022
 *  Author: Islam Ahmed
 */

#ifndef SYSCTRL_H_
#define SYSCTRL_H_

#include "COMMONS.h"
#include "STD_DATA_TYPES.h"

/*************************************************** SYSCTRL-REGISTERS BASE/OFFSET ADDRESSE ***************************************/

#define   SYSCTRL_BASE               (0x400FE000)

#define   SYSCTRL_RCC_OFFSET          (0x60)
#define   SYSCTRL_RCC2_OFFSET         (0x70)
#define   SYSCTRL_RCGCGPIO_OFFSET     (0x0608)
#define   SYSCTRL_GPIOHBCTL_OFFSET    (0x6C)

 


/************************************************** SYSCTRL-REGISTERS OFFSET ADDRESSES  ********************************/

#define    SYSCTRLREG_RCC              (*((volatile uint32*)((SYSCTRL_BASE)+(SYSCTRL_RCC_OFFSET))))
#define    SYSCTRLREG_RCC2             (*((volatile uint32*)((SYSCTRL_BASE)+(SYSCTRL_RCC2_OFFSET))))
#define    SYSCTRLREG_RCGCGPIO         (*((volatile uint32*)((SYSCTRL_BASE)+(SYSCTRL_RCGCGPIO_OFFSET))))
#define    SYSCTRLREG_GPIOHBCTL        (*((volatile uint32*)((SYSCTRL_BASE)+(SYSCTRL_GPIOHBCTL_OFFSET))))

/***********************************************  enums & typedefs **********************************/

  
typedef enum{
	SYSCTRL_PERICLK_GPIOA,   /* default = 0 */
	SYSCTRL_PERICLK_GPIOB,   /* default = 1 */
	SYSCTRL_PERICLK_GPIOC,
	SYSCTRL_PERICLK_GPIOD,
	SYSCTRL_PERICLK_GPIOE,
	SYSCTRL_PERICLK_GPIOF    /* default = 5 */
} SYSCTRL_PERICLK_GPIOX_t;



typedef enum{
	SYSCTRL_GPIOXBUS_APB,   /* default = 0 */
	SYSCTRL_GPIOXBUS_AHB    /* default = 1 */
} SYSCTRL_GPIOXBUS_t;


/******************************************************************************************************************************/



/************************************************ This API Functions Declarations *********************************************************/


void SYSCTRL_SetClk_Gpio( SYSCTRL_PERICLK_GPIOX_t gpiox , bool ClkState);
void SYSCTRL_SetGpioBus(  SYSCTRL_PERICLK_GPIOX_t gpiox, SYSCTRL_GPIOXBUS_t bus);


#endif /* SYSCTRL_H_ */

