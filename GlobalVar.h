#ifndef GLOBALVARDEFINE
#define GLOBALVARDEFINE

#include "BD_Bistatic_SAR.h"


extern SOCKET ssd;
extern SOCKET csd;
extern Uint32 NetRecvBuf[8][50];
extern Uint32 SRIORecvCnt;


#define ECHODATA_POINT	16*1024 //�ز�����
#define CUT_POINT	256		//��ȡ�ĵ���
#define	SENDBUF_NUM 64//���ͻ������ĸ���

#define EMIF1_BACE 0x74000000//CMDR�Ĵ������׵�ַ
#define EMIF2_BACE 0x78000000//CMDR�Ĵ������׵�ַ

//����CMDR�Ĵ���
#define CMDR_REG ((CMDR_TYPEDEF*)EMIF1_BACE)

//��ȡָ�����ϱ����ľ��Ե�ַ
#define Get_L2_Global_Address(addr, core_num) (0x10000000 + (core_num)*0x1000000 + (addr))

/*******************************�ṹ������*********************************************/
//���ò����ṹ��
typedef struct _ConfigParaStruct
{
	Uint32 uDataType;//����������
	Uint32 uDataLen;//���ݳ���
	Uint32 uWaveForm;//����ģʽ��
	Uint32 uCodeType;//�������ģʽ
	Uint32 uFarWavePulsWidth;//Զ�ನ������
	Uint32 uPRT;//PRT 6.25nmΪ��λ
	Uint32 uSampWinLen;//����������
	Uint32 uStartSampRange;//��ʼ�������� 6.25ns
	Uint32 uUploadSampNum;//ʵʱ�����ϴ�����
	Uint32 uUploadPeriod;//��Ϣ�ϴ�����
	Uint32 FHSSPoint;//������Ƶ����
	Uint32 uAGC1;//AGC������1
	Uint32 uAGC2;//AGC������2
	Uint32 uStdChnEnable;//��׼ͨ��ʹ��
	Uint32 uStdChnCtrl;//��׼ͨ������
	Uint32 AntennaScanMode;//����ת��ģʽ
	Uint32 PitchWaveNumOrRoundNum;//����������������תȦ��
	Uint32 AngleNum;//�Ƕȸ���
	float uAziScanVel_New;//������λ��ɨ���ٶ�
	float uEleScanVel_New;
	float uAziScanStart;//��λ��ɨ����ʼ�Ƕ�/������λ��1
	float uAziScanEnd;//��λ��ɨ����ֹ�Ƕ�/������λ��2
	float uAziScanVel;//��λ��ɨ���ٶ�/������λ��3
	float uEleScanStart;//������ɨ����ʼ�Ƕ�/������λ��4
	float uEleScanEnd;//������ɨ����ֹ�Ƕ�/������λ��5
	float uEleScanVel;//������ɨ���ٶ�/������λ��6
	Uint32 uReserved[8];
}ConfigParaStruct;


