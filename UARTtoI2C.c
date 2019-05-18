//___________________________________________________________________
//___________________________________________________________________
//   Copyright: 2019 For MK Master INC.
//   File Name: Main program of the application
// Description: 
//Targer Board: 
//    MCU Body: HT66F318 28ssop
//      Author: Louis Huang
//        Date: 2019/05/18
//     Version: V00 on V10 hardware
//     History:
//___________________________________________________________________
//___________________________________________________________________
#include "HT66F318.h"
#include "common.h"

void main()
{
	//u8	i;
	//�P�_�O�_�O�W�q�_��Ϊ̬O���`���p�U���D���`�_��
	//�p�G���߫h����W�q��l�ưʧ@�A�Ϥ��h����WDT���X��l��
	if(_to ==0 || _pdf ==0)									//WDT1	Reset
	{	
		//�W�q�_��Ϊ̬O���`���p�U���D���`�_��
		//RAM
		fun_RamInit();
		fun_PowerOnInit();	//�Ĥ@���W�q�Υ��`reset pin                             								
	}
	else													
	{
		//WDT ���X�_��
		fun_ResetInit();
	}
  //  TEST_LCD()  ;   
	while(1)
	{	
		//�M���ݪ���
		//GCC_CLRWDT();
		_clrwdt();
		//�Ω�p��
		//fun_500ms_polling();
		
		//�P�_�O�_�n�i�J�ίv
		/*
		if(gu8v_halt_time<LU8C_HALT_TIME)
		{

			if(_ptm2af)
			{
				//10ms �`��					
				_ptm2af = 0;
				gbv_work_polling = 0;
				sys_time();
				fun_Key_Scan();		
				fun_cal_pressure(gu16v_pressure_output);
				Sys_lower_power();	
				
				switch(gu8v_work_mode)
				{
					case	Sys_Normal_mode:
						Sys_Normal();				
					break;
					case	Sys_Power_On_mode:
						Sys_Power_On();
					break;
					case	Sys_HALT_mode:
						Sys_HALT();
					break;			
					default :
						Change_Mode(Sys_Normal_mode);
					break;	
				}
			}
			 gbv_500ms = 0;		
			 gbv_250ms = 0;		 			
		}
		else
		{
			Change_Mode(Sys_Normal_mode);
 			fun_PrepareToHalt();
		}
		*/
	}
}