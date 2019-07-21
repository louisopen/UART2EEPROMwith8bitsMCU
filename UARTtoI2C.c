//___________________________________________________________________
//___________________________________________________________________
// Description: Main program
//   Copyright: 2019 For MK Master INC.
//   File Name: UARTtoI2C.c
//Targer Board: MK8002D 
//    MCU Body: HT66F318 28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on V10 hardware
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "HT66F318.h"
#include "common.h"
#include "Sys_Init.h"
#include "interrupt.h"
#include "eeprom.h"
#include "uart.h"
void main()
{	//like Arduino setup();
	//u8	i;
	//判斷是否是上電復位或者是正常情況下的非正常復位
	//如果成立則執行上電初始化動作，反之則執行WDT溢出初始化
	if(_to ==0 || _pdf ==0)									//WDT1	Reset
	{	//上電復位或者是正常情況下的非正常復位
		fun_RamInit();	//RAM clear all.
		fun_PowerOnInit();	//第一次上電或正常reset pin                             								
	}
	else													
	{	//WDT造成溢出復位
		fun_WDT_ResetInit();
	}
  	//main loop here like Arduino loop()
	while(1)
	{	
		//清除看門狗		//GCC_CLRWDT();
		_clrwdt();
		//用於計時
		//fun_500ms_polling();
		
		//判斷是否要進入睡眠
		/*
		if(gu8v_halt_time<LU8C_HALT_TIME)
		{

			if(_ptm2af)
			{
				//10ms 循環					
				_ptm2af = 0;
				gbv_work_polling = 0;
				sys_time();
				fun_Key_Scan();		
				fun_cal_pressure(gu16v_pressure_output);
				Sys_lower_power();	
				
				switch(gu8v_work_mode)
				{
					case	Sys_Normal_mode:
						Sys_Normal();				
					break;
					case	Sys_Power_On_mode:
						Sys_Power_On();
					break;
					case	Sys_HALT_mode:
						Sys_HALT();
					break;			
					default :
						Change_Mode(Sys_Normal_mode);
					break;	
				}
			}
			 gbv_500ms = 0;		
			 gbv_250ms = 0;		 			
		}
		else
		{
			Change_Mode(Sys_Normal_mode);
 			fun_PrepareToHalt();
		}
		*/
	}
}