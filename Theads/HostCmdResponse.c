#include "BD_Bistatic_SAR.h"

//��������
void ConfigFPGA(ConfigParaStruct*  CFGParam);
void CommandToFPGA(unsigned char cmd);


/*******************************************************
 * ����˵������λ��ָ��������������������ȼ������������������
 *******************************************************/
void HostCmdResponse()
{
	NetDataInfoStruct RecvCmd;//����λ���˽��յ�������
	ConfigParaStruct  CFGParam;//���ò���
	while(1)
	{
		Mailbox_pend(hHostCmdResponseMail,&RecvCmd,BIOS_WAIT_FOREVER);
		if(RecvCmd.pDataAddr[0] == 0x5a5a5a5a) //0x5a5a5a5a Ϊָ��
		{
			switch (RecvCmd.pDataAddr[2])
			{
			case 1://�Լ�
				CommandToFPGA(0x10);
				Mailbox_post(hNetSendMail,&RecvCmd,BIOS_WAIT_FOREVER);
				break;
			case 3://��ʼ
				CommandToFPGA(0x11);
				Mailbox_post(hNetSendMail,&RecvCmd,BIOS_WAIT_FOREVER);
				break;
			case 4://ֹͣ
				CommandToFPGA(0x12);
				Mailbox_post(hNetSendMail,&RecvCmd,BIOS_WAIT_FOREVER);
				break;
			default:
				break;
			}

		}
		else if(RecvCmd.pDataAddr[0] == 0x6b6b6b6b) //0x6b6b6b6b Ϊϵͳ����
		{
			//������λ�������ò���
			memcpy((void*)&CFGParam, (void*)RecvCmd.pDataAddr, RecvCmd.uDataLen);
			//��FPGA���ò���
			ConfigFPGA(&CFGParam);
			ProcInit();//��ʼ���㷨
			Mailbox_post(hNetSendMail,&RecvCmd,BIOS_WAIT_FOREVER);
		}
	}
}

/*******************************************************
 * ����˵������λ��͸�����ƴ�Ӻ���������ƥ������FPGA�Ĳ���
 *******************************************************/
void DegreeSplit(float srcStart, float srcEnd, unsigned char* HXDW, unsigned char* HXDW1, unsigned char* HXDW2)
{
	unsigned short degreeStartNum, degreeEndNum;

	degreeStartNum = 2048 + srcStart/0.1;
	degreeEndNum = 2048 + srcEnd/0.1 ;
	*HXDW = (unsigned char)((degreeStartNum&0xF00)>>4 | (degreeEndNum&0xF00)>>8);
	*HXDW1 = (unsigned char)(degreeStartNum&0xff);
	*HXDW2 = (unsigned char)(degreeEndNum&0xff);
}

/*******************************************************
 * ����˵������λ�������ٶ�ƴ�ӣ�����ƥ������FPGA�Ĳ���
 *******************************************************/
void VelocitySplit(float HXSRC, float FYSRC, unsigned char* HXFY_H, unsigned char* HXCS_L, unsigned char* FYCS_L)
{
	unsigned short HXSRC_NUM, FYSRC_NUM;
	HXSRC_NUM = HXSRC/0.02;
	FYSRC_NUM = FYSRC/0.02;
	*HXFY_H = (unsigned char)((HXSRC_NUM&0xF00)>>4 | (FYSRC_NUM&0xF00)>>8);
	*HXCS_L = (unsigned char)(HXSRC_NUM&0xff);
	*FYCS_L = (unsigned char)(FYSRC_NUM&0xff);
}

/*******************************************************
 * ����˵����ͨ��EMIF��FPGA���ò���
 *******************************************************/