//SRIO�����֡��ʽ
#pragma pack(1)
typedef struct _SRIORECVFRAME
{
	/**********************ͨ��1*************************/
	Uint32 	CH1_FrameInfo;//ͨ��1֡ͷ��Ϣ 4B
	Uint8  	CH1_AntennaLoc[12];//ͨ��1����λ�� 12B
	Uint32 	CH1_FrameNum;//ͨ��1֡�� 4B
	Uint8	CH1_RPNNum;//ͨ��1RPN��  1B
	Uint8	CH1_TraceState;//ͨ��1�ĸ���״̬ 1B
	Uint8	CH1_MessagePhase;//ͨ��1�ĵ�����λ 1B
	Uint8 	CH1_SNR;//ͨ��1������� 1B
	Uint32	CH1_BDTimeScale;//ͨ��1��ʱ�� 4B
	Uint32	CH1_CarryWavePhase;//ͨ��1���ز���λ4B
	Uint32	CH1_Doppler;//ͨ��1�Ķ�����4B
	Uint8	CH1_SatelliteLoc[12];//ͨ��1������λ�� 12B
	Uint32	CH1_Angle;//ͨ��1�����Ƿ�λ��4B
	Uint8	CH1_Reserved[12];//ͨ��1���� 12B
	float	CH1_EchoData[ECHODATA_POINT*2];//ͨ��1�ز����� 128KB

	/**********************ͨ��2*************************/
	Uint32 	CH2_FrameInfo;//ͨ��1֡ͷ��Ϣ 4B
	Uint8  	CH2_AntennaLoc[12];//ͨ��1����λ�� 12B
	Uint32 	CH2_FrameNum;//ͨ��1֡�� 4B
	Uint8	CH2_RPNNum;//ͨ��1RPN��  1B
	Uint8	CH2_TraceState;//ͨ��1�ĸ���״̬ 1B
	Uint8	CH2_MessagePhase;//ͨ��1�ĵ�����λ 1B
	Uint8 	CH2_SNR;//ͨ��1������� 1B
	Uint32	CH2_BDTimeScale;//ͨ��1��ʱ�� 4B
	Uint32	CH2_CarryWavePhase;//ͨ��1���ز���λ4B
	Uint32	CH2_Doppler;//ͨ��1�Ķ�����4B
	Uint8	CH2_SatelliteLoc[12];//ͨ��1������λ�� 12B
	Uint32	CH2_Angle;//ͨ��1�����Ƿ�λ��4B
	Uint8	CH2_Reserved[12];//ͨ��1���� 12B
	float	CH2_EchoData[ECHODATA_POINT*2];//ͨ��1�ز����� 128KB

	/**********************ͨ��3*************************/
	Uint32 	CH3_FrameInfo;//ͨ��1֡ͷ��Ϣ 4B
	Uint8  	CH3_AntennaLoc[12];//ͨ��1����λ�� 12B
	Uint32 	CH3_FrameNum;//ͨ��1֡�� 4B
	Uint8	CH3_RPNNum;//ͨ��1RPN��  1B
	Uint8	CH3_TraceState;//ͨ��1�ĸ���״̬ 1B
	Uint8	CH3_MessagePhase;//ͨ��1�ĵ�����λ 1B
	Uint8 	CH3_SNR;//ͨ��1������� 1B
	Uint32	CH3_BDTimeScale;//ͨ��1��ʱ�� 4B
	Uint32	CH3_CarryWavePhase;//ͨ��1���ز���λ4B
	Uint32	CH3_Doppler;//ͨ��1�Ķ�����4B
	Uint8	CH3_SatelliteLoc[12];//ͨ��1������λ�� 12B
	Uint32	CH3_Angle;//ͨ��1�����Ƿ�λ��4B
	Uint8	CH3_Reserved[12];//ͨ��1���� 12B
	float	CH3_EchoData[ECHODATA_POINT*2];//ͨ��1�ز����� 128KB
}SRIORECVFRAME;

