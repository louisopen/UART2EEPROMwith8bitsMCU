//___________________________________________________________________
//___________________________________________________________________
// Description: 系統初始化相關程序
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: Sys_Init.c
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"


//___________________________________________________________________
//Function: Time base timer task process
//   INPUT: 
//	  NOTE:
//___________________________________________________________________
volatile unsigned char  count_2sec;
volatile __byte_type	system_flag;
void Task_500ms()
{	//TimeBase0
	if(TB0_int_flag==0) return;
	count_2sec++;
	if(count_2sec < 4) return;
	count_2sec=0;
	if(toggle_buzzer==0)
	{
		toggle_buzzer=1;
		_pb2=1;
	}
	else
	{
		toggle_buzzer=0;
		_pb2=0;
	}
}
//___________________________________________________________________
//Function: Key scan process
//   INPUT: 
//	  NOTE: 
//___________________________________________________________________
void Key_Scan()
{
	//GCC_NOP();
	_nop();
	
	
}	
//___________________________________________________________________
//Function: MCU WDT復位初始化
//   INPUT: 
//  OUTPUT: 
//	  NOTE: 
//___________________________________________________________________
void WDT_ResetInit()	//WDT 溢出復位
{
	GPIO_Init();
 	Uart_Init();	
	//Enable_ADC();
		
 	//TimeBase
	TimeBaseInitial();

	//Timer0 Control off	
	_tm0c0 = TM0C0_Default;
	_tm0c1 = TM0C1_Default;
	_tm0al = TM0AL_Default;	
	_tm0ah = TM0AH_Default;
	_tm0rp = TM0RP_Default;		//有8bit ht66f318, 16bit ht66f317
	//Timer1 Control off
	_tm1c0 = TM1C0_Default;
	_tm1c1 = TM1C1_Default;
	_tm1al = TM1AL_Default;	
	_tm1ah = TM1AH_Default;
	_tm1rpl = TM1RPL_Default;	//有10bit f317/f318
	_tm1rph = TM1RPH_Default;	//有10bit f317/f318
	//Timer2 Control off
	//_tm2rp = TM2RP_Default;	//有8bit only for ht66f318		
  	_nop();
  	//_pgc0 = 0;
	//_pg0 = 0;
	//_pbs1 = 0b11111111;
	_emi  = 1;	//enable global interrupt
}
//___________________________________________________________________
//Function: MCU POWER UP
//   INPUT: 
//	  NOTE: 
//___________________________________________________________________
void PowerOn_Init() //power up or reset pin normal
{
  	SETHXT();	//fH source is external Hi speed
  	
	//LVR low voltage reset select
	//SETLVR_Voltage1_9();
	SETLVR_Voltage2_55();
	//SETLVR_Voltage3_15();

	//WDT select
	SETWDTtime8192ms();		//WDT timer enable.
	
	//GPIO control
	WDT_ResetInit();
	
	//SAVE_REEPROM();	
}
//___________________________________________________________________
//Function: Enter to HLAT mode
//   INPUT: 
//	  NOTE: 
//___________________________________________________________________
void ReadyToHalt()
{
	/*	
  	_nop();
	_pbc = 0x0f;
	_pb = 0x0f;
	_pbs1 = 0;
	*/		
	Disable_ADC();	
	Uart_off();
	_t1on  = 0;
	//_regc = 0x00;
	//_fsiden = 1;
	_halt();
	
	Uart_Init();
	//Enable_ADC();
}
//HALT
//SLEEPMode0	@(IDLEN==0  & LVDEN==Disable & WDT Disable )
//Stop:CPU,Fsub,Fs,Disable WDT,LVDEN must Disable

//SLEEPMode1	@(IDLEN==0  & (LVDEN==Disable || WDT Disable) )
//Stop:CPU,Fsub,Fs,
//Run :Enable WDT or LVDEN

//IDLEMode0		@(IDLEN==1  & FSYSON==0 )
//Stop:CPU,Fs
//Run :Fsub

//IDLEMode1		@(IDLEN==1  & FSYSON==1 )
//Stop:CPU
//Run :Fs,Fsub

//___________________________________________________________________
//Function: GPIO initial
//   INPUT: 
//	  NOTE: Base scription
//___________________________________________________________________
void GPIO_Init()
{
	/*
	_pac = 0b11100111;
	_papu = 0b11100111;	
	_pawu = 0b00000000; 	//default is 0.
	_pa = 0;
	*/
	_pbc = 0b11111011;		//pb0 for an0, pb2 for buzzer
	_pbpu =   0b11111111;		
	_pb =0;
	/*
	_pcc = 0xff;
	_pcpu = 0b11111111;		
	_pc = 0;
	*/
	/*
	//only for ht66f318
	_pdc = 0;
	_pdpu = 0;		
	_pd = 0;	
	*/	
}
//___________________________________________________________________
//Function: Ram_Init
//   INPUT: 
//  OUTPUT: 
//	  NOTE:   
//___________________________________________________________________
void Ram_Init()
{
	_bp = 1;
	_mp1 = 0xA0;	//HT66F318 only
	for(_tblp = 0x00;_tblp < 96;_tblp++) //HT66F318 96x2
	{
		_iar1 = 0;
		_mp1++;
	}	
	_bp = 0;
	//_mp1 = 0x80;	//HT66F317 bank0(80h~FFh) 128bytes
	_mp1 = 0xA0;	//HT66F318 bank0(A0h~FFh),bank1(A0h~FFh) 192bytes
	//for(_tblp = 0x00;_tblp < 128;_tblp++)	//HT66F317 128
	for(_tblp = 0x00;_tblp < 96;_tblp++) //HT66F318 96x2
	{
		_iar1 = 0;
		_mp1++;
	}		
}