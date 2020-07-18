//___________________________________________________________________
//___________________________________________________________________
// Description: Interupt ISR 
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: Interrupt.c’é
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

volatile	__byte_type	interrupt_flag;

//___________________________________________________________________
//Function: INT0 ISR
//NOTE	  :   
//___________________________________________________________________
//#pragma vector INT0_ISR @ 0x04					//for V2 of compiler
//void INT0_ISR(void)
void __attribute((interrupt(0x04)))  INT0_ISR()		//for V3 of compiler
{
}

//___________________________________________________________________
//Function: INT1 ISR
//NOTE	  :   
//___________________________________________________________________
//#pragma vector INT1_ISR @ 0x24					//for V2 of compiler
//void INT1_ISR(void)
void __attribute((interrupt(0x24)))  INT1_ISR()		//for V3 of compiler
{
}

//___________________________________________________________________
//Function: MuFunction0 ISR
//NOTE	  : STM0 & PTM0 “æ?(TM0)  
//___________________________________________________________________
//#pragma vector MuFunction0_ISR @ 0x0c				//for V2 of compiler
//void MuFunction0_ISR(void)
void __attribute((interrupt(0x0c)))  MuFunction0_ISR()	//for V3 of compiler
{		
	//_ptm0af = 0;
}

//___________________________________________________________________
//Function: MuFunction1 ISR
//NOTE	  : PTM1 & PTM2  
//___________________________________________________________________
//#pragma vector MuFunction1_ISR @ 0x10				//for V2 of compiler
//void MuFunction1_ISR(void)
void __attribute((interrupt(0x10)))  MuFunction1_ISR()	//for V3 of compiler
{		
	//_ptm0af = 0;
}

//___________________________________________________________________
//Function: MuFunction2 ISR
//NOTE	  : LVD & EEPROM W
//___________________________________________________________________
//#pragma vector MuFunction2_ISR @ 0x14				//for V2 of compiler
//void MuFunction2_ISR(void)
void __attribute((interrupt(0x14)))  MuFunction2_ISR()	//for V3 of compiler
{		
	//_ptm0af = 0;
}

//___________________________________________________________________
//Function: ADC ISR
//NOTE	  : 
//___________________________________________________________________
//#pragma vector ADC_ISR @ 0x18						//for V2 of compiler
//void ADC_ISR(void)
void __attribute((interrupt(0x18)))  ADC_ISR()		//for V3 of compiler
{
}

//___________________________________________________________________
//Function: TimeBase0 ISR
//NOTE	  : 
//___________________________________________________________________
//#pragma vector Timebase0_ISR @ 0x1c				//for V2 of compiler
//void Timebase0_ISR(void)
void __attribute((interrupt(0x1c)))  Timebase0_ISR()	//for V3 of compiler
{ 
	TB0_int_flag=1;
}

//___________________________________________________________________
//Function: TimeBase1 ISR
//NOTE	  : 
//___________________________________________________________________
//#pragma vector Timebase1_ISR @ 0x20				//for V2 of compiler
//void Timebase1_ISR(void)
void __attribute((interrupt(0x20)))  Timebase1_ISR()	//for V3 of compiler
{	
	TB1_int_flag=1;
}

//___________________________________________________________________
//Function: Comparator ISR (Only for HT66F318)
//NOTE    : 
//___________________________________________________________________
DEFINE_ISR(Comparator_ISR, 0x08)					//for V3 of compiler
//#pragma vector Comparator_ISR @ 0x08				//for V2 of compiler
//void Comparator_ISR(void)
//void __attribute((interrupt(0x08)))  Comparator_ISR()	//for V3 of compiler
{
}

//___________________________________________________________________
//Function: I2C ISR (Only for HT66F318)
//NOTE    : 
//___________________________________________________________________
DEFINE_ISR(I2C_ISR, 0x28)							//for V3 of compiler
//#pragma vector I2C_ISR @ 0x28
//void I2C_ISR(void)
//void __attribute((interrupt(0x28)))  I2C_ISR()	//for V3 of compiler
{
}
