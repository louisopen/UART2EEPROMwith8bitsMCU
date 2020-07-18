//___________________________________________________________________
//___________________________________________________________________
// Description: Interrupt
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: interrupt.h
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _MCUCONFIG_H_
#define _MCUCONFIG_H_

//___________________________________________________________________
//___________________________________________________________________
//	ISR service VECTOR address for interrupt
#define	START_VECTOR			0x000		// Main code
#define INT0_VECTOR				0x004		// Intrrupt 0
#define COMPARATOR_VECTOR		0x008		// Comparator interrupt (ht66F318 only)
#define MuFunction0_VECTOR		0x00C		// Multi function0 STM0 & PTM0
#define STM0_VECTOR				0x00C		// STM0
#define PTM0_VECTOR				0x00C		// PTM0
#define MuFunction1_VECTOR		0x010		// Multi function1 PTM1 & PTM2
#define PTM1_VECTOR				0x010		// PTM1
#define PTM2_VECTOR				0x010		// PTM2
#define MuFunction2_VECTOR		0x014		// Multi function2 LVD & EEPROM W
#define ADC_VECTOR				0x018		// ADC
#define Timebase0_VECTOR		0x01C		// timebase0
#define Timebase1_VECTOR		0x020		// timebase1
#define INT1_VECTOR				0x024		// Intrrupt 1
#define SIM_VECTOR				0x028		// SIM SPI & IIC (ht66F318 only)
#define UART_VECTOR		    	0x02c		// UART (ht66F318 only)

extern	volatile	__byte_type	interrupt_flag;
#define TB0_int_flag	interrupt_flag.bits.b0
#define TB1_int_flag	interrupt_flag.bits.b1

#endif