#include "show.h"
#include "oled.h"
#include "common.h"
//#include <stdio.h>
extern int a1,a2,a3,a4,x,i;
/**************************************************************************
函数功能：OLED显示
入口参数：无
返回  值：无
**************************************************************************/
void oled_show(void)
{           
		 OLED_ShowString(20,00,"NYU shepard");	
     OLED_ShowString(00,12,"<->----------<->");	
	   OLED_ShowString(00,24,"LOW:");    
	   OLED_ShowString(100,24,"HZ");    
	   OLED_ShowString(00,36,"HIGH:");
	   OLED_ShowString(100,36,"HZ");   
	   OLED_ShowString(00,48,"TEL:");
//	   OLED_ShowString(48,48,"**********");
	   switch(x)
		 {
			 case 1:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,697,5,12);OLED_ShowNumber(50,36,1209,5,12);break;
			 case 2:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,697,5,12);OLED_ShowNumber(50,36,1336,5,12);break;
			 case 3:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,697,5,12);OLED_ShowNumber(50,36,1477,5,12);break;
			 case 4:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,770,5,12);OLED_ShowNumber(50,36,1209,5,12);break;
			 case 5:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,770,5,12);OLED_ShowNumber(50,36,1336,5,12);break;
			 case 6:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,770,5,12);OLED_ShowNumber(50,36,1477,5,12);break;
			 case 7:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,852,5,12);OLED_ShowNumber(50,36,1209,5,12);break;
			 case 8:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,852,5,12);OLED_ShowNumber(50,36,1336,5,12);break;
			 case 9:OLED_ShowNumber(i,48,x,1,12);OLED_ShowNumber(50,24,852,5,12);OLED_ShowNumber(50,36,1477,5,12);break;
			 case 10:OLED_ShowNumber(i,48,0,1,12);OLED_ShowNumber(50,24,941,5,12);OLED_ShowNumber(50,36,1336,5,12);break;
			 case 11:OLED_ShowString(i,48,"*");OLED_ShowNumber(50,24,941,5,12);OLED_ShowNumber(50,36,1209,5,12);break;
			 case 12:OLED_ShowString(i,48,"#");OLED_ShowNumber(50,24,941,5,12);OLED_ShowNumber(50,36,1477,5,12);break;
			 default:break;
		 }
		   OLED_Refresh_Gram();	
	}
