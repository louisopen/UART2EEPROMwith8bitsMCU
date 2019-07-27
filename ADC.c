//___________________________________________________________________
//___________________________________________________________________
// Description: Analog input (10bit)
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: ADC.c
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"
//#include "uart.h"

//___________________________________________________________________
//Function: ADC get by channel
//   INPUT: U8 channel
//  OUTPUT: U16 data
//	  NOTE:   
//___________________________________________________________________
u16 fun_Get_ADC(u8 lu8c_adc_channel)
{
	__16_type	lu8c_adc_rdata;
	
	_sadc0 = 0B00110111;	//enable & format& channel selection
	_sadc1 = 0B00100011;	//AVDD & clock source selection
	_sadc2 = 0B00000000;	//ENOPA .. reference voltage selection
	
	_acerl = 0x00;	//Not used binding IO an0~an7 IO pin
	//_acerl = 0x01;	//binding an0 IO pin
	switch(lu8c_adc_channel)
	{
		case 0:  _sadc0 &= 0xF8;  break;	//_acerl=0b00000001; pb0 an0
		case 1:  _sadc0 &= 0xF9;  break;	//_acerl=0b00000010; pb1 an1
		case 2:  _sadc0 &= 0xFa;  break;	//_acerl=0b00000100; pb2 an2
		case 3:  _sadc0 &= 0xFb;  break;	//_acerl=0b00001000; pa4 an3	
		case 4:  _sadc0 &= 0xFc;  break;	//_acerl=0b00010000; pa5 an4
		case 5:  _sadc0 &= 0xFd;  break;	//_acerl=0b00100000; pa6 an5	
		case 6:  _sadc0 &= 0xFe;  break;	//_acerl=0b01000000; pa7 an6			
		case 7:  _sadc0 &= 0xFf;  break;	//_acerl=0b10000000; pb3 an7		
	}
	
	_enadc = 1;		//ADC start convert
	
	GCC_DELAY(20);
	_start = 0;		//_sadc0.7
	_start = 1;		//_sadc0.7
	_start = 0;		//_sadc0.7
	while(_adbz != 0)	//_sadc0.6
	{} 
	
	lu8c_adc_rdata.byte.byte0 = _sadol;
	lu8c_adc_rdata.byte.byte1 = _sadoh;
	_start = 0;		//_sadc0.7
	_start = 0;		//_sadc0.7
	return lu8c_adc_rdata.u16/16;	
}

//u16 fun_Get_ADC_Key(u8 lu8c_adc_channel)
//{
//	__16_type	lu8c_adc_rdata;
//	_sadc0 = 0B00111111;
//	_sadc1 = 0B11101011;
//	_adaccm = 0;	
//	switch(lu8c_adc_channel)
//	{
//		case 0:  _sadc0 &=0xf0;  _pcs05 =1 ;_pcs04 =1 ; break;	// pc2 an0
//		case 1:  _sadc0 &=0xf1;  _pcs07 =1 ;_pcs06 =1 ; break;	// pc3 an1
//		case 2:  _sadc0 &=0xf2;  _pcs01 =1 ;_pcs00 =1 ; break;	// pc0 an2
//		case 3:  _sadc0 &=0xf3;  _pcs03 =1 ;_pcs02 =1 ; break;	// pc1 an3	
//		case 4:  _sadc1 &=0x3f;  break;	// pgao2
//		case 5:  _sadc1 &=0x5f;  break;	// vscf		
//		case 6:  _sadc1 &=0x7f;  break;	// vscfr				
//		case 7:  _sadc1 &=0x9f;  break;	// vbat		
//	}
//	_start = 0;
//	_start = 1;
//	_start = 0;	
//	GCC_NOP();	
//	while(_adbz != 0)
//	{
//	} 
//	lu8c_adc_rdata.byte.byte0 = _sadol;
//	lu8c_adc_rdata.byte.byte1 = _sadoh;
//	if(lu8c_adc_rdata.u16 == 0)
//	{
//		GCC_NOP();	
//	}
//	
//	return lu8c_adc_rdata.u16/16;	
//
//}

//___________________________________________________________________
//Function: Disable ADC
//   INPUT: 
//  OUTPUT: 
//	  NOTE:   
//___________________________________________________________________
void fun_Disable_ADC()
{
	_enadc = 0;		//_sadc0.5
}

//___________________________________________________________________
//Function: Test the ADC function with uart send
//   INPUT: Get adc value
//  OUTPUT: Uart port
//	  NOTE:   
//___________________________________________________________________
//#include "uart.h"
void TEST_ADC()
{
	__16_type	lu8c_adc_rdata_buff;
	while(1)
	{
		GCC_CLRWDT();
		lu8c_adc_rdata_buff.u16 = fun_Get_ADC(AN6);

		lu8c_adc_rdata_buff.u16++;
		
//		Uart_TX_Send_Test(lu8c_adc_rdata_buff.u16);			
//		GCC_DELAY(60000);		
//		GCC_DELAY(60000);			
	}
}
