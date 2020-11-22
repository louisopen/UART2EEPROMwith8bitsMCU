//___________________________________________________________________
//___________________________________________________________________
// Description: This Application
//  Copyright@: 2019 BY Louis Huang / https://github.com/louisopen/
//   File Name: common.h
//Targer Board: MK8002D
//    MCU Body: HT66F317 HT66F318-28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on Hardware V10
//     History:
//___________________________________________________________________
//___________________________________________________________________
#ifndef _COMMON_H_
#define _COMMON_H_

#include "HT66F318.h"
#include "typedef.h"
#include "EEPROM.h"		//#include "IAP.h"
#include "Sys_Init.h"
#include "Uart.h"
#include "interrupt.h"

extern volatile	__byte_type	system_flag;
#define toggle_led		system_flag.bits.b0
#define toggle_buzzer	system_flag.bits.b1
#define sleep_request	system_flag.bits.b2


#endif
