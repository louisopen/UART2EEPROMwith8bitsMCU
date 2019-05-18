//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : sys_init.h
// Description: �t�Ϊ�l�Ƭ����{��
//Targer Board: 
//   MCU      : BH67F2260
//   Author   : ming
//   Date     : 2015/11/20
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef SYS_INIT_H_
#define SYS_INIT_H_


void fun_PowerOnInit();
void fun_ResetInit();
void fun_GPIO();
void fun_RamInit();
//void fun_SysInit();
void fun_PrepareToHalt();
//void STP_PUMP_SET();


//@@@@@@@@@@@@@@@@@@@@@@@@@@@ �t�ΰ�¦�]�w @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//  �i���W�v��
//  4000000,8000000�A120000
#define SysFrequency		12000000



//					@-------------SCC config--------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  CKS2  |  CKS1  |  CKS0  |  �X     |  FHS   |  FSS   | FHIDEN | FSIDEN |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// Bit 7~5 CKS2~CKS0�G
// 000�GfH 001�GfH/2 010�GfH/4 011�GfH/8 100�GfH/16 101�GfH/32 110�GfH/64 111�GfSUB
// Bit 3 FHS�G
// 	0�GHIRC  1�GHXT
// Bit 2 FSS�G
// 	0�GLIRC  1�GLXT
// Bit 1 FHIDEN�GHALT MODLE
// 	0�GDISABLE  1�GENABLE
// Bit 0 FSIDEN�GCPU???�C?��?�������
// 	0�GDISABLE  1�GENABLE

#define SCC_Default		0b00000000   // fH HIRC LIRC 

   
//					@-------------HIRCC config--------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  CKS2  |  CKS1  |  CKS0  |  �X     |  HIRC1 |  HIRC0 | HIRCF  | HIRCEN |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   1    |
// |_______________________________________________________________________________

// Bit 3~2 HIRC1~HIRC0�GHIRC
// 	00�G4MHz 01�G8MHz 10�G12MHz 11�G4MHz
// Bit 1 HIRCF�G
// 	0�GHIRC 1�GHIRC
// Bit 0 HIRCEN�G
// 	0�GDISABLE
// 	1�GENABLE
#define HIRCC_Default		0b00000101   // 8 mhz 



  
//					@-------------HXTC config--------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  �X     |  �X     |  �X     |  �X     |  �X     |  HXTM  |   HXTF | FSIDEN |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// Bit 2 HXTM�G
// 	0�GHXT ? 10MHz  1�GHXT �� 10MHz
// Bit 0 HXTEN�G
// 	0�GDISABLE  1�GENABLE
#define HXTC_Default		0b00000000   //



//					@-------------LXTC config--------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  �X     |  �X     |  �X     |  �X     |  �X     |  �X     |   LXTF | LXTEN  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// Bit 2 HXTM�G
// 	0�GHXT ? 10MHz  1�GHXT �� 10MHz
// Bit 0 HXTEN�G
// 	0�GDISABLE  1�GENABLE
#define LXTC_Default		0b00000000   //


#define SETHIRC_8MHZ()	{_fhs = 0;_hirc1 = 0;_hirc0 = 0;_hircen = 1;}
#define SETHIRC_12MHZ()	{_fhs = 0;_hirc1 = 0;_hirc0 = 1;_hircen = 1;}
#define SETHIRC_16MHZ()	{_fhs = 0;_hirc1 = 1;_hirc0 = 0;_hircen = 1;}

#define SETLIRC_32K()		{_fss = 0;}

#define SETHXT()			{_fhs = 1;_pas07 = 1;_pas06 = 1;_pas11 = 1;_pas10 = 1;_hxten = 1;}
#define SETLXT_32768()		{_fss = 1;_pas05 = 1;_pas04 = 1;_pas01 = 1;_pas00 = 1;_lxten = 1;}

#define SETLXT_32768_1()	{_fss = 1;_pas05 = 0;_pas04 = 0;_pas01 = 0;_pas00 = 0;_lxten = 1;}


//					@-------------WDT config--------------@
//___________________________________________________________________
//Please in Option select WDT clock Source
//if WDT clock Source fs =fsub
//WDT time?��覡:
//WDT time =  2^18/fsub
//example:(max time �P����?2^18�ASource fs = 32768)
//WDT time = 2^18/32768= 8s

