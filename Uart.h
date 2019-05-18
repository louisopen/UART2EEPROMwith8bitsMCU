//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Uart.h
// Description: IO 模擬 Uart 
//Targer Board: None
//   MCU      : BH67F2260
//   Author   : ming
//   Date     : 2015/11/20
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#ifndef _UART_H_
#define _UART_H_


/********************************************************************
Function:	
********************************************************************/
extern	volatile	u8	gu8v_rx_guide;
extern	volatile	u8	gu8v_tx_guide;
extern	volatile	u8	array_uart_txbuff[7];
extern	volatile	u8	array_uart_rxbuff[6];
extern	volatile	__byte_type	gu8v_uart_flag;
#define gbv_tx_success 			gu8v_uart_flag.bits.b0
#define gbv_rx_success			gu8v_uart_flag.bits.b1
#define gu8v_uart_flag2 		gu8v_uart_flag.bits.b2
#define gu8v_uart_flag3 		gu8v_uart_flag.bits.b3
#define gu8v_uart_flag4			gu8v_uart_flag.bits.b4
#define gu8v_uart_flag5	 		gu8v_uart_flag.bits.b5
#define gu8v_uart_flag6			gu8v_uart_flag.bits.b6
#define gu8v_uart_flag7			gu8v_uart_flag.bits.b7

/********************************************************************
Function:	
********************************************************************/
void 	Uart_Init(void);
void	Uart_off(void);
void	Uart_manage(void);

/********************************************************************
Function:	DEFINE
********************************************************************/

//#define	GPIO_UART_TX_IO	_pcc4
//#define	GPIO_UART_TX	_pc4


/********************************************************************
Function:	
********************************************************************/
#define	UART_TX_DELAY	93	//evchip 9600

/********************************************************************
Function:	
********************************************************************/
void 	Uart_Init(void);
//void	Uart_putchar(u8	tx_data);
void	Uart_TX_BH32F52640_ADC_AUTO_TEST(u16	lu16v_tx_data);
#endif


