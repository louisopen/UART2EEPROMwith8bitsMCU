//___________________________________________________________________
//___________________________________________________________________
// Description: UART TXD/RXD 
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: uart.h
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _UART_H_
#define _UART_H_

extern	volatile	u8	gu8v_rx_guide;
extern	volatile	u8	gu8v_tx_guide;
extern	volatile	u8	array_uart_txbuff[7];
extern	volatile	u8	array_uart_rxbuff[6];
extern	volatile	__byte_type	gu8v_uart_flag;
#define gbv_tx_success 			gu8v_uart_flag.bits.b0
#define gbv_rx_success			gu8v_uart_flag.bits.b1
//#define gu8v_uart_flag2 		gu8v_uart_flag.bits.b2
//#define gu8v_uart_flag3 		gu8v_uart_flag.bits.b3
//#define gu8v_uart_flag4		gu8v_uart_flag.bits.b4
//#define gu8v_uart_flag5	 	gu8v_uart_flag.bits.b5
//#define gu8v_uart_flag6		gu8v_uart_flag.bits.b6
//#define gu8v_uart_flag7		gu8v_uart_flag.bits.b7

#define	UART_TX_DELAY	93	//evchip 9600

//___________________________________________________________________
//___________________________________________________________________
void 	Uart_Init(void);
void	Uart_off(void);
void	Uart_manage(void);
//void	Uart_putchar(u8	tx_data);
void	Uart_TX_Send_Test(u16 lu16v_tx_data);
#endif


