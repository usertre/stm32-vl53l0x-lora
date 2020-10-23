#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "key.h"
//#include "Water_Test.h"
#include "usmart.h" 
#include "malloc.h"  
///#include "MMC_SD.h" 
///#include "ff.h"  
#include "exfuns.h"
#include "fontupd.h"
#include "text.h"		
//#include "touch.h"	
#include "usart2.h"	
#include "lora_app.h"
#include "led.h"
#include "lora_ui.h"
#include "24cxx.h"
#include "vl53l0x.h"
/************************************************
 ALIENTEK MiniV3 STM32开发板扩展实验21
 ATK-VL53L0X激光测距模块 综合测试实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
   	
 int main(void)
 { 
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组2
	delay_init();	                               //延时函数初始化	  
	uart_init(115200);	                           //串口初始化为115200
	usmart_dev.init(72);                           //初始化USMART	
	LED_Init();		  	                           //初始化与LED连接的硬件接口
	//LCD_Init();	                                   //LCD初始化
	KEY_Init();			                           //按键初始化		 	
	AT24CXX_Init();		                           //IIC初始化 
	 
	 LoRa_Init();///////////////(1) 2020/10/22/14:57  OK    start slowly
	 Menu_cfg(21);								//参数配置   2020/10/22/15:03  OK    start slowly
DATA:	 ///////////2020/10/22 15:51
	 LoRa_Set();									//LoRa配置(进入配置需设置串口波特率为115200)          2020/10/22 15:06   OK   start slowly
	 Dire_Set();//进入设置目标地址和信道	     2020/10/22 15:09      OK  start slowly
	//POINT_COLOR=RED;                               //设置字体为红色 
	/*LCD_ShowString(30,50,200,16,16,"Mini STM32");	
	LCD_ShowString(30,70,200,16,16,"Sensor VL53L0X TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2017/6/25");	    
	POINT_COLOR=BLUE;//设置字体为蓝色*/
	printf("Mini STM32");//
	printf("Sensor VL53L0X TEST");//
	 printf("ATOM@ALIENTEK");//
	 printf("2020/10/11");//
	 //written by wps
	while(AT24CXX_Check())//检测不到24c02
	{
		//LCD_ShowString(30,150,200,16,16,"24C02 Check Failed!");
		printf("24C02 Check Failed!");//
		delay_ms(500);
		//LCD_ShowString(30,150,200,16,16,"Please Check!      ");
		printf("Please Check!");
		delay_ms(500);
		LED0=!LED0;//DS0闪烁
	}
	while(1)
	{
		vl53l0x_test();//vl53l0x测试
	}
}
