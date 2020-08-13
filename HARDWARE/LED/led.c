#include "led.h"
#include "delay.h"


//��ʼ��PA0��PA1Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//ʹ��PORTCʱ��
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //����Ϊ�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC	
	GPIO_SetBits(GPIOC,GPIO_Pin_9);				 //PC9 �����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTBʱ��
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_11; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //����Ϊ�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOB	
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);				 //PB8 �����
	GPIO_ResetBits(GPIOB,GPIO_Pin_9);				 //PB9 �����
	GPIO_ResetBits(GPIOB,GPIO_Pin_11);				 //PC8 �����
}
 
void Led_Test(void)
{
		LED1(ON);
	  Delay_ms(500);
	  LED1(OFF);
	  Delay_ms(500);
		LED1(ON);
	  Delay_ms(500);
		LED1(OFF);
	  Delay_ms(500);
	 
}