void ConfigFPGA(ConfigParaStruct*  CFGParam)
{
	int i = 0;
	unsigned char HXDW, HXDW1, HXDW2, FXDW, FXDW1, FXDW2,HXFY_H,HXCS_L,FYCS_L;
	//��fpga���ò���
	DegreeSplit(CFGParam->uAziScanStart, CFGParam->uAziScanEnd, &HXDW, &HXDW1, &HXDW2);
	DegreeSplit(CFGParam->uEleScanStart, CFGParam->uEleScanEnd, &FXDW, &FXDW1, &FXDW2);
	VelocitySplit(CFGParam->uAziScanVel, CFGParam->uEleScanVel, &HXFY_H, &HXCS_L, &FYCS_L);
//	CMDR_REG->REG_CMDR_SR_MASK_CLR |= 0x01;//ʹ��0���ж�
//	//���͵�һ֡����
//	CMDR_REG->REG_CMDR_CONFIGO_REG0 = 0x20EB;
//	CMDR_REG->REG_CMDR_CONFIGO_REG1 = 0x0113;
//	CMDR_REG->REG_CMDR_CONFIGO_REG2 = 0x0042;
//	CMDR_REG->REG_CMDR_CONFIGO_REG3 = 0x0000;
//
//	CMDR_REG->REG_CMDR_CONFIGO_REG4 = 15*(CFGParam->uStartSampRange&0x3f)*20/18.75;//������ʼ�㣿
//	CMDR_REG->REG_CMDR_CONFIGO_REG5 = 0x0000;//������ʼ��
//	CMDR_REG->REG_CMDR_CONFIGO_REG6 = 256 << (CFGParam->uSampWinLen&0x3);//���������� 1024
//	CMDR_REG->REG_CMDR_CONFIGO_REG7 = 0x2800;//������ʽ��
//	if (CFGParam->uSampWinLen&0x3 == 3)//˵����2048���������Ϊ40us
//	{
//		CFGParam->uPRT = 3;
//	}
//	CMDR_REG->REG_CMDR_CONFIGO_REG8 = (((CFGParam->uPRT&0x3)*5)+25)*1000/6.25;//prt����,6.25nmΪ��λ 4000
//	CMDR_REG->REG_CMDR_CONFIGO_REG9 = 0x0000;
//	CMDR_REG->REG_CMDR_DATAO_REG0 = (HXDW<<8 | AntennaScanMode[CFGParam->AntennaScanMode&0x7]);//�ŷ�����ģʽ
//	CMDR_REG->REG_CMDR_DATAO_REG1 = (HXDW2<<8 | HXDW1);
//	CMDR_REG->REG_CMDR_DATAO_REG2 = (FXDW1<<8 | FXDW);
//	CMDR_REG->REG_CMDR_DATAO_REG3 = (HXFY_H<<8|FXDW2);
//	CMDR_REG->REG_CMDR_DATAO_REG4 = (FYCS_L<<8|HXCS_L);
//	CMDR_REG->REG_CMDR_DATAO_REG5 = (unsigned short)((CFGParam->AngleNum<<8)|CFGParam->PitchWaveNumOrRoundNum);
//	CMDR_REG->REG_CMDR_DATAO_REG6 = (unsigned short)(2048 + CFGParam->uAziScanStart*10);
//	CMDR_REG->REG_CMDR_DATAO_REG7 = (unsigned short)(2048 + CFGParam->uAziScanEnd*10);
//	CMDR_REG->REG_CMDR_DATAO_REG8 = (unsigned short)(2048 + CFGParam->uAziScanVel*10);
//	CMDR_REG->REG_CMDR_DATAO_REG9 = (unsigned short)(2048 + CFGParam->uEleScanStart*10);
//
//	//DSPͨ��CMDR�Ĵ�����REG_CMDR_PUL0����Koala�����ж�
//	CMDR_REG->REG_CMDR_PUL0 |= 0x01;
//	//gai
//	while(!(CMDR_REG->REG_CMDR_SR_PENDING & 0x01));//�ȴ�fpga�˵�1���ж�
//	CMDR_REG->REG_CMDR_SR_PENDING |= 0x01;//����жϱ�־λ
//	//���͵ڶ�֡����
//	CMDR_REG->REG_CMDR_CONFIGO_REG0 = 0x12EB;
//	CMDR_REG->REG_CMDR_CONFIGO_REG1 = 0x0213;
//	CMDR_REG->REG_CMDR_CONFIGO_REG2 = 0x0042;
//	CMDR_REG->REG_CMDR_CONFIGO_REG3 = 0x0000;
//
//	for (i = 0; i < CFGParam->AngleNum-4; i++)
//	{
//		*(&CMDR_REG->REG_CMDR_CONFIGO_REG4+i) = (unsigned short)(2048+ *((float*)(&CFGParam->uEleScanEnd + i))*10);
//	}
//	CMDR_REG->REG_CMDR_DATAO_REG0 = (unsigned short)(2048+ *((float*)(&CFGParam->uEleScanEnd + 6))*10);
//	CMDR_REG->REG_CMDR_DATAO_REG1 = (unsigned short)(CFGParam->uAziScanVel_New/0.02);//��λɨ���ٶ�,��λ����Ҫ������
//	CMDR_REG->REG_CMDR_DATAO_REG2 = (unsigned short)((CFGParam->PitchWaveNumOrRoundNum&0xff)|(CFGParam->AntennaScanMode>7)<<8);  //|����ɨ��ģʽ�߰�λ);
//	CMDR_REG->REG_CMDR_DATAO_REG3 = (unsigned short)(((CFGParam->uCodeType+1)&0xff)<<8 | ((CFGParam->uWaveForm+1)&0xff));//�������ģʽ������ģʽ
//	CMDR_REG->REG_CMDR_DATAO_REG4 = (unsigned short)(CFGParam->uFarWavePulsWidth&0xff == 5)?1:(((CFGParam->uFarWavePulsWidth+1)&0xff)*10);
//	if (CFGParam->uFarWavePulsWidth == 5)
//		CMDR_REG->REG_CMDR_DATAO_REG4 = 1;
//	else
//		CMDR_REG->REG_CMDR_DATAO_REG4 = (unsigned short)(((CFGParam->uFarWavePulsWidth+1)&0xff)*10);
//
//	CMDR_REG->REG_CMDR_DATAO_REG5 = (unsigned short)(CFGParam->uEleScanVel_New/0.02);//����ɨ���ٶ�
//	CMDR_REG->REG_CMDR_DATAO_REG6 = (unsigned short)(((CFGParam->uAGC2)&0xFF)<<8 | ((CFGParam->uAGC2)&0xFF));//AGC1��AGC2
//	CMDR_REG->REG_CMDR_DATAO_REG7 = (((CFGParam->uStdChnCtrl)&0xFF)<<8 | ((CFGParam->uStdChnEnable)&0xFF));//У׼ͨ��ʹ�ܣ���λ����ѡ�񣨸�λ��
//	//TEST
//	//DSPͨ��CMDR�Ĵ�����REG_CMDR_PUL0����Koala�����ж�
//	CMDR_REG->REG_CMDR_PUL0 |= 0x01;
//	while(!(CMDR_REG->REG_CMDR_SR_PENDING & 0x01));//�ȴ�fpga�˵�1���ж�
//	CMDR_REG->REG_CMDR_SR_PENDING |= 0x01;//����жϱ�־λ
}

/*******************************************************
 * ����˵����ͨ��EMIF��FPGA����ָ��
 *******************************************************/
void CommandToFPGA(unsigned char cmd)
{
//	CMDR_REG->REG_CMDR_CONFIGO_REG0 = 0x00EB;
//	CMDR_REG->REG_CMDR_CONFIGO_REG1 = 0x0100|cmd;
//	CMDR_REG->REG_CMDR_CONFIGO_REG2 = 0x0008;
//	CMDR_REG->REG_CMDR_CONFIGO_REG3 = 0x0000;
//
//	//DSPͨ��CMDR�Ĵ�����REG_CMDR_PUL0����Koala�����ж�
//	CMDR_REG->REG_CMDR_PUL0 |= 0x01;
//	while(!(CMDR_REG->REG_CMDR_SR_PENDING & 0x01));//�ȴ�fpga�˵�1���ж�
//	CMDR_REG->REG_CMDR_SR_PENDING |= 0x01;//����жϱ�־λ
}

