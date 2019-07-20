

#ifndef _MCUCONFIG_H_
#define _MCUCONFIG_H_


extern volatile unsigned char WorkModeState;		// MCU工作模式狀態標誌位
//__________________________________________________________________//
//					-----ISR VECTOR Defination------;
//中斷入口地址
#define	START_VECTOR			0x000		// 主程序
#define INT0_VECTOR				0x004		// Intrrupt 0
#define INT1_VECTOR				0x008		// Intrrupt 1
#define ADC_VECTOR				0x00C		// ADC
#define MuFunction0_VECTOR		0x010		// Multi function0 STM0 & PTM0
#define STM0_VECTOR				0x010		// STM0
#define PTM0_VECTOR				0x010		// PTM0
#define MuFunction1_VECTOR		0x014		// Multi function1 PTM1 & PTM2
#define PTM1_VECTOR				0x014		// PTM1
#define PTM2_VECTOR				0x014		// PTM2
#define MuFunction2_VECTOR		0x018		// Multi function2 LVD & EEPROM W
#define Timebase0_VECTOR		0x020		// timebase0
#define Timebase1_VECTOR		0x024		// timebase1
#define UART_VECTOR		    	0x028		// UART
#define SIM_VECTOR				0x02C		// SIM SPI & IIC
#define SPI_VECTOR				0x030		// SPI
#endif