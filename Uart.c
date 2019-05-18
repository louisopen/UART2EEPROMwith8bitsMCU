//___________________________________________________________________
//___________________________________________________________________
//  Copyright : 2015 BY HOLTEK SEMICONDUCTOR INC
//  File Name : Uart.c
// Description: 
//Targer Board: 
//   MCU      : BH67F2260
//   Author   : ming
//   Date     : 2015/11/23
//   Version  : V00
//   History  :
//___________________________________________________________________
//___________________________________________________________________
#include "common.h"

/********************************************************************
Function:	DEFINE
********************************************************************/
#define		cmd_return_op1adnum			30
#define		cmd_return_op2adnum			31
#define		cmd_adjust_bandgap_up		32
#define		cmd_adjust_bandgap_down		33
#define		cmd_data_to_pref			34
#define		cmd_data_to_rom				35
#define		cmd_adjust_daco_up			37
#define		cmd_adjust_daco_down		38
#define		UCR1_8_N_1     				0x80      //8bits-Data  NONE-Parity 1bit-Stop Format
#define 	UCR1_7_O_1     				0x0B0     //7bits-Data  Odd-Parity  1bit-Stop Format
#define		UCR1_7_E_1     				0x0A0     //7bits-Data  Even-Parity 1bit-Stop Format
#define		UCR1_9_N_1     				0x0C0     //9bits-Data  NONE-Parity 1bit-Stop Format
#define		UCR1_8_O_1    				0x0F0     //8bits-Data  Odd-Parity  1bit-Stop Format
#define		UCR1_8_E_1     				0x0E0     //8bits-Data  Even-Parity 1bit-Stop Format
#define		UCR1_8_N_2     				0x88      //8bits-Data  NONE-Parity 2bits-Stop Format
#define		UCR1_7_O_2     				0x0B8     //7bits-Data  Odd-Parity  2bits-Stop Format
#define		UCR1_7_E_2     				0x0A8     //7bits-Data  Even-Parity 2bits-Stop Format
#define		UCR1_9_N_2     				0x0C8     //9bits-Data  NONE-Parity 2bits-Stop Format
#define		UCR1_8_O_2     				0x0F8     //8bits-Data  Odd-Parity  2bits-Stop Format
#define		UCR1_8_E_2     				0x0E8     //8bits-Data  Even-Parity 2bits-Stop Format
#define		UCR2Data       				0x0E4     //Enable TXEN RXEN BRGH RIE 
#define		UCR2Data1       			0x0Ef     //Enable TXEN RXEN BRGH RIE 
#define		BRGData        				38		  //12mhz      //Baud=19200,BRGH=1,N=38 


volatile	u8	gu8v_rx_guide;
volatile	u8	gu8v_tx_guide;
volatile	__byte_type	gu8v_uart_flag;
volatile	u8	array_uart_txbuff[7];
volatile	u8	array_uart_rxbuff[6];

/********************************************************************
Function:	Key_Scan
INPUT	:
OUTPUT	:	
NOTE	:   
********************************************************************/
void Uart_Init(void)
{
	//_pgs05 = 1;//set tx rx pin
	//_pgs04 = 0;//set tx rx pin
	//_pgs03 = 1;//set tx rx pin
	//_pgs02 = 0;//set tx rx pin			
	
    _ucr1 = UCR1_8_N_1;     //enable UART function,8bits-Data  NONE-Parity 1bit-Stop Format
    _ucr2 = UCR2Data1;       //enable TXEN,RXEN,Hige Speed Baud Rate, Receiver interrupt enable 
	_rie = 1;
	#ifndef	Debug
   		_brg = BRGData;         //9600 Baud Rate	
	#else
   		_brg = 38;         //9600 Baud Rate	
	#endif

	//_euti = 1;      			//UART interrupt enable
	//_ure = 1;      			//UART interrupt enable	
	//_uartmd = 1;
	//_usime = 1;
}

