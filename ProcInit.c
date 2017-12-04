
#include <math.h>
#include "BD_Bistatic_SAR.h"

void tw_gen (float *w, int n);//��������������ת����

/*******************************************************
 * ����˵���������ʼ��
 *******************************************************/
void ProcInit()
{
	int i = 0;
	if(DNUM == 0)
	{
		//������ת����
		tw_gen ((float *)cFFTTwidTable_L3, ECHODATA_POINT);
		Cache_wb((Uint32 *)cFFTTwidTable_L3, ECHODATA_POINT*2*4, Cache_Type_L2,TRUE);
	}
	if (DNUM == 0)
	{
		//����1����2����3,��4��ձ�־λ
		for(i = 1; i <= 4; i++)
		{
			*((Uint8*)Get_L2_Global_Address((Uint32)&IsEchoDataReady,i)) = 0;
			*((Uint32*)Get_L2_Global_Address((Uint32)&Echo_Procd_Index,i)) = 0;
		}

		//��0�����ͼ�����0
		Echo_Send_Index = 0;
	}

}

void tw_gen (float *w, int n)
{
    int i, j, k;
    const double PI = 3.141592654;

    for (j = 1, k = 0; j <= n >> 2; j = j << 2)
    {
        for (i = 0; i < n >> 2; i += j)
        {
#ifdef _LITTLE_ENDIAN
            w[k]     = (float) -sin (2 * PI * i / n);
            w[k + 1] = (float)  cos (2 * PI * i / n);
            w[k + 2] = (float) -sin (4 * PI * i / n);
            w[k + 3] = (float)  cos (4 * PI * i / n);
            w[k + 4] = (float) -sin (6 * PI * i / n);
            w[k + 5] = (float)  cos (6 * PI * i / n);
#else
            w[k]     = (float) cos (2 * PI * i / n);
            w[k + 1] = (float) sin (2 * PI * i / n);
            w[k + 2] = (float) cos (4 * PI * i / n);
            w[k + 3] = (float) sin (4 * PI * i / n);
            w[k + 4] = (float) cos (6 * PI * i / n);
            w[k + 5] = (float) sin (6 * PI * i / n);
#endif
            k += 6;
        }
    }
}
