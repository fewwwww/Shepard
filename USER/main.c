#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stm32f10x.h"	    				
#include "usart.h"		  					
#include "delay.h"						
#include "led.h"
#include "beep.h"
#include "common.h"
#include "oled.h"
#include "show.h"
#include "MT8870.h"
uint8 redata[500];
int a1,a2,a3,a4,x,i=48,h=0;
/**********************************************************************************/
/********************************������********************************************/
int main(void)
{   		
	LED_Init();	
	Beep_Init();
	Uart_Init(1);
	OLED_Init();   //=====OLED��ʼ��	
	MT8870_Init(); //MT8870�ӿڳ�ʼ��
	USART_Config(USART1,115200);  
	Led_Test();    //LED�Ʋ���
	Beep_Test();   //����������
	while (1)
	{
     if(PAin(4)==1)  a1=1;
	   else            a1=0;
	   if(PAin(5)==1)  a2=1;   
	   else            a2=0;
	   if(PAin(6)==1)  a3=1;
	   else            a3=0;
	   if(PAin(7)==1)  a4=1;   
	   else            a4=0;
		 x=a4*8+a3*4+a2*2+a1*1;
     if(PCin(4)==1)  
		 {
			 i=i+8;
			 h=1;
			 GPIO_SetBits(GPIOB,GPIO_Pin_11);//������ɫLED��
       Delay_ms(200);//��ʱ200ms
			 GPIO_ResetBits(GPIOB,GPIO_Pin_11);//Ϩ����ɫLED��
		   BEEP(OFF);
			 Delay_ms(80);
			 switch(x)
		 {
			 case 1:printf("%d",x);break;
			 case 2:printf("%d",x);break;
			 case 3:printf("%d",x);break;
			 case 4:printf("%d",x);break;
			 case 5:printf("%d",x);break;
			 case 6:printf("%d",x);break;
			 case 7:printf("%d",x);break;
			 case 8:printf("%d",x);break;
			 case 9:printf("%d",x);break;
			 case 10:printf("%d",0);break;
			 case 11:printf("%c",'*');break;
			 case 12:printf("%c\n",'#');break;
			 default:break;
		 }
		 }
		 if(i<=120&&x!=12)
		 {
			 oled_show();//===��ʾ��������ʾ
		 }
		 else
		 {
			 if(h==1)
			 Alarm();//���볬����Χ����
			 OLED_ShowString(48,48,"**********");
			 OLED_Refresh_Gram();
			 if(i>120) i=48;
			 else i=40;
		 }
		 Delay_ms(50);
	}
} 




