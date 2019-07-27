//___________________________________________________________________
//___________________________________________________________________
// Description: EEPROM read/write/test operation
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: EEPROM.h
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _EEPROM_H__
#define _EEPROM_H__

#define	EEPROM_START_ADDR	0x01
#define	EEPROM_father	EEPROM_START_ADDR+1
#define	EEPROM_mother	EEPROM_START_ADDR+2
#define	EEPROM_mind		EEPROM_START_ADDR+3
#define	EEPROM_son 		EEPROM_START_ADDR+4

//___________________________________________________________________
//___________________________________________________________________
void fun_Write_EEPROM(unsigned char addr,unsigned char data);
unsigned char fun_Read_EEPROM(unsigned char addr);

void	TEST_EEPROM(u8 lu8v_eeprom_length);	//For test or Debug

#endif
