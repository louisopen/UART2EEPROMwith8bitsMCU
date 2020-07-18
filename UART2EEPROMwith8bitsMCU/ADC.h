//___________________________________________________________________
//___________________________________________________________________
// Description: Get ADC value (10bit internal)
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: ADC.h
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _ADC_H_
#define _ADC_H_

u16 Get_ADC(u8 lu8c_adc_channel);
void Disable_ADC();
void TEST_ADC();
  
//--------------_sadc0------------------
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name | START  | ADBZ   |  ENADC |  ADRFS |    -   | SACS2  | SACS1  | SACS0  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |    0   |    -   |   0    |   0    |   0    |
// |_______________________________________________________________________________
// Bit 7 START: Start the A/D conversion
//		0¡÷1¡÷0: Start A/D conversion
//		0¡÷1: Reset the A/D converter and set ADBZ to 0
//		1¡÷0: Start A/D conversion and set ADBZ to 1
// Bit 6 ADBZ: A/D Converter busy flag
//		0: No A/D conversion is in progress
//		1: A/D conversion is in progress
// Bit 5 ENADC: A/D Converter function enable control
//		0: Disable
//		1: Enable
// Bit 4 ADRFS: A/D Converter data format control
//		0: ADC output data format ¡÷ SADOH=D[11:4]; SADOL=D[3:0]
//		1: ADC output data format ¡÷ SADOH=D[11:8]; SADOL=D[7:0]
// Bit 3 Unimplemented, read as ¡§0¡¨
// Bit 2~0 SACS2~SACS0: A/D converter external analog input channel selection
//		000: AN0
//		001: AN1
//		010: AN2
//		011: AN3
//		100: AN4
//		101: AN5
//		110: AN6
//		111: AN7
#define AN0		0		//
#define AN1		1		//
#define AN2		2		//
#define AN3		3		//
#define AN4		4		//
#define AN5		5		//
#define AN6		6		//
#define AN7		7		//
#define SADC0_Default 0b00000000   // AN0

//--------------_sadc1------------------
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name | SAINS2 | SAINS1 | SAINS0 |   -    |   -    | ADCK2  | ADCK1  | ADCK0  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   -    |   -    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// Bit 7~5 SAINS2~SAINS0: A/D converter input signal selection
//		000,100: External signal ¡V External analog channel input
//		001: Internal signal ¡V Internal A/D converter power supply voltage AVDD
//		010: Internal signal ¡V Internal A/D converter power supply voltage AVDD/2
//		011: Internal signal ¡V Internal A/D converter power supply voltage AVDD/4
//		101, 110, 111: Reserved
// Bit 4~3 Unimplemented, read as ¡§0¡¨
// Bit 2~0 SACKS2~SACKS0: A/D conversion clock source selection
//		000: fSYS
//		001: fSYS /2
//		010: fSYS /4
//		011: fSYS /8
//		100: fSYS /16
//		101: fSYS /32
//		110: fSYS /64
//		111: fSYS /128
#define SADC1_Default 0b00001001   // 8MHZ/8 = 1US >0.5US


//--------------_sadc2------------------
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  ENOPA |  VBGEN |  VREFI |  VREFO | SAVRS3 | SAVRS2 | SAVRS1 | SAVRS0 |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |    0   |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// Bit 7 ENOPA: A/D converter OPA enable/disable control
//		0: Disable
//		1: Enable
// Bit 6 VBGEN: Internal Bandgap reference voltage enable control
//		0: Disable
//		1: Enable
// Bit 5 VREFI: VREF input control
//		0: Disable
//		1: Enable
// Bit 4 VREFO: VREFO output control
//		0: Disable
//		1: Enable
// Bit 3~0 SAVRS3~SAVRS0: A/D converter reference voltage selection
//		0000: AVDD
//		0001: VREF
//		0010: VREF ¡Ñ 2
//		0011: VREF ¡Ñ 3
//		0100: VREF ¡Ñ 4
//		1001: Inhibit to use
//		1010: VBG ¡Ñ 2
//		1011: VBG ¡Ñ 3
//		1100: VBG ¡Ñ 4
//		Others: AVDD
#define SADC2_Default 0B00000000


//--------------_acerl------------------
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  ACE7  |  ACE6  |  ACE5  |  ACE4  |  ACE3  |  ACE2  |  ACE1  |  ACE0  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |    0   |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// Bit 7 ACE7: Define PB3 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN7
// Bit 6 ACE6: Define PA7 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN6
// Bit 5 ACE5: Define PA6 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN5
// Bit 4 ACE4: Define PA5 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN4
// Bit 3 ACE3: Define PA4 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN3
// Bit 2 ACE2: Define PB2 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN2
// Bit 1 ACE1: Define PB1 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN1
// Bit 0 ACE0: Define PB0 is A/D input or not
//		0: Not A/D input
//		1: A/D input, AN0
#define ACERL_Default 0B00000000	//No GPIO define


#endif