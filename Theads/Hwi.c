#include "BD_Bistatic_SAR.h"

///*******************************************************
// * ����˵����ͨ��L2��Ե�ַ��ã�ָ���˵�L2���ݵľ��Ե�ַ����
// *******************************************************/
//Uint32 Get_L2_Global_Address(Uint32 addr, int core_num)
//{
//    	Uint32 Globle_L2_addr;
//    	Globle_L2_addr = 0x10000000 + core_num*0x1000000 +addr;
//    	return  Globle_L2_addr;
//}



/*******************************************************
 * ����˵����SRIO�жϴ�����(��0����srio�ж�)
 *******************************************************/
void SrioDoorBell_Isr_handler()
{
	int i= 0;
	//ʧЧCache
	Cache_inv((Uint32 *)&Srio_Recv_L3, sizeof(Srio_Recv_L3), Cache_Type_L2,TRUE);

	//�ñ�־λ����1����2����3,��4֪ͨ�䴦������
	for(i = 1; i <= 4; i++)
	{
		*((Uint8*)Get_L2_Global_Address((Uint32)&IsEchoDataReady,i)) = 1;
	}

	//Mailbox_post(hProcBufMail,(Uint32 *)&Srio_Recv_L3,BIOS_WAIT_FOREVER);
	C6678_Srio_DoorbellInt_Clear(DNUM,0);//���ж�
}



