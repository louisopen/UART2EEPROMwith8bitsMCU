//___________________________________________________________________
//___________________________________________________________________
// Description: EEPROM read/write/test operation
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//  File Name : EEPROM.c
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History: Inedx used iar1(mp1), bank1
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

//___________________________________________________________________
//Function: Read from EEPROM internal
//   INPUT: address
//  OUTPUT: data
//	  NOTE:   
//___________________________________________________________________
unsigned char fun_Read_EEPROM(unsigned char addr)
{
	u8 rdata,tm_emi;

	tm_emi = _emi;
	_emi = 0;
	_eea = addr;				//EEPROM address b5~b0 internal
	_bp = 1;
	_mp1 = 0x40;
	//_mp1h = 1;
	//_mp1l = 0x40;
	
	_iar1 |=0x2;				//enable RDEN (read enable)
	_iar1 |=0x1;				//active READ 
	while((_iar1 & 0x01) !=0);	//wait read end
	rdata = _eed;				//EEPROM data
	
	_iar1 &=	0xfD;			//disable RDEN	

//	_mp1 = tmp_mp1;   
	_bp = 0;	
	_emi = tm_emi;
	return (rdata);
}


//___________________________________________________________________
//Function: Write to EEPROM internal
//   INPUT: address/data
//  OUTPUT: none
//	  NOTE:   
//___________________________________________________________________
void fun_Write_EEPROM(unsigned char addr,unsigned char data)
{
	u8 tm_emi;
	tm_emi = _emi;
	_emi = 0;	
	_eea = addr;		//EEPROM address bit 5 ~ bit 0 internal
	_eed = data;		//EEPROM data bit 7 ~ bit 0 internal
	_bp = 1;			//bank 1
	_mp1 = 0x40;		//index mp1
	//_mp1h = 1;
	//_mp1l = 0x40;

	_iar1	|=	0x8;				//enable WREN (write enable)
	_iar1	|=	0x4;				//active write 
	//GCC_NOP();
	_nop();
	while((_iar1 & 0x04) !=0);		//wait write end
	
	_iar1	&=	0xf7;				//disable WREN	

//	_mp1	=	tmp_mp1;   
	_bp	= 0;
	_emi = tm_emi;	
}


//___________________________________________________________________
//Function: Test Read/Write with EEPROM internal
//   INPUT: lu8v_eeprom_length �]�wŪ�geeprom�����סA�i�ھڤ��P����i��]�m
//  OUTPUT: none
//	  NOTE: lu8a_datatemp[64] ���O�O����,�{�ǶȥΦbtest 
//___________________________________________________________________
void TEST_EEPROM(u8 lu8v_eeprom_length)
{
	volatile	u8	lu8a_datatemp[64],i;
	for(i=0;i<lu8v_eeprom_length;i++)
	{
		fun_Write_EEPROM(i,i);
	}

	for(i=0;i<lu8v_eeprom_length;i++)
	{
		lu8a_datatemp[i] = fun_Read_EEPROM(i);
	}	
	//�b���B�]�m�_�I�d��lu8a_datatemp[i]���ȧY�i�P�_Ū�g�O�_���\�C
	GCC_NOP();
}





