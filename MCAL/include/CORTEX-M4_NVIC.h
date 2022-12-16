/*
 * NVIC.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Islam Ahmed
 */

#ifndef NVIC_H_
#define NVIC_H_

// Reset value: 0x00000000 FOR ALL REGISTERS

#include "COMMONS.h"
#include "STD_DATA_TYPES.h"


 

#define NVIC_BASE    (0xE000E000)




#define NVIC_EN_BASE   ((NVIC_BASE)+0x0100)
#define NVICREG_EN(x)  (*((volatile uint32*)((NVIC_EN_BASE)+((x)*4))))
#define NVIC_EN0       (*((volatile uint32*)((NVIC_BASE)+0x0100))) //0->31
#define NVIC_EN1       (*((volatile uint32*)((NVIC_BASE)+0x0104))) //32->63
#define NVIC_EN2       (*((volatile uint32*)((NVIC_BASE)+0x0108))) //64->95
#define NVIC_EN3       (*((volatile uint32*)((NVIC_BASE)+0x010C))) //96->127
	

 // NVICREG_EN(x/32)|=(1<<(x%32)) 



#define NVIC_DIS_BASE   ((NVIC_BASE)+0x0180)
#define NVICREG_DIS(x)  (*((volatile uint32*)((NVIC_DIS_BASE)+((x)*4))))
#define NVIC_DIS0       (*((volatile uint32*)((NVIC_BASE)+0x0180)))
#define NVIC_DIS1       (*((volatile uint32*)((NVIC_BASE)+0x0184)))
#define NVIC_DIS2       (*((volatile uint32*)((NVIC_BASE)+0x0188)))
#define NVIC_DIS3       (*((volatile uint32*)((NVIC_BASE)+0x018C)))


	

#define NVIC_PEND_BASE   ((NVIC_BASE)+0x0200)
#define NVICREG_PEND(x)  (*((volatile uint32*)((NVIC_PEND_BASE)+((x)*4))))
#define NVIC_PEND0       (*((volatile uint32*)((NVIC_BASE)+0x0200)))
#define NVIC_PEND1       (*((volatile uint32*)((NVIC_BASE)+0x0204)))
#define NVIC_PEND2       (*((volatile uint32*)((NVIC_BASE)+0x0208)))
#define NVIC_PEND3       (*((volatile uint32*)((NVIC_BASE)+0x020C)))


#define NVIC_UNPEND_BASE   ((NVIC_BASE)+0x0280)
#define NVICREG_UNPEND(x)  (*((volatile uint32*)((NVIC_UNPEND_BASE)+((x)*4))))
#define NVIC_UNPEND0       (*((volatile uint32*)((NVIC_BASE)+0x0280)))
#define NVIC_UNPEND1       (*((volatile uint32*)((NVIC_BASE)+0x0284)))
#define NVIC_UNPEND2       (*((volatile uint32*)((NVIC_BASE)+0x0288)))
#define NVIC_UNPEND3       (*((volatile uint32*)((NVIC_BASE)+0x028C)))




// these registers set should be read only
#define NVIC_ACTIVE_BASE   ((NVIC_BASE)+0x0300)
#define NVICREG_ACTIVE(x)  (*((volatile const uint32*)((NVIC_ACTIVE_BASE)+((x)*4))))
#define NVIC_ACTIVE0       (*((volatile const uint32*)((NVIC_BASE)+0x0300)))
#define NVIC_ACTIVE1       (*((volatile const uint32*)((NVIC_BASE)+0x0304)))
#define NVIC_ACTIVE2       (*((volatile const uint32*)((NVIC_BASE)+0x0308)))
#define NVIC_ACTIVE3       (*((volatile const uint32*)((NVIC_BASE)+0x030C)))



#define NVIC_SWTRIG       (*((volatile uint32*)((NVIC_BASE)+0x0F00)))



 

typedef enum{
 NVICIRQN_GPIOA,/*0*/
 NVICIRQN_GPIOB,
 NVICIRQN_GPIOC,
 NVICIRQN_GPIOD,
 NVICIRQN_GPIOE,
 NVICIRQN_GPIOF = 30 
}NVICIRQN_t;










/************************************************************ API *******************************************/






void   NVIC_ENABLE_IRQ(NVICIRQN_t irqn);
void   NVIC_DISABLE_IRQ(NVICIRQN_t irqn);

void   NVIC_SET_PENDING_IRQ(NVICIRQN_t irqn);
void   NVIC_CLR_PENDING_IRQ(NVICIRQN_t irqn); 

void   NVIC_SET_SWINT(NVICIRQN_t irqn);

uint32 NVIC_IS_ACTIVE(NVICIRQN_t irqn);




#endif /* NVIC_H_ */
