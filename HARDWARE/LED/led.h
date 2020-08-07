#ifndef __LED_H
#define __LED_H	 

#include "sys.h"

#define ON  0
#define OFF 1
#define LED1(a) if(a) \
											GPIO_SetBits(GPIOC,GPIO_Pin_9); \
								else \
											GPIO_ResetBits(GPIOC,GPIO_Pin_9)


void LED_Init(void);//≥ı ºªØ
void Led_Test(void);
		 				    
#endif