/********************************************************************
Function:	Key_Scan
INPUT	:
OUTPUT	:	
NOTE	:   
********************************************************************/
void Uart_off(void)
{
	_rie = 0;
	//_ren = 0;
	//_ucr1 = 0;
	//_ucr2 = 0;	
	//_sime = 0;
	
	//_pgs05 = 0;//set tx rx pin
	//_pgs04 = 0;//set tx rx pin
	//_pgs03 = 0;//set tx rx pin
	//_pgs02 = 0;//set tx rx pin			
}


/********************************************************************
Function:	UART_ISR
INPUT	:
OUTPUT	:	
NOTE	:   
********************************************************************/
//@------------uart--------------@
#pragma vector UART_ISR @ 0x2c
void UART_ISR(void)
//void __attribute((interrupt(UART_VECTOR)))  UART_ISR()	//for V3 of compiler
{	
	u8	lu8v_isr_temp0;
		//clear urf flag
	   	if(_perr || _nf || _ferr || _oerr)		// error found?
	   	{
	   	   lu8v_isr_temp0 = _usr;				//read USR to clear error flag 
	   	   lu8v_isr_temp0 =  _txr_rxr;				//read USR to clear error flag 	   	       
	   	}
	   	else									// no error found
	   	{
	   	   if(_rxif)							//RXR	data register has available	data
	   	   {
	   	   		//receive data from PC
				array_uart_rxbuff[gu8v_rx_guide] = _txr_rxr; 
				//
				if(array_uart_rxbuff[gu8v_rx_guide] == 10)	
				{
					gbv_rx_success = 1;
				}
					

				if(gu8v_rx_guide>=5)
				{
					gu8v_rx_guide = 0 ;					
				}
				else
				{
					gu8v_rx_guide ++ ;						
				}
	   	   	  
	   	   	  
	   	   	  //GCC_NOP();
	   	   	  _nop();
	   	   }
	   	   if(_txif)							//TXR	data register is empty
	   	   {
	   	   		gu8v_tx_guide++; 	   		
	   	   		if(gu8v_tx_guide<7)			//
	   	   		{
		   	   		_txr_rxr= array_uart_txbuff[gu8v_tx_guide];	  	   	   			
//	   	   			gu16v_an4_votage%256;		//send 0xaa to PC
	   	   		}
	   	   		else 
	   	   		{
//	   	   			gu8v_tx_guide=0;
					
	   	   		}
					
	   	   }
	   	}	
}


/********************************************************************
Function:	Key_Scan
INPUT	:
OUTPUT	:	
NOTE	:   
********************************************************************/
void	Uart_manage(void)
{
	if(gbv_rx_success == 1)
	{
		gbv_rx_success = 0;
		if(array_uart_rxbuff[0] == 47 && array_uart_rxbuff[5] == 10)
		{
			switch(array_uart_rxbuff[1])
			{
				//
				case	0xaa:

				break;
				
				default	:
				
				break;			
				
				
				
							
			}	
					
		}
		else
		{
			gu8v_rx_guide = 0;
			
		}
		
	}
	
}

/********************************************************************
Function:	
INPUT	:
OUTPUT	:	
NOTE	:   
********************************************************************/
void	Uart_TX_BH32F52640_ADC_AUTO_TEST(u16	lu16v_tx_data)
{
	array_uart_txbuff[0]	= 0x55;	
	array_uart_txbuff[1]	= 00;			
	array_uart_txbuff[2]	= lu16v_tx_data%256;	
	array_uart_txbuff[3]	= lu16v_tx_data/256;	
	array_uart_txbuff[4]	= 00;		
	array_uart_txbuff[5]	= array_uart_txbuff[0]+array_uart_txbuff[1]+array_uart_txbuff[2]+array_uart_txbuff[3]+array_uart_txbuff[4];	
	_txr_rxr= array_uart_txbuff[0];					
	gu8v_tx_guide=0;	
	
}