#define SETWDT_Disable()			{ 	_wdtc =	0B10101000	;	}
#define SETWDTtime8ms()				{	_wdtc =	0B01010000 	;	} //2^8/Fs  =    8ms
#define SETWDTtime32ms()			{	_wdtc =	0B01010001	;	}//2^10/Fs =   32ms
#define SETWDTtime128ms()			{	_wdtc =	0B01010010 	;	}	//2^12/Fs =  128ms
#define SETWDTtime512ms()			{	_wdtc =	0B01010011	;	}//2^14/Fs =  512ms
#define SETWDTtime1024ms()			{	_wdtc =	0B01010100 	;	}	//2^15/Fs = 1024ms
#define SETWDTtime2048ms()			{	_wdtc =	0B01010101	;	}//2^16/Fs = 2048ms
#define SETWDTtime4096ms()			{	_wdtc =	0B01010110	;	}//2^17/Fs = 4096ms
#define SETWDTtime8192ms()			{	_wdtc =	0B01010111	;	}	//2^18/Fs = 8192ms



//					@-------------LVR config--------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  LVS7  |  LVS6  |  LVS5  |  LVS4  |  LVS3  |  LVS2  |  LVS1  |  LVS0  |
// |______________________________________________________________________________
// | POR  |   0    |   1    |   0    |   1    |   0    |   1    |   0    |   1    |
// |_______________________________________________________________________________
// BIT 7~0  LVS7~LVS0:LVR�q����� (01100110 is default)
// 			01010101:  1.9V     00110011:  2.55V
//			10011001:  3.15V    10101010:  3.8V
//          ��L��: MCU�_�� ( set 11110000 is disable)
//___________________________________________________________________
#define SETLVR_Voltage1_7()		{	_lvrc = 0B01100110 ;	}	//default on reset
#define SETLVR_Voltage1_9()		{	_lvrc = 0B01010101 ;	}
#define SETLVR_Voltage2_55()	{	_lvrc = 0B00110011 ;	}
#define SETLVR_Voltage3_15()	{	_lvrc = 0B10011001 ; 	}
#define SETLVR_Voltage3_8()		{	_lvrc = 0B10101010 ;	}
#define SETLVR_Disable()		{	_lvrc = 0B11110000 ;	}

//					@-------------EEPROM config--------------@
//Setting in EEPROM.h

//					@-------------IO config--------------@
//Setting in Target.h

//					@-------------Timer config-----------@
//Setting in Timer.h

 
//                           @--------------PTMnC0---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name | PTnPAU | PTnCK2 | PTnCK1 | PTnCK0 |  PTnON |    -   |    -   |    -   |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7  TnPAU:TMn�p�ƾ��Ȱ������
// 			0:  �B��
//			1:  �Ȱ�
// BIT 6~4  TnCK2~TnCK0:���TMn�p�Ʈ���
// 			000:  fsys/4   001:  fsys   010:   fh/16
// 			011:  fh/64    100:  fsub   101:   �O�d��
// 			110:  TCKn�W�ɪu    111:  TCKn�U���u
// BIT 3  TnON:TMn�p�ƾ�on/off�����
// 			0:  off
//			1:  on
// BIT 2~0 



//#define TM0C0_Default		0x30   // CLOCK  fsys/64
#define TM0C0_Default		0b01000000   // CLOCK  fsub

//                           @--------------PTMnC1---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TnM1  |  TnM0  |  TnIO1 |  TnIO0 |  TnOC  | TnPOL  | TnDPX  | TnCCLR |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   0    |   0    |   0    |   0    |   0    |   0    |
// |_______________________________________________________________________________
// BIT 7~6  TnM1~TnM0:���TMn�u�@�Ҧ���
// 			00:  ������ǰt��X�Ҧ�   01:���w�q�Ҧ�
//			10:  PWM�Ҧ�              11:�w��/�p�ƾ��Ҧ�
// BIT 5~4  TnIO1~TnIO0:���TPn_0�ATPn_1��X�\���
//����ǰt��X�Ҧ�
// 			00:  �L�ܤ�          01:  ��X�C
//			10:  ��X��          11:  ��X½��
//PWM�Ҧ�
// 			00:  �j��L�Ī��A    01:  �j��Ī��A
//			10:  PWM��X         11:  ���w�q
//�p�ƾ�/�w�ɼҦ�: ���w�q
// BIT 3  TnOC
// ����ǰt��X�Ҧ�             PWM�Ҧ�
// 			0:  ��l�C             0:  �C����
//			1:  ��l��             1:  ������
// BIT 2  TnPOL:TPn_0,TPn_1��X���ʱ����
// 			0:  �P��
//			1:  �Ϭ�
// BIT 1  TnDPX: TMn PWM�g��/�e�Ť񱱨��
// 			0:  CCRP-�g��   ;CCRA-�e�Ť�
//			1:  CCRP-�e�Ť� ;CCRP-�g��
// BIT 0  TnCCLR:���TMn�p�ƾ��M�s�����
// 			0:  TMn�����P�ǰt
//			1:  TMn�����A�ǰt
#define TM0C1_Default		0xC1



// #define TM0AL_Default		0xfa	
// #define TM0AH_Default		0x0       // = 0.000008*250 = 2ms
// #define TM0AL_Default		0x47	
// #define TM0AH_Default		0x1       	  // = 0.000008*250 = 2ms

