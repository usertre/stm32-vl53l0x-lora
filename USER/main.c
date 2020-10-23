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
 ALIENTEK MiniV3 STM32��������չʵ��21
 ATK-VL53L0X������ģ�� �ۺϲ���ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
   	
 int main(void)
 { 
	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����2
	delay_init();	                               //��ʱ������ʼ��	  
	uart_init(115200);	                           //���ڳ�ʼ��Ϊ115200
	usmart_dev.init(72);                           //��ʼ��USMART	
	LED_Init();		  	                           //��ʼ����LED���ӵ�Ӳ���ӿ�
	//LCD_Init();	                                   //LCD��ʼ��
	KEY_Init();			                           //������ʼ��		 	
	AT24CXX_Init();		                           //IIC��ʼ�� 
	 
	 LoRa_Init();///////////////(1) 2020/10/22/14:57  OK    start slowly
	 Menu_cfg(21);								//��������   2020/10/22/15:03  OK    start slowly
DATA:	 ///////////2020/10/22 15:51
	 LoRa_Set();									//LoRa����(�������������ô��ڲ�����Ϊ115200)          2020/10/22 15:06   OK   start slowly
	 Dire_Set();//��������Ŀ���ַ���ŵ�	     2020/10/22 15:09      OK  start slowly
	//POINT_COLOR=RED;                               //��������Ϊ��ɫ 
	/*LCD_ShowString(30,50,200,16,16,"Mini STM32");	
	LCD_ShowString(30,70,200,16,16,"Sensor VL53L0X TEST");	
	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(30,110,200,16,16,"2017/6/25");	    
	POINT_COLOR=BLUE;//��������Ϊ��ɫ*/
	printf("Mini STM32");//
	printf("Sensor VL53L0X TEST");//
	 printf("ATOM@ALIENTEK");//
	 printf("2020/10/11");//
	 //written by wps
	while(AT24CXX_Check())//��ⲻ��24c02
	{
		//LCD_ShowString(30,150,200,16,16,"24C02 Check Failed!");
		printf("24C02 Check Failed!");//
		delay_ms(500);
		//LCD_ShowString(30,150,200,16,16,"Please Check!      ");
		printf("Please Check!");
		delay_ms(500);
		LED0=!LED0;//DS0��˸
	}
	while(1)
	{
		vl53l0x_test();//vl53l0x����
	}
}
