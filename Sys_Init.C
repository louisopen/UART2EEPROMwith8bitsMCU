//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : sys_init.c
// Description: 系統初始化相關程序
//Targer Board: None
//   MCU      : HT66F318
//   Author   : 
//   Date     : 2019
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"


/********************************************************************
Function: MCU復位初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_ResetInit()	//WDT 溢出復位
{
		//IO
	fun_GPIO();
 	Uart_Init();	
 	//fun_PGA1_INIT(Pgac1_gain1_32,16);
 	//fun_PGA2_INIT();
 	//fun_SCF_INIT(32);
 	//fun_CCurrent_INIT();
	//fun_En_Analog_power();
	//fun_Enable_ADC();
 	//ptm2
 	SETPTM2_10MS();
 	_t2on  = 1;	
 	
 	//TimeBase 
 	_tbc = TimeBase0_Default;
 	//_tb1c = TimeBase1_Default;
 	//_pscr = 0x03;//	time base click = fsub
	//_tbon = 1;
 	//_tbck = 0;

	
	_tm0c0 = STM0C0_Default;
	_tm0c1 = STM0C1_Default;
	_tm0al = STM0AL_Default;//;占空比
	_tm0ah = STM0AH_Default;
	_tm0rp = STM0RP_Default;//4*256 周期	

	
  	_nop();
  	//_pgc0 = 0;
	//_pg0 = 0;
	//_pbs1 = 0b11111111;
	//SYSTEM_INITIALIZATION(); //System initialization
	//DAC_RAMP_UP(); //Open DAC and do ramp up	
	//fun_en_battery_check();
	//gbv_bat_low = 0;
	//gu8v_battery_votage = 0;
	_emi  = 1;	//開啟TimeBase 1作為喚醒檢測
	
}
/********************************************************************
Function: MCU上電初始化
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_PowerOnInit() //第一次上電或正常reset pin
{
	//Fsys used fH so don't setting SMOD 
   	//SETHIRC_12MHZ();	//internal
  	//SETLXT_32768(); 	//external 
  	
	//WDT
	SETWDTtime8192ms();		//WDT timer or disable.
	
	//LVR
	//SETLVR_Voltage1_9();
	SETLVR_Voltage3_15();
	
	//IO
	fun_ResetInit();
//	fun_CAL_REEPROM();
//	fun_init_time();	
}
/********************************************************************
Function: 關閉各個模塊進入HLAT模式
INPUT	:
OUTPUT	:
NOTE	:
********************************************************************/
void fun_PrepareToHalt()
{
/*	
  	_nop();
  	_pgc0 = 0;
	_pg0 = 1;
	//DAC_RAMP_DOWN(); //Open DAC and do ramp up		
	_pbc = 0x0f;
	_pb = 0x0f;
	_pbs1 = 0;
	_pgs11 = 0;
	_pgs10 = 0;	
	_pgc4 = 0;
	_pg4 = 0;
*/	
	//fun_dis_battery_check();	
	 //fun_Disable_ADC();	
	 //fun_Dis_Analog_power();

	 //fun_LCD_Disable();
	//LCD_ICON(LBC_CLR,LCD_mmhg_ADDR);
	//LCD_DISP_DIA_ON(LBC_CLR,gu16v_dia);
	//LCD_DISP_SYS_ON(LBC_CLR,gu16v_sys);	
	//LCD_DISP_Pluse_ON(LBC_CLR,gu8v_heart);	
	//LCD_ICON(LBC_CLR,LCD_Heart_beep_ADDR);	
	 Uart_off();
	 _t1on  = 0;
//	 gbv_tb1_flag = 0;
//	 _regc = 0x00;
//	 _fsiden = 1;
	 _halt();
	//fun_500ms_polling();	
	/* 
	 if(gbv_tb1_flag)
	 {
	 	
	 }
	 else
	 {
	 	fun_ResetInit();
		//fun_LCD_INIT();
		//fun_LCD_Enable();		
	 	//gu8v_halt_time = LU8C_HALT_TIME - 8;
	 }
	 */
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



/********************************************************************
Function: GPIO初始化
INPUT	: none
OUTPUT	: none
NOTE	: 所有IO config為輸出low
********************************************************************/
void fun_GPIO()
{/*
	_pac = 0b11100111;
	_papu = 0b11100111;	
	_pa = 0;
	_pbc = 0b11111111;
	_pbpu =   0b11111111;		
	_pb =0;
	_pcc = 0xff;
	_pcpu = 0b11111111;		
	_pc = 0;
	_pdc = 0;
	_pdpu = 0;		
	_pd = 0;
	_pec = 0;
	_pepu = 0;	
	_pe = 0;
	_pfc = 0;	
	_pfpu = 0;	
	_pf = 0;	
	_pgc = 0b00010110;	
	_pgpu = 0b00010110;	
	_pg = 0b00010110;		
*/	
	//fun_Key_init();
	//GPIO_VALUE_IO = 0;
	//GPIO_VALUE = 0;
	//GPIO_PUMP_IO = 0;
	//GPIO_PUMP = 0;	
	
}
/********************************************************************
Function:Ram_Init
INPUT	:
OUTPUT	:
NOTE	:HT66F317 (80h~FFh), HT66F318(A0h~FFh), Bank0,bank1
********************************************************************/
void fun_RamInit()
{
	_bp = 0;
	_mp1 = 0xA0;
	//while(_mp1h<RamBankSectorSum)
	while(_mp1<2)	//HT66F318 bank0,bank1
	{
		for(_tblp = 0x00;_tblp < 128;_tblp++)
		{
			 _iar1 = 0;
			  _mp1++;
		}
		_mp1 = 0xA0;		
		_bp = 1;
	}
	_bp = 0;		
}
/*
void fun_RamInit()
{
	_mp1 = 0x80;
	//while(_mp1<RamBankSectorSum)
	while(_mp1<1)	//HT66F317 bank0
	{
		for(_tblp = 0x00;_tblp < 128;_tblp++)
		{
			 _iar1 = 0;
			  _mp1++;
		}
		_mp1 = 0x80;		
	}		
}
*/