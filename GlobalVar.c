#include "BD_Bistatic_SAR.h"

SOCKET ssd = INVALID_SOCKET;
SOCKET csd = INVALID_SOCKET;
Uint32 NetRecvBuf[8][50];
Uint32 SRIORecvCnt;



/*-----------------------------------------------------------
 * 				������L2�еĲ�������
 *------------------------------------------------------------*/
#pragma SET_DATA_SECTION(".L2")

Uint32 SRIO_INTC_NUM 	= 0;//SRIO���ռ���
Uint8  IsEchoDataReady 	= 0;//srio���յ����ݺ󽫸ñ�־λ��1,�����˴�����ɺ󽫸ñ�־��0
Uint32 Echo_Procd_Index = 0;//��1~��3������ɼ�����ģ64�洢��������
Uint32 Echo_Send_Index 	= 0;//��4���緢�ͼ�����ģ64

complex	IFFT_Echo_L2[ECHODATA_POINT];//��ʱ�洢IFFT���
#pragma SET_DATA_SECTION()




/*-------------------------------------------------------------
 * ������L3�еĲ�������
 *-------------------------------------------------------------*/
#pragma SET_DATA_SECTION(".L3")

#pragma DATA_ALIGN (Srio_Recv_L3,	64);
#pragma DATA_ALIGN (NetSendFrames_L3,	64);
#pragma DATA_ALIGN (cFFTTwidTable_L3,	64);


#pragma LOCATION(Srio_Recv_L3,0xC010000)
#pragma RETAIN(Srio_Recv_L3)

SRIORECVFRAME 	Srio_Recv_L3;//���ڴ洢srio���յ���ԭʼ֡���ݣ�ping-pong����
NETSENDFRAME 	NetSendFrames_L3[64];//���ڴ洢������ɴ����͵����ݣ����64�飬���ڻ���
complex 		cFFTTwidTable_L3[ECHODATA_POINT];//IFFT��������

#pragma SET_DATA_SECTION()







