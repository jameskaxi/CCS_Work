/*
 * utils.c
 *
 *  Created on: 2016-7-18
 *      Author: Administrator
 */
#include "BD_Bistatic_SAR.h"

#pragma SET_DATA_SECTION(".L2")
volatile unsigned short LocalSynFlagx[8]={0,0,0,0,0,0,0,0};

volatile unsigned short * pFlagFromCore0;
volatile unsigned short * pFlagToCore0x;
#pragma SET_DATA_SECTION()

/*******************************************************
 * ����˵�����˺�ͬ���������ڸ����˵�L2�Ͽ���һ�οռ䣬ÿ����ִ�е���λ�ö��������˷���Ŀռ��ָ��λ��дһ����־λ������ѭ������ǲ���ÿ���˶�ִ�е���λ�ã�
 * 		     ���������������L2��дһ����־�������˼�⵽�����־��ʼ�������ִ�С�
 *******************************************************/
void mulcoresyn()
{
	unsigned int sum=0;
	/*******************************************************************
	 * �Ƚ����Ľ϶��cycle
	 *******************************************************************/
//	(pFlagToCore0x[0]==pFlagToCore0x[1])&&
//	(pFlagToCore0x[0]==pFlagToCore0x[2])&&
//	(pFlagToCore0x[0]==pFlagToCore0x[3])&&
//	(pFlagToCore0x[0]==pFlagToCore0x[4])&&
//	(pFlagToCore0x[0]==pFlagToCore0x[5])&&
//	(pFlagToCore0x[0]==pFlagToCore0x[6])&&
//	(pFlagToCore0x[0]==pFlagToCore0x[7]))
	//141 cycle
//	if(RankMarker.OneOrAllCore==0)
	{
		pFlagToCore0x=(unsigned short * )(((unsigned int)&LocalSynFlagx[0]|0x10000000)+DNUM*2);
		(*pFlagToCore0x)++;
		if(DNUM==0)
		{
			while(1)
			{
				//�ж�������53 cycle
				sum = pFlagToCore0x[0]+pFlagToCore0x[1]+pFlagToCore0x[2]+pFlagToCore0x[3]+
					  pFlagToCore0x[4]+pFlagToCore0x[5]+pFlagToCore0x[6]+pFlagToCore0x[7];
				if(pFlagToCore0x[0]==(sum>>3))
				{
					//core0 д7�Σ�53cycle
					*(unsigned short*)((unsigned int)LocalSynFlagx|0x11000000)=1;
					*(unsigned short*)((unsigned int)LocalSynFlagx|0x12000000)=1;
					*(unsigned short*)((unsigned int)LocalSynFlagx|0x13000000)=1;
					*(unsigned short*)((unsigned int)LocalSynFlagx|0x14000000)=1;
					*(unsigned short*)((unsigned int)LocalSynFlagx|0x15000000)=1;
					*(unsigned short*)((unsigned int)LocalSynFlagx|0x16000000)=1;
					*(unsigned short*)((unsigned int)LocalSynFlagx|0x17000000)=1;

					break;
				}
				else;
			}
		}
		else
		{
			while(LocalSynFlagx[0]==0)
			{
				//do nothing
			}
			LocalSynFlagx[0]=0;
		}
	}
//	else;
}
