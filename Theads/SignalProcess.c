#include "BD_Bistatic_SAR.h"


/************************************��������**********************************/
void SendDataByNet();
void Process();
extern void DSPF_sp_ifftSPxSP (int N, float *ptr_x, float *ptr_w, float *ptr_y,
    unsigned char *brev, int n_min, int offset, int n_max);
/***************************************************************************/


/*******************************************************
 * ����˵�������ݴ����̣߳����к�0ͨ����������λ���������ݣ���1~4����IFFT�任��
 * ����������
 *******************************************************/
void SignalProcess()
{
	while(1)
	{
		if((DNUM==5) || (DNUM==6) || (DNUM == 7))//��0����5~7��������,����
		{
			Mailbox_pend(hProcBufMail,NULL,BIOS_WAIT_FOREVER);
		}
		else if (DNUM == 0)//ͨ����������λ����������
		{
			if (NetSendFrames_L3[Echo_Send_Index%SENDBUF_NUM].IsHaveData == 1)//�����ǰ����׼�����ˣ�����
			{
				SendDataByNet();//ͨ�����緢��
				NetSendFrames_L3[Echo_Send_Index%SENDBUF_NUM].IsHaveData = 0;//��־��0
				Echo_Send_Index++;//������1
			}
		}
		else//��1~��4�ȴ�IsEchoDataReady�źŽ������ݴ���
		{
			if (IsEchoDataReady)
			{
				Process();//���ݴ���
				IsEchoDataReady = 0;//���־λ
			}
		}
	}
}



/*******************************************************
 * ����˵������4������ͷ������Ϣ��NetSendFrames_L3������
 *******************************************************/
void CopyHeadInfo()
{
	//ͷ����Ϣ
	NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].IsHaveData = 1;
	NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].FrameInfo = 0x5b5b5b5b;//֡ͷ��Ϣ 4B
	memcpy((void*)NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].AntennaLoc,
			(void*)Srio_Recv_L3.CH1_AntennaLoc, sizeof(Srio_Recv_L3.CH1_AntennaLoc));
	//ͨ��1������Ϣ
	memcpy((void*)&NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH1_FrameNum,
			(void*)&Srio_Recv_L3.CH1_FrameNum, ((Uint32)&Srio_Recv_L3.CH1_Reserved) - (Uint32)(&Srio_Recv_L3.CH1_FrameNum));

	//ͨ��2�Ĳ�����Ϣ
	memcpy((void*)&NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH2_FrameNum,
			(void*)&Srio_Recv_L3.CH2_FrameNum, (Uint32)(&Srio_Recv_L3.CH2_Reserved) - (Uint32)(&Srio_Recv_L3.CH2_FrameNum));

	//ͨ��3������Ϣ
	memcpy((void*)&NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH3_FrameNum,
			(void*)&Srio_Recv_L3.CH3_FrameNum, (Uint32)(&Srio_Recv_L3.CH3_Reserved) - (Uint32)(&Srio_Recv_L3.CH3_FrameNum));

}
/*******************************************************
 * ����˵�������ݴ���
 * 			���к�1~3��ز����ݽ���IFFT���㽫������͵�NetSendFrames_L3������
 * 			��4����ͷ��������Ϣ��������������
 *******************************************************/
void Process()
{
	if (DNUM == 1)
	{
		DSPF_sp_ifftSPxSP (ECHODATA_POINT, (float*)Srio_Recv_L3.CH1_EchoData,
				(float*)cFFTTwidTable_L3, (float*)IFFT_Echo_L2, 0, 0, 0, 0);
		//ͨ��1�ز����� **���ȶԲ���
		memcpy((void*)NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH1_EchoData,
					(void*)IFFT_Echo_L2, sizeof(NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH1_EchoData));
	}
	else if (DNUM == 2)
	{
		DSPF_sp_ifftSPxSP (ECHODATA_POINT, (float*)Srio_Recv_L3.CH2_EchoData,
				(float*)cFFTTwidTable_L3, (float*)IFFT_Echo_L2, 0, 0, 0, 0);
		//ͨ��2�ز�����
		memcpy((void*)NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH2_EchoData,
						(void*)IFFT_Echo_L2, sizeof(NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH2_EchoData));
	}
	else if (DNUM == 3)
	{
		DSPF_sp_ifftSPxSP (ECHODATA_POINT, (float*)Srio_Recv_L3.CH3_EchoData,
				(float*)cFFTTwidTable_L3, (float*)IFFT_Echo_L2, 0, 0, 0, 0);
		//ͨ��3�ز�����
		memcpy((void*)NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH3_EchoData,
							(void*)IFFT_Echo_L2, sizeof(NetSendFrames_L3[Echo_Procd_Index%SENDBUF_NUM].CH3_EchoData));
	}
	else if (DNUM == 4)
	{
		CopyHeadInfo();
	}
	Echo_Procd_Index++;//
}

/*******************************************************
 * ����˵������0ͨ����������λ������֡����
 *******************************************************/
void SendDataByNet()
{
	NetDataInfoStruct SendDataInfo;
	Uint32 uSendedLen,uTmp;
	SendDataInfo.pDataAddr = (Uint32*)&NetSendFrames_L3[Echo_Send_Index%SENDBUF_NUM].FrameInfo;
	SendDataInfo.uDataLen = sizeof(NETSENDFRAME) - 1;//ʵ��ÿ֡���͵ĳ���
	uSendedLen = 0;
	fdOpenSession( (HANDLE)Task_self());
	do
	{
		uTmp=send(csd,(char*)SendDataInfo.pDataAddr+uSendedLen,SendDataInfo.uDataLen-uSendedLen,0);
		uSendedLen += uTmp;
	}while(uSendedLen < SendDataInfo.uDataLen);
}