//���緢�͵�֡��ʽ
typedef struct _NETSENDFRAME
{
	Uint8	IsHaveData;//�Ƿ�������
	Uint32 	FrameInfo;//֡ͷ��Ϣ 4B
	Uint8  	AntennaLoc[12];//����λ�� 12B
	Uint8	Reseverd[16];//����	   16B

	/**********************ͨ��1*************************/
	Uint32 	CH1_FrameNum;//ͨ��1֡�� 4B
	Uint8	CH1_RPNNum;//ͨ��1RPN��  1B
	Uint8	CH1_TraceState;//ͨ��1�ĸ���״̬ 1B
	Uint8	CH1_MessagePhase;//ͨ��1�ĵ�����λ 1B
	Uint8 	CH1_SNR;//ͨ��1������� 1B
	Uint32	CH1_BDTimeScale;//ͨ��1��ʱ�� 4B
	Uint32	CH1_CarryWavePhase;//ͨ��1���ز���λ4B
	Uint32	CH1_Doppler;//ͨ��1�Ķ�����4B
	Uint8	CH1_SatelliteLoc[12];//ͨ��1������λ�� 12B
	Uint32	CH1_Angle;//ͨ��1�����Ƿ�λ��4B
	Uint8	CH1_Reserved[28];//ͨ��1���� 28B
	float	CH1_EchoData[CUT_POINT*2];//ͨ��1�ز����� 2KB

	/**********************ͨ��2*************************/
	Uint32 	CH2_FrameNum;//ͨ��1֡�� 4B
	Uint8	CH2_RPNNum;//ͨ��1RPN��  1B
	Uint8	CH2_TraceState;//ͨ��1�ĸ���״̬ 1B
	Uint8	CH2_MessagePhase;//ͨ��1�ĵ�����λ 1B
	Uint8 	CH2_SNR;//ͨ��1������� 1B
	Uint32	CH2_BDTimeScale;//ͨ��1��ʱ�� 4B
	Uint32	CH2_CarryWavePhase;//ͨ��1���ز���λ4B
	Uint32	CH2_Doppler;//ͨ��1�Ķ�����4B
	Uint8	CH2_SatelliteLoc[12];//ͨ��1������λ�� 12B
	Uint32	CH2_Angle;//ͨ��1�����Ƿ�λ��4B
	Uint8	CH2_Reserved[28];//ͨ��1���� 12B
	float	CH2_EchoData[CUT_POINT*2];//ͨ��1�ز����� 2KB

	/**********************ͨ��3*************************/
	Uint32 	CH3_FrameNum;//ͨ��1֡�� 4B
	Uint8	CH3_RPNNum;//ͨ��1RPN��  1B
	Uint8	CH3_TraceState;//ͨ��1�ĸ���״̬ 1B
	Uint8	CH3_MessagePhase;//ͨ��1�ĵ�����λ 1B
	Uint8 	CH3_SNR;//ͨ��1������� 1B
	Uint32	CH3_BDTimeScale;//ͨ��1��ʱ�� 4B
	Uint32	CH3_CarryWavePhase;//ͨ��1���ز���λ4B
	Uint32	CH3_Doppler;//ͨ��1�Ķ�����4B
	Uint8	CH3_SatelliteLoc[12];//ͨ��1������λ�� 12B
	Uint32	CH3_Angle;//ͨ��1�����Ƿ�λ��4B
	Uint8	CH3_Reserved[28];//ͨ��1���� 12B
	float	CH3_EchoData[CUT_POINT*2];//ͨ��1�ز����� 2KB
}NETSENDFRAME;