#define TM0AL_Default		0x48	
#define TM0AH_Default		0x1       	  // =  = 10ms



//#define	SETPTM2_10MS()		{ _ptm2c0 = 0b01000000;_ptm2c1 = 0xC1;_ptm2al = 0x48;_ptm2ah = 0x1;}
#define	SETPTM2_10MS()		{ _tm2c0 = 0b01000000; _tm2c1 = 0xC1; _tm2al = 0x48; _tm2ah = 0x1;}


#define STM0C0_Default		0b00000000   // CLOCK  fSYS
#define STM0C1_Default		0B10100100

#define STM0A_MAX			1023      	

#define STM0AL_Default		767%256	
#define STM0AH_Default		767/256       	  // 
#define STM0RP_Default		4       	  // =


#define TM2AL_bat_60		580%256	
#define TM2AH_bat_60		580/256  
#define TM2AL_bat_58		630%256	
#define TM2AH_bat_58		630/256    
#define TM2AL_bat_56		680%256
#define TM2AH_bat_56		680/256    
#define TM2AL_bat_54		730%256	
#define TM2AH_bat_54		730/256      
#define TM2AL_bat_52		780%256	
#define TM2AH_bat_52		780/256   
#define TM2AL_bat_50		830%256	
#define TM2AH_bat_50		830/256    
#define TM2AL_bat_48		880%256	
#define TM2AH_bat_48		880/256      
#define TM2AL_bat_46		930%256	
#define TM2AH_bat_46		930/256   
#define TM2AL_bat_44		980%256	
#define TM2AH_bat_44		980/256  


//					@-------Internal Power config--------@
//Setting in Others file  when need

//					@------------ADC config--------------@
//                           @--------------TBC---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TBON  |  TBCK  |  TB11  |  TB10  | LXTLP  |  TB02  |  TB01  |  TB00  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   1    |   1    |   0    |   1    |   1    |   1    |
// |_______________________________________________________________________________
// BIT 7  TBON:TB0�MTB1�����
// 			0:  Disable
//			1:  Enable
// BIT 6  TBCK:���ftb������
// 			0:  fsub
//			1:  fsys/4
// BIT 5~4  TB11~TB10:TimeBase1���X�g��
// 			00:  2^12/ftb   01:  2^13/ftb
//			10:  2^14/ftb   11:  2^15/ftb
// BIT 3  LXTLP:LXT�C�\�ӱ����
// 			0:  �ֳt�ҰʼҦ�
//			1:  �C�\�ӼҦ�
// BIT 2~0  TB02~TB00�GTimeBase0���X�g��
// 			000:  2^8/ftb    001:  2^9/ftb    010:  2^10/ftb
// 			011:  2^11/ftb   100:  2^12/ftb   101:  2^13/ftb
// 			110:  2^14/ftb   111:  2^15/ftb

#define TimeBase_Default 	0B10100000	//TimeBase1 0.5S   TimeBase 0  7.8ms



//                           @--------------TB0C---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TB0ON |  -     |  -     |  -     |  -     |  TB02  |  TB01  |  TB00  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   1    |   1    |   0    |   1    |   1    |   1    |
// |_______________________________________________________________________________
// BIT 7  TB0ON:
// 			0:  Disable
//			1:  Enable
// BIT 2~0  TB02~TB00�GTimeBase0���X�g��
// 			000:  2^0/ftb    001:  2^1/ftb    010:  2^2/ftb
// 			011:  2^3/ftb   100:  2^4/ftb   101:  2^5/ftb
// 			110:  2^6/ftb   111:  2^7/ftb

#define TimeBase0_Default 	0B00000111	//

//                           @--------------TB1C---------------@
//  ______________________________________________________________________________
// | Bit  |  Bit7  |  Bit6  |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
//  ______________________________________________________________________________
// | Name |  TB1ON |  -     |  -     |  -     |  -     |  TB12  |  TB11  |  TB10  |
// |______________________________________________________________________________
// | POR  |   0    |   0    |   1    |   1    |   0    |   1    |   1    |   1    |
// |_______________________________________________________________________________
// BIT 7  TB1ON:
// 			0:  Disable
//			1:  Enable
// BIT 2~0  TB12~TB10�GTimeBase0���X�g��
// 			000:  2^8/ftb    001:  2^9/ftb    010:  2^10/ftb
// 			011:  2^11/ftb   100:  2^12/ftb   101:  2^13/ftb
// 			110:  2^14/ftb   111:  2^15/ftb

#define TimeBase1_Default 	0B00000110	//500ms




//					@------------ADC config--------------@
//Setting in ADC.h

//					@-------Temperature config-----------@
//Setting in Others file  when need

//					@-------------SIM config-------------@
//Setting in SIM.h

//					@-------------UART config-------------@
//Setting in UART.h



#endif
