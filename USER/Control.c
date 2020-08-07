#include "Control.h"
#include "control_app.h"
#include "encoder.h"
#include "key.h"
u8 time=0;
#define	LED PBout(0)  
u8 led_time=0;
extern u8 delay_50,delay_flag; 
extern char menu;
void TIM1_UP_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM1,TIM_IT_Update)!=RESET)
	{
		TIM_ClearITPendingBit(TIM1,TIM_FLAG_Update);
		led_time++;
		time++;
	if(led_time==50)
	{
		led_time=0;
		LED=~LED;
	}
	}
}

