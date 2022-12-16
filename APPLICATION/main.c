
/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: Islam Ahmed
 */
 
#define MCUCLK (16000000)

#include "TIMER_DRIVER.h"
#include "Led_Driver.h"
#include "Switch_Driver.h"


//PORTF_APB_BASE_ADDRESS   (0x40025000)
//PORTF_AHB_BASE_ADDRESS   (0x4005D000)
 
 

//functions declaration
void Init_PWM_SW_StepUp(void);
void Init_PWM_SW_StepDown(void);
void Init_Timer(void);
void Init_Led(void);
void Init_SW(void);
void PWM_StepUpDutyCycle_CALLBACK(void);
void PWM_StepDownDutyCycle_CALLBACK(void);
void Led_Control_CallBack(void);

 
 
// create led & switches instances
static Led_t MyLed;
static Switch_t MySwStepUpDutyCycle;
static Switch_t MySwStepDownDutyCycle;
 
 

// timing parameters
//static volatile float  PWM_FreqHz = 1/5; 
static volatile uint32 PWM_PeriodSec = 5;
static volatile uint32 PWM_toff=1;
static volatile uint32 PWM_ton=4;


static volatile LedState_t ledstate = LedState_OFF;


int main(void)
{

	
	 Init_PWM_SW_StepUp();
	 Init_PWM_SW_StepDown();
   Init_Led();
   Init_Timer();
 
   while(1)
   {
      
   }
	
  return 0;
}





void Led_Control_CallBack()
{
	 static uint32 SecCnt;
   SecCnt++;
	 switch(ledstate)
	 {
	  case LedState_OFF:
		{
			if(SecCnt>=PWM_toff && (PWM_ton>0) )
			{
				SecCnt=0; 
				Led_On(&MyLed);  
				ledstate = LedState_ON;
			}	
			break;
		} // end case LedState_OFF
		
	  case LedState_ON:
		{
		   if(SecCnt>=PWM_ton  && (PWM_toff>0) )
			{
				SecCnt=0;
				Led_Off(&MyLed);
				ledstate = LedState_OFF;
			}		
			break;
		}// end case LedState_ON
	 }//end switch
}// end func





void PWM_StepUpDutyCycle_CALLBACK(void)
{
	
	if(PWM_ton==PWM_PeriodSec) return;
	else
	{
		PWM_ton++;
    PWM_toff--;
	}

}// end func




void PWM_StepDownDutyCycle_CALLBACK(void)
{
 	if(0==PWM_ton) return;
	else
	{
    PWM_toff++;
    PWM_ton--;
	}
}// end func



void Init_Timer()
{
	  // timer config instance
	  SysTimConfig_t MyTimer;
	  //init reload&current values with ((time*clock)-1) where time= 1 sec, and clock = sys-clk = 16000000Hz 
	  MyTimer.ReloadValue= (MCUCLK-1);
	  MyTimer.CurrentValue= (MCUCLK-1);
	  // set timer clock to sys clk
	  MyTimer.ClkSrc = SysTimClkSrc_SYSCLK;
	  // enable timer interrupt
	  MyTimer.IntState = SysTimIntState_ON;
	  //set timer callback func 
	  MyTimer.CALL_BACK = Led_Control_CallBack;
	  //start timer
	  SysTim_Init(&MyTimer); 
}







void Init_Led()
{
	//assign led to port F 
    MyLed.portx = GPIOA;
	//assign led to pin 2 at port F
    MyLed.pinx  =	GPIOPIN_2;
	 // set pin connection as active high 
 	  MyLed.activemode = LedActiveMode_HIGH;
	  // init led 
    Led_Init(&MyLed);
}




void Init_PWM_SW_StepUp()
{
	  GPIO_PinIntConfig_t sic;
	 //assign sw to port F 
    MySwStepUpDutyCycle.portx = GPIOF;
 	 //assign sw to pin 0 
    MySwStepUpDutyCycle.pinx  =	GPIOPIN_4;
	 // set sw as active low --> pin is pulled up and idle state is high
 	  MySwStepUpDutyCycle.activemode = SwitchActiveMode_LOW;
	  // init sw gpio
    Switch_Init(&MySwStepUpDutyCycle);
	  // as idle is high, on depression a falling edge will be detected 
	  sic.Event=GPIO_IntEvent_FALLINGEDGE;
	  sic.OnChipPulling = GPIO_PinInternalPulling_UP;
	  sic.IntHandlerCallBack = PWM_StepUpDutyCycle_CALLBACK;
	  // init sw int
    Switch_ConfigInterrupt(&MySwStepUpDutyCycle,&sic);
}




void Init_PWM_SW_StepDown()
{
	  GPIO_PinIntConfig_t sic;
	
	 //assign sw to port F 
    MySwStepDownDutyCycle.portx = GPIOF;
 	 //assign sw to pin 4
    MySwStepDownDutyCycle.pinx  =	GPIOPIN_0;
	 // set sw as active low --> pin is pulled up and idle state is high
 	  MySwStepDownDutyCycle.activemode = SwitchActiveMode_LOW;
	  // init sw gpio
    Switch_Init(&MySwStepDownDutyCycle);
	

	  // as idle is high, on depression a falling edge will be detected 
	  sic.Event=GPIO_IntEvent_FALLINGEDGE;
	  sic.OnChipPulling = GPIO_PinInternalPulling_UP;
	  sic.IntHandlerCallBack = PWM_StepDownDutyCycle_CALLBACK;
	   
	// init sw int
    Switch_ConfigInterrupt(&MySwStepDownDutyCycle,&sic);
}




