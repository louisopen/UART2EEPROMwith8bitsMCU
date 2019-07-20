//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : fun_isr.c
// Description: ┮Τい耞ㄧ计
//   Customer : Holtek Demo Code
//Targer Board: None
//     Note   :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"
volatile unsigned char  gu8v_400ms_count;
volatile unsigned char  gu8v_500ms_count;
volatile unsigned char  gu8v_4ms_count;	
volatile unsigned char  gu8v_100ms_count;	

/********************************************************************
//@------------场い耞0ㄧ计--------------@
NOTE	:   
********************************************************************/
//#pragma vector INT0_ISR @ 0x04
//void INT0_ISR(void)
void __attribute((interrupt(0x04)))  INT0_ISR()	//for V3 of compiler
{
}
//@------------场い耞0ㄧ计--------------@
//#pragma vector INT1_ISR @ 0x24
//void INT1_ISR(void)
void __attribute((interrupt(0x24)))  INT1_ISR()	//for V3 of compiler
{
}
//@-------MuFunction0 い耞ㄧ计------------@
// STM0 & PTM0 ノ(TM0)
//#pragma vector MuFunction0_ISR @ 0x0c
//void MuFunction0_ISR(void)
void __attribute((interrupt(0x0c)))  MuFunction0_ISR()	//for V3 of compiler
{		
	//_ptm0af = 0;
}
//@-------MuFunction1 い耞ㄧ计------------@
// Multi function1 PTM1 & PTM2
//#pragma vector MuFunction1_ISR @ 0x10
//void MuFunction1_ISR(void)
void __attribute((interrupt(0x10)))  MuFunction1_ISR()	//for V3 of compiler
{		
	//_ptm0af = 0;
}
//@-------MuFunction2 い耞ㄧ计-----------@
// Multi function2 LVD & EEPROM W
//#pragma vector MuFunction2_ISR @ 0x14
//void MuFunction2_ISR(void)
void __attribute((interrupt(0x14)))  MuFunction2_ISR()	//for V3 of compiler
{		
	//_ptm0af = 0;
}
//@------------ADC い耞ㄧ计---------------@
//#pragma vector ADC_ISR @ 0x18
//void ADC_ISR(void)
void __attribute((interrupt(0x18)))  ADC_ISR()	//for V3 of compiler
{
}
//@----------Timebase0 い耞ㄧ计-----------@
//#pragma vector Timebase0_ISR @ 0x1c
//void Timebase0_ISR(void)
void __attribute((interrupt(0x1c)))  Timebase0_ISR()	//for V3 of compiler
{ 
}
//@----------Timebase1 い耞ㄧ计-----------@
//#pragma vector Timebase1_ISR @ 0x20
//void Timebase1_ISR(void)
void __attribute((interrupt(0x20)))  Timebase1_ISR()	//for V3 of compiler
{	
}
//@-----------UART0 い耞ㄧ计--------------@
//DEFINE_ISR(UART0_ISR, UART0_VECTOR)
//{
//
//}
//@-------------SPI い耞ㄧ计--------------@
//DEFINE_ISR(SPI_ISR, SPI_VECTOR)
//{
//}
//@------------SIM い耞ㄧ计---------------@
//DEFINE_ISR(SIM_ISR, SIM_VECTOR)
//{
//}