//CMDR�Ĵ�����
typedef struct CMDR_TYPEDEF_STRU
{
	volatile Uint16 REG_CMDR_SR_PENDING             ;//0X00000000
	volatile Uint16 REG_CMDR_SR_MASK_SET            ;//0X00000002
	volatile Uint16 REG_CMDR_SR_MASK_CLR            ;//0X00000004
	volatile Uint16 REG_CMDR_PUL0                   ;//0X00000006
	volatile Uint16 RESERVED0[12];
	volatile Uint16 REG_CMDR_CONFIGO_REG0           ;//0X00000020
	volatile Uint16 REG_CMDR_CONFIGO_REG1           ;//0X00000022
	volatile Uint16 REG_CMDR_CONFIGO_REG2           ;//0X00000024
	volatile Uint16 REG_CMDR_CONFIGO_REG3           ;//0X00000026
	volatile Uint16 REG_CMDR_CONFIGO_REG4           ;//0X00000028
	volatile Uint16 REG_CMDR_CONFIGO_REG5           ;//0X0000002a
	volatile Uint16 REG_CMDR_CONFIGO_REG6           ;//0X0000002c
	volatile Uint16 REG_CMDR_CONFIGO_REG7           ;//0X0000002e
	volatile Uint16 REG_CMDR_CONFIGO_REG8           ;//0X00000030
	volatile Uint16 REG_CMDR_CONFIGO_REG9           ;//0X00000032
	volatile Uint16 RESERVED1[6];
	volatile Uint16 REG_CMDR_DATAO_REG0             ;//0X00000040
	volatile Uint16 REG_CMDR_DATAO_REG1             ;//0X00000042
	volatile Uint16 REG_CMDR_DATAO_REG2             ;//0X00000044
	volatile Uint16 REG_CMDR_DATAO_REG3             ;//0X00000046
	volatile Uint16 REG_CMDR_DATAO_REG4             ;//0X00000048
	volatile Uint16 REG_CMDR_DATAO_REG5             ;//0X0000004a
	volatile Uint16 REG_CMDR_DATAO_REG6             ;//0X0000004c
	volatile Uint16 REG_CMDR_DATAO_REG7             ;//0X0000004e
	volatile Uint16 REG_CMDR_DATAO_REG8             ;//0X00000050
	volatile Uint16 REG_CMDR_DATAO_REG9             ;//0X00000052
	volatile Uint16 RESERVED2[6];
	volatile Uint16 REG_CMDR_CONFIGI_REG0           ;//0X00000060
	volatile Uint16 REG_CMDR_CONFIGI_REG1           ;//0X00000062
	volatile Uint16 REG_CMDR_CONFIGI_REG2           ;//0X00000064
	volatile Uint16 REG_CMDR_CONFIGI_REG3           ;//0X00000066
	volatile Uint16 REG_CMDR_CONFIGI_REG4           ;//0X00000068
	volatile Uint16 REG_CMDR_CONFIGI_REG5           ;//0X0000006a
	volatile Uint16 REG_CMDR_CONFIGI_REG6           ;//0X0000006c
	volatile Uint16 REG_CMDR_CONFIGI_REG7           ;//0X0000006e
	volatile Uint16 REG_CMDR_CONFIGI_REG8           ;//0X00000070
	volatile Uint16 REG_CMDR_CONFIGI_REG9           ;//0X00000072
	volatile Uint16 RESERVED3[6];
	volatile Uint16 REG_CMDR_DATAI_REG0             ;//0X00000080
	volatile Uint16 REG_CMDR_DATAI_REG1             ;//0X00000082
	volatile Uint16 REG_CMDR_DATAI_REG2             ;//0X00000084
	volatile Uint16 REG_CMDR_DATAI_REG3             ;//0X00000086
	volatile Uint16 REG_CMDR_DATAI_REG4             ;//0X00000088
	volatile Uint16 REG_CMDR_DATAI_REG5             ;//0X0000008a
	volatile Uint16 REG_CMDR_DATAI_REG6             ;//0X0000008c
	volatile Uint16 REG_CMDR_DATAI_REG7             ;//0X0000008e
	volatile Uint16 REG_CMDR_DATAI_REG8             ;//0X00000090
	volatile Uint16 REG_CMDR_DATAI_REG9             ;//0X00000092
}CMDR_TYPEDEF;


typedef  struct _complex
{
	float     re;
	float     im;
}complex;

typedef  struct _complex_int16
{
	short     re;
	short     im;
}complex_int16;

typedef struct _NetDataInfoStruct
{
	Uint32 *pDataAddr;
	Uint32 uDataLen;
}NetDataInfoStruct;



/*******************************ȫ�ֱ�������*********************************************/
extern far				Uint32 SRIO_INTC_NUM ;//����srio�жϼ���
extern far				Uint8  IsEchoDataReady;//srio���յ����ݺ󽫸ñ�־λ��1,�����˴�����ɺ󽫸ñ�־��0
extern far				Uint32 Echo_Procd_Index;//��1~��3������ɼ�����ģ64�洢��������
extern far				Uint32 Echo_Send_Index;//��4���緢�ͼ�����ģ64

extern complex			IFFT_Echo_L2[ECHODATA_POINT];//��ʱ�洢IFFT���

extern SRIORECVFRAME 	Srio_Recv_L3;//���ڴ洢srio���յ���ԭʼ֡����
extern NETSENDFRAME 	NetSendFrames_L3[SENDBUF_NUM];//���ڴ洢������ɴ����͵����ݣ����64�飬���ڻ���
extern complex 			cFFTTwidTable_L3[ECHODATA_POINT];//IFFT��������

#endif







