#ifndef __BEEP_H__
#define __BEEP_H__
#include "sys.h"

#define ON  0
#define OFF 1
#define BEEP(a) if(a) \
											GPIO_SetBits(GPIOA,GPIO_Pin_3); \
								else \
											GPIO_ResetBits(GPIOA,GPIO_Pin_3)
								
#define	Beep PAout(3)  //Ñ¡ÖÐFLASH										

void Beep_Init(void);
void Beep_Test(void);
void Alarm(void);
void N_Beep(char n);
#endif
