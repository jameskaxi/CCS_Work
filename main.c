/*
 *  ======== main.c ========
 */

#include "BD_Bistatic_SAR.h"



void resetfunc()
{
}

void myfirstfunc()
{
	mulcoresyn();
}

void mylastfunc()
{
}


void main()
{
	int a=0;
	mulcoresyn();
	DSPInit();//DSP��ʼ��
	mulcoresyn();
	a=Raco_Vec_C6678_Get_Licence(0x11111111);//ƥ��ʸ���㷨���lic����lic��оƬ�й�
	while(a==0)
	{
		a=Raco_Vec_C6678_Get_Licence(0x11111111);
	}
	BIOS_start();     /* enable interrupts and start SYS/BIOS */
}





















