/*
 * my.h
 *
 *  Created on: 2012-2-20
 *      Author: GuoHongZhu
 *  modefied by Guohongzhu�� 2013-11-16:
 *   1 �������FFT�ӿ�˵��������ԭλ����ͷ�ԭλ���㣩
 *   2 ����һ������ֵ��������Ǻ������ģ��Ľӿ�����
 *  			�����lib����
 *  modefied by Guohongzhu�� 2013-11-27:
 *  �����˳������FFT��ʵ��,����ֻ�����˷�ԭλ�ļ��㣬���֧��128K���FFT
 */

#ifndef MY_H_
#define MY_H_

#include <ti/csl/tistdtypes.h>
#include "../../C6678_driver/c6678.h"

typedef struct complex
{
	float re;
	float im;
}COMPLEX_TYPE;
//˵��:������2��float�����,��һ��float��ʾʵ��,�ڶ���float��ʾ�鲿
//���Ǻ������ı��С

extern const float exptable[16384+2];
extern const float cos_sin_table[16384+4];
/***************************************************************************************
 *	������:		void CplxMulCplx(float*pX, float*pY, float*pZ, unsigned int n)
 *	��������: 	ʵ�����������������
 *	����˵��:	float*pX:��һ����������
 *		    	float*pY:�ڶ�����������
 *		    	float*pZ:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX��pY
 *		    	unsigned int n:���������,��Ҫ����:�������n>=12,���������������4�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxMulCplx(float*pX, float*pY, float*pZ, unsigned int n);


/***************************************************************************************
 *	������:		void CplxAddCplx(float*pX, float*pY, float*pZ, unsigned int n)
 *	��������: 	ʵ�����������������
 *	����˵��:	float*pX:��һ����������
 *		    	float*pY:�ڶ�����������
 *		    	float*pZ:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX��pY
 *		    	unsigned int n:���������,��Ҫ����:�������n>=12,���������������4�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxAddCplx(float*pX, float*pY, float*pZ, unsigned int n);


/***************************************************************************************
 *	������:		void CplxSubCplx(float*pX, float*pY, float*pZ, unsigned int n)
 *	��������: 	ʵ�����������������
 *	����˵��:	float*pX:��һ����������
 *		    	float*pY:�ڶ�����������
 *		    	float*pZ:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX��pY
 *		    	unsigned int n:���������,��Ҫ����:�������n>=12,���������������4�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxSubCplx(float*pX, float*pY, float*pZ, unsigned int n);


/***************************************************************************************
 *	������:		void CplxConj(float*pX, float*pY, unsigned int n)
 *	��������: 	ʵ�ָ�����������
 *	����˵��:	float*pX:���븴������
 *		    	float*pY:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX
 *		    	unsigned int n:���������,��Ҫ����:�������n>=24,���������������8�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxConj(float*pX, float*pY, unsigned int n);


/***************************************************************************************
 *	������:		void CplxMulConst(float*pX, float*pY, float fVal, unsigned int n)
 *	��������: 	ʵ�ָ������Գ�������
 *	����˵��:	float*pX:��һ����������
 *		    	float*pY:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX
 *		    	float fVal: �͸�����˵ĳ���
 *		    	unsigned int n:���������,��Ҫ����:�������N>=24,���������������8�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxMulConst(float*pX, float*pY, float fVal, unsigned int n);


/***************************************************************************************
 *	������:		CplxAddConst(float*pX, float fVal, float*pZ, unsigned int n)
 *	��������: 	ʵ�ָ����ӳ�������
 *	����˵��:	float*pX:��һ����������
 *		    	float fVal: �͸�����ӵĳ���
 *		    	float*pZ:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX
 *		    	unsigned int n:���������,��Ҫ����:�������N>=24,���������������8�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxAddConst(float*pX, float fVal, float*pZ, unsigned int n);

/***************************************************************************************
 *	������:		CplxSubConst(float*pX, float fVal, float*pZ, unsigned int n)
 *	��������: 	ʵ�ָ�������������
 *	����˵��:	float*pX:����ĸ���������ʼ��ַ
 *		    	float fVal: �͸�������ĳ���
 *		    	float*pZ:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX
 *		    	unsigned int n:���������,��Ҫ����:�������N>=24,���������������8�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxSubConst(float*pX, float fVal, float*pZ, unsigned int n);


/***************************************************************************************
 *	������:		CplxMulVec(float*pX, float*pY, float*pZ, unsigned int n)
 *	��������: 	ʵ�ָ���������������,��ʽ:Z[i] = X[i]*Y[i] + X[i+1]*Y[i];X[i]��ʾʵ��,X[i+1]��ʾ�鲿
 *	����˵��:	float*pX:����ĸ���������ʼ��ַ
 *		    	float*pY:��������ʼ��ַ
 *		    	float*pZ:��ż�����,ʵ����ǰ,�鲿�ں�,�õ�ַ���Ը���pX
 *		    	unsigned int n:���������,��Ҫ����:�������N>=12,���������������4�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxMulVec(float*pX, float*pY, float*pZ, unsigned int n);


/***************************************************************************************
 *	������:		CplxPower2(float *pX, float*pY, unsigned int n)
 *	��������: 	ʵ�ָ���ƽ��,��ʽ:Y[i] = X[i]*X[i] + X[i+1]*X[i+1];X[i]��ʾʵ��,X[i+1]��ʾ�鲿
 *	����˵��:	float*pX:����ĸ���������ʼ��ַ
 *		    	float*pY:�����������ʼ��ַ
 *		    	unsigned int n:���������,��Ҫ����:�������N>=24,���������������8�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_CplxPower2(float *pX, float*pY, unsigned int n);


/***************************************************************************************
 *	������:		UncharToFloattest(unsigned char*pX, float *pW, unsigned int nLen)
 *	��������: 	ʵ��unsigned char ת���� float��
 *	����˵��:	unsigned char*pX:�����unsigned char������ʼ��ַ
 *		    	float*pW:�����������ʼ��ַ
 *		    	unsigned int nLen:���������,��Ҫ����:�������nLen>=24,���������������8�ı���
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_UncharToFloat(unsigned char*pX, float *pW, unsigned int nLen);


/***************************************************************************************
 *	������:		VectorSum(float *pX, unsigned int nLen)
 *	��������: 	��һ��float�����������Ԫ���������,�������ͽ��
 *	����˵��:	float *pX:���������������ʼ��ַ
 *		    	unsigned int nLen:����float���ݵĳ���,��Ҫ����:���ݳ��ȱ������16,�ұ�����8��������
 *	����ֵ: 		float
 ***************************************************************************************/
extern float Vec_VectorSum(float *pX, unsigned int nLen);


/***************************************************************************************
 *	������:		CplxSum(float *pX, unsigned int nLen, float*pY)
 *	��������: 	����������������,�������ͽ��
 *	����˵��:	float *pX:����ĸ���������ʼ��ַ
 *		    	unsigned int nLen:���븴����ĸ���,��Ҫ����:���ݳ��ȱ������8,�ұ�����4��������
 *		    	float*pY:����Ľ����ŵ�ַ
 *	����ֵ: 		float
 ***************************************************************************************/
extern void Vec_CplxSum(float *pX, unsigned int nLen, float*pY);


/***************************************************************************************
 *	������:		Cos_Sin_LookUp_Table_CplxMul(float*InPut, float*OutPut, float*pCos_Sin_Table, int InPutLen, int nPortion)
 *	��������: 	�����������ͨ�����Ǻ�������������Ӧ��cos��sinֵ��Ȼ��͸�������и����˷�
 *	����˵��:	float *pX:����ĸ���������ʼ��ַ
 *				float*OutPut����������ʼ��ַ
 *				float*pCos_Sin_Table:���ɵ����Ǻ�����ĵ�ַ,exptable
 *		    	int InPutLen:���븴����ĸ���,��Ҫ����:���ݳ��ȱ������8,�ұ�����2��������
 *		    	int nPortion:��0-2PI����nPortion�ȷ�
 *	����ֵ: 		void
 ***************************************************************************************/
extern void Vec_Cos_Sin_LookUp_Table_CplxMul(float*InPut, float*OutPut, float*pCos_Sin_Table, int InPutLen, int nPortion);

/***************************************************************************************
 *	������:		FloatSqrtVec(float *pX, float *pY, unsigned int nLen)
 *	��������: 	������������������;
 *	����˵��:	float *pX:��ʾ�����������ʼ��ַ,Ҫ������ĸ������������������ݱ���Ϊ���ڵ���0.0�ĸ�����
 *				float *pY:��ʾ����Ľ����ŵ���ʼ��ַ,Ҫ�������ַ�ռ��С������ռ��Сһ��;
 *		    	unsigned int nLen:��ʾ����ĵ���;��Ҫ����:�������N>=16,�ұ�����8�ı���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_FloatSqrtVec(float *pX, float *pY, unsigned int nLen);

/***************************************************************************************
 *	������:		FloatAbsVec(float *pX, float *pY, unsigned int nLen)
 *	��������: 	���������ֵ����;
 *	����˵��:	float *pX:��ʾ�����������ʼ��ַ;
 *				float *pY:��ʾ����Ľ����ŵ���ʼ��ַ;
 *		    	unsigned int nLen:��ʾ����ĵ���;��Ҫ����:�������N>=16,���������������8�ı���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_FloatAbsVec(float *pX, float *pY, unsigned int nLen);

/***************************************************************************************
 *	������:		MemCopy(void * src,void * dst,unsigned int nLen);
 *	��������: 	�����ڴ濽������;
 *	����˵��:	void * src:��ʾԴ�������ʼ��ַ src;
 *				void * dst:��ʾĿ�ĵ�ַ����ʼ��ַ dst��
 *		    	unsigned int nLen:��ʾ��Ҫ�������ֽ���;��Ҫ����:�������nLen>=16*8,�������ֽ���������32�ı���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_MemCopy(void * src,void * dst,unsigned int nLen);
/***************************************************************************************
 *	������:void Memoryset(float*pInPut, float*pOutPut,int n)
 *	��������: ��Ӧ��C���Ե�memset ����дд��8���ֽڣ���2��FLOAT����
 *	����˵��:
 *	1.	float*pInPut:��Ҫ����������8���ֽڣ�2����
 *  2.	float*pOutPut���������
 *  3.  int n��������������8�ı���
 *	����ֵ: 	��
 ***************************************************************************************/
extern void Vec_Memoryset(float*pInPut, float*pOutPut,int n);
/***************************************************************************************
 *	������:		MemCopyStride(float * src,float * dst,unsigned int nLen, unsigned int stride);
 *	��������: 	�����ڴ濽������;
 *	����˵��:	void * src:��ʾԴ�������ʼ��ַ src;
 *				void * dst:��ʾĿ�ĵ�ַ����ʼ��ַ dst��
 *		    	unsigned int nLen:��ʾ��Ҫ��ʾ�����ĸ���(������32λ);��Ҫ����:�������N>=16,���������������8�ı���
 *				unsigned int stride:�������������
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_MemCopyStride(float * src,float * dst,unsigned int nLen, unsigned int stride);

/***************************************************************************************
 *	������:		Linspace(float First,float Last,unsigned int nLen,float *pOut);
 *	��������: 	ʵ��matlab��linspace()����;
 *	����˵��:	float First:��������ĵ�һ��ֵ
 *				float Last:������������һ��ֵ
 *		    	unsigned int nLen:��������ĸ���;��Ҫ����:nLen>=12������4�ı���
 *				float *pOut:�������������׵�ַ
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_Linspace(float First,float Last,unsigned int nLen,float *pOut);

/***************************************************************************************
 *	������:		void f32_bit8_Ext(void *buf1, void *buf2,unsigned int nl, float fstep, float fmin);
 *	��������: 	������������;
 *	����˵��:	void *buf1:�����������ʼ��ַ��Ҫ����øú���ǰ�����������������ֵ������֤�������ݲ���Ϊ������
 *				void *buf2:�����ַ����ʼ��ַ��
 *		    	unsigned int nl:��������ĸ���;��Ҫ����:Ҫ��Ϊ>=24������8�ı�����
 *				float fstep:�������������׵�ַ��fstep =255/(max*0.9-min);maxΪ����������������ֵ��
 *				float fmin���������ݵ���Сֵ
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_f32_bit8_Ext(void *buf1, void *buf2,unsigned int nl, float fstep, float fmin);
/***************************************************************************************
 *	������:	Vec_f32_bit16(float* pIn,short * pOut,float fMax,unsigned int Num);
 *	��������:  ʵ�ֶ�������������������������
 *  ����˵��:  pIn:����float����ָ��
 *          pOut:���int16����ָ��
 *          fMax:��������
 *          Num:���ݳ��ȣ�float�����ݳ��ȣ�����ʵ�����ǵ��������Ǹ������Ǹ���������2��
 *  ��ʽ:    int16��pIn/fMax*32767��
 *	����ֵ: 	��
 ***************************************************************************************/
extern void Vec_f32_bit16(float* pIn,short * pOut,float fMax,unsigned int Num);
/***************************************************************************************
 *	������:		float Mat_sp_maxval(float *x,int row,int col )
 *	��������: 	ʵ�־��������ֵ
 *	����˵��:	float*x:��������
 *		    	int row:���������
 *		    	int col�����������   row*col������4�ı����� >= 4
 *	����ֵ: 		�������ֵ
 ***************************************************************************************/

extern float Mat_sp_maxval(float *x,int row,int col );
/***************************************************************************************
 *	������:		float  Mat_sp_minval(float *x,int row,int col )
 *	��������: 	ʵ�־�������Сֵ
 *	����˵��:	float*x:��������
 *		    	int row:���������
 *		    	int col�����������   row*col������4�ı����� >= 4
 *	����ֵ: 		������Сֵ
 ***************************************************************************************/
extern float Mat_sp_minval(float *x,int row,int col );
/***************************************************************************************
 *	������:Vec_mat_max(float*pInPut, int nPointNum,float*Value);
 *	��������: ���������е����ֵ�Լ���λ��
 *	����˵��:
 *	1.	float*pInPut:��������
 *  2.	int nPointNum��������������4�ı���
 *  3.  float*Value�����ֵ��ŵ�ַ
 *	����ֵ: 	���ֵλ��
 ***************************************************************************************/
extern int Vec_mat_max(float*pInPut, int nPointNum,float*Value);
/***************************************************************************************
 *	������:		float Vec_ave(float *p,float n)
 *	��������: 	ʵ��������ֵ
 *	����˵��:	float*x:��������
 *		    	float n������n������4�ı����� >= 4
 *	����ֵ: 		������ֵ
 ***************************************************************************************/
extern float Vec_ave(float *p,float n);
/***************************************************************************************
 *	������:		float standard_sa_c(float*pX, float n)
 *	��������: 	ʵ���������׼��
 *	����˵��:	float*pX:��������
 *		    	float n�����������ĵ���
 *	����ֵ: 		������ֵ
 ***************************************************************************************/
extern float standard_sa_c(float*pX, float n);
/***************************************************************************************
 *	������:		void Mat_Mul(float*X1,float*X2,int r,int c,float *Y)
 *	��������: 	ʵ��ʵ��������
 *	����˵��:	float*X1:�����һ����˾���
 *		    	float*X2������ڶ�����˾���
 *		    	int r����˾����������r������2�ı����в��Ҵ��ڵ���2
 *		    	int c����˾����������c������2�ı����в��Ҵ��ڵ���2
 *		    	float *Y������������ľ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Mat_Mul(float*X1,float*X2,int r,int c,float *Y);
/***************************************************************************************
 *	������:		void Mat_Mul_Cplx(float*X1,float*X2,int r,int c,float *Y))
 *	��������: 	ʵ�ָ�����������
 *	����˵��:	float*X1:�����һ����˸�������
 *		    	float*X2������ڶ�����˸�������
 *		    	int r����˾�����е�����r������2�ı����в��Ҵ��ڵ���2
 *		    	int c����˾�����е�����c������2�ı����в��Ҵ��ڵ���2
 *		    	float *Y������������ľ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Mat_Mul_Cplx(float*X1,float*X2,int r,int c,float *Y);
/***************************************************************************************
 *	������:Vec_cplxmulmat(float*X1,int r,int c,float*X2,float *Y);
 *	��������: ���������һ����������
 *	����˵��:
 *	1.	float*X1:����������ַ
 *  2.	int r�����븴����������
 *  3.  int c�����븴����������
 *  4.  float*X2�����븴������
 *  5.  float*  y���������
 *	����ֵ: 	��
 ***************************************************************************************/
extern void Vec_cplxmulconstmat(float*X1,int r,int c,float*X2,float *Y);
/***************************************************************************************
 *	������:		void Mat_add_cplx(float* x1,float* x2,float *Y,int r1, int c1)
 *	��������: 	ʵ�ָ����������
 *	����˵��:	float*x1:�����һ����������
 *		    	float*x2������ڶ�����������
 *		    	float *Y������������ľ���
 *		    	int r1��������е�����r1������2�ı����в��Ҵ��ڵ���2
 *		    	int c1��������е�����c1������2�ı����в��Ҵ��ڵ���2
 *
 *	����ֵ: 		��
 ***************************************************************************************/

extern void Mat_add_cplx(float* x1,float* x2,float *Y,int r1, int c1);

/***************************************************************************************
 *	������:		void Mat_add(float* x1,float* x2,float *Y,int r1, int c1)
 *	��������: 	ʵ�ָ����������
 *	����˵��:	float*x1:�����һ����˸�������
 *		    	float*x2������ڶ�����˸�������
 *		    	float *Y������������ľ���
 *		    	int r1��������е�����r1������2�ı����в��Ҵ��ڵ���2
 *		    	int c1��������е�����c1������2�ı����в��Ҵ��ڵ���2
 *
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Mat_add(float* x1,float* x2,float *Y,int r1, int c1);//

/***************************************************************************************
 *	������:		double Vec_mu_dp(double* x,int nx)
 *	��������: 	ʵ��������ģ˫������ģ
 *	����˵��:	float*x:��������
 *		    	int nx�����������ĵ�����nx����Ϊ2�ı���
 *	����ֵ: 		ģֵ
 ***************************************************************************************/
extern double Vec_mu_dp(double* x,int nx);
/***************************************************************************************
 *	������:		float Vec_mu_sp(float* x,int nx)
 *	��������: 	ʵ��������ģ��������ģ
 *	����˵��:	float*x:��������
 *		    	int nx�����������ĵ�����nx����Ϊ2�ı���
 *	����ֵ: 		ģֵ
 ***************************************************************************************/
extern float Vec_mu_sp(float* x,int nx);
/***************************************************************************************
 *	������:		int Mat_sp_inv(float *a, int n)
 *	��������: 	ʵ��ʵ����������
 *	����˵��:	float*a:�������		����Ľ����������a
 *		    	int n����������ά��
 *	����ֵ: 		���1�������ܹ����� 		���0������������
 ***************************************************************************************/
extern int Mat_sp_inv(float *a, int n);  
/***************************************************************************************
 *	������:		int Mat_inv_cplx(float *pInPut,int n,int *is,int *js,float *frow,float *fcol);
 *	��������: 	ʵ�ָ�����������
 *	����˵��:
 *	1.	float *pInPut:���븴������		����Ľ����������pInPut
 *  2.	int n�����븴�������ά��
 *  3.	int *is,int *js���м������ſռ䣬�ռ�����ڸ����������
 *  4.	float *frow,float *fcol�м������ſռ䣬�ռ�����ڸ����������
 *	����ֵ: 		���1�������ܹ����� 		���0������������
 ***************************************************************************************/
extern int Mat_invc_cplx( float *pInPut,int n,int *is,int *js,float *frow,float *fcol);

/***************************************************************************************
 *	������:		void Vec_Split(float*X1,float*pY1,float*pY2,int n)
 *	��������: 	ʵ��ʵ������ �� ż���
 *	����˵��:	float*X1:����ʵ������
 *				float*pY1�������������
 *				float*pY2��ż���������
 *		    	int n��������������������ڵ���8��Ϊ8�ı���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_Split(float*X1,float*pY1,float*pY2,int n);
/***************************************************************************************
 *	������:		void Vec_Split_Cplx(float*X1,float*pY1,float*pY2,int n)
 *	��������: 	ʵ�ָ������� �� ż���
 *	����˵��:	float*X1:����ʵ������
 *				float*pY1�������������
 *				float*pY2��ż���������
 *		    	int n������������������������ڵ���4��Ϊ4�ı���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_Split_Cplx(float*X1,float*pY1,float*pY2,int n);
/***************************************************************************************
 *	������:		void Vec_Comb(float*X1,float*X2,float*pY,int n)
 *	��������: 	ʵ��ʵ������ �� ż�ϲ�
 *	����˵��:	float*X1:����ż������
 *				float*X2��������������
 *				float*pY���������
 *		    	int n������������������������ڵ���2��Ϊ2�ı���	 ���������ż���������������ͬ
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_Comb(float*X1,float*X2,float*pY,int n);
/***************************************************************************************
 *	������:		void Vec_Comb(float*X1,float*X2,float*pY,int n)
 *	��������: 	ʵ�ָ������� �� ż�ϲ�
 *	����˵��:	float*X1:����ż������
 *				float*X2��������������
 *				float*pY���������
 *		    	int n������������������������ڵ���2��Ϊ2�ı���	 ���������ż���������������ͬ
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_Comb_Cplx(float*X1,float*X2,float*pY,int n);

/***************************************************************************************
 *	������:		void Vec_cos_lookup_table(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��COS
 *	����˵��:	float* X:��������
 *				float *Y������������
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ,ʹ��16384���exptable��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_cos_lookup_table(float* X,float *Y,int n,const float *table,float  table_num);
/***************************************************************************************
 *	������:		void Vec_sin_lookup_table(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��sin
 *	����˵��:	float* X:��������
 *				float *Y������������
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ ,ʹ��16384���exptable��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_sin_lookup_table(float* X,float *Y,int n,const float *table,float  table_num);

/***************************************************************************************
 *	������:		void Vec_sin_cos(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��sin��cos
 *	����˵��:	float* X:��������   Ϊ����ֵX/2PI
 *				float *Y������������ ��ŵ�һ����cosֵ���ڶ�����sinֵ
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ��ʹ��16384���exptable��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_sin_cos(float* X,float *Y,int n,const float *table,float  table_num);
/***************************************************************************************
 *	������:		void Hamming(float* Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ֺ�����
 *	����˵��:	float *Y������������
 *				int n���������ĳ���  ż������
 *				const float *table������COS����ַ ��ʹ��16384���exptable��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Hamming(float* Y,int n,const float *table,float  table_num);
/***************************************************************************************
 *	������:		void Vec_cos(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��COS,�Ż��汾�������Բ�
 *	����˵��:	float* X:��������
 *				float *Y������������
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ,ʹ��8192���cos_sin_table��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_cos(float* X,float *Y,int n,const float *table,float  table_num);
/***************************************************************************************
 *	������:		void Vec_sin(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��sin��,�Ż��汾�������Բ�
 *	����˵��:	float* X:��������
 *				float *Y������������
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ    ʹ��8192���cos_sin_table��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_sin(float* X,float *Y,int n,const float *table,float  table_num);
/***************************************************************************************
 *	������:		void Vec_sin_cos1(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��sin��cos��,�Ż��汾�������Բ�
 *	����˵��:	float* X:��������   Ϊ����ֵX/2PI
 *				float *Y������������ ��ŵ�һ����cosֵ���ڶ�����sinֵ
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ   ,ʹ��8192���cos_sin_table��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_sin_cos1(float* X,float *Y,int n,const float *table,float  table_num);

/***************************************************************************************
 *	������:		void Hamming1(float* Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ֺ�����,�Ż��汾�������Բ�
 *	����˵��:	float *Y������������
 *				int n���������ĳ���  ż������
 *				const float *table������COS����ַ ,ʹ��8192���cos_sin_table��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Hamming1(float* Y,int n,const float *table,float  table_num);
/***************************************************************************************
 *	������:		void Mat_extract(float* X,int r_s,int c_s,int row_num,int r1,int c1,float* Y)
 *	��������: 	��ά������ȡ
 *	����˵��:	float *X��ԭʼ����
 *				int r_s����ȡԭʼ�������ʼ�е���
 *				int c_s����ȡԭʼ�������ʼ�е���
 *				int row_num����ȡԭʼ�����е���
 *				int r1����ȡ���е��� 
 *				int c1����ȡ���е���
 *				float* Y���������
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Mat_extract(float* X,int r_s,int c_s,int row_num,int r1,int c1,float* Y);
/***************************************************************************************
 *	������:		 Cfar(float* input,int *output,int  N,int G, int L, float coeff, float thr );
 *	��������: 	���龯�ʽ��ջ�
 *	����˵��:	float* input����������
 *				int *output�������⵽Ŀ���λ�õ�����
 *				 N���������г���
 *				 G��������Ԫ����
 *				 L���ο���Ԫ����
 *				coeff����Ȩϵ��
 *			    thr�����޴�С
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Cfar(float* input,int *output,int  N,
		int G, int L, float coeff, float thr );

/***************************************************************************************
 *	������:		 void Vec_ShortToFloat(short *pX,float *pY,int n);
 *	��������: 	16λ�з�������ת��Ϊ������
 *	����˵��:	short *pX����������
 *				float *pY�������������
 *				int n����������   ��������Ϊ2�ı���
 *				
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_ShortToFloat(short *pX,float *pY,int n);
/***************************************************************************************
 *	������:		 Vec_UnShortToFloat(short *pX,float *pY,int n);
 *	��������: 	16λ�޷�������ת��Ϊ������
 *	����˵��:	unsigned short *pX����������
 *				float *pY�������������
 *				int n����������   ��������Ϊ2�ı���
 *				
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_UnShortToFloat(unsigned short *pX,float *pY,int n);
/***************************************************************************************
 *	������:		Vec_cplxfftshift(float*pInPut,int r,float*pOutPut);
 *	��������: 	ʵ��matlab��fftshift()����;
 *	����˵��:	float*pInPut�����븴������
 * 	            int  r�����������Ϊ4�ı���
 *	            float*pOutPu�������������
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_cplxfftshift(float*pInPut,int r,float*pOutPut);

/***************************************************************************************
 *	������:		 ReferenceGenerate( float fFdc,
									float fFdr,
									float fPluseband,
									float fFs,
									float *pfWindow,
									int   iMulWindflag,
									int   iPoint,
									float *pfTable,
									float   fTabNum,
									float *tempBuf,
									float *pfOut
									);
 *	��������: 	���ɲο���������������chirp������
 *	����˵��:	fFdc�� �ο������Ķ���������Ƶ��		
				fFdr����Ƶб��
				fPluseband������     
				fFs�� ����Ƶ��
				pfWindow��Ҫ�ӵĴ������׵�ַ
				iMulWindflag���Ƿ�˴����������Ϊ0��ʾ���˴�������Ϊ1��ʾ�˴�����
				iPoint����������
				pfTable ��cos�������ַ
				fTabNum�����Ĵ�С
				tempBuf�� ���������СΪiPoint
				pfOut��   �ο�����������


 *	����ֵ: 		��
 ***************************************************************************************/
extern void ReferenceGenerate( float fFdc,
						float fFdr,
						float fPluseband,
						float fFs,
						float *pfWindow,
						int   iMulWindflag,
						int   iPoint,
						float *pfTable,
						float   fTabNum,
						float *tempBuf,
						float *pfOut
				  		);
/***************************************************************************************
 *	������:		void PulseCompress(
					float  *cf_PRTData,          
					float  *cf_PCReference,		 
					float  *cf_PCResult,		
					float  *tempBuf,             
					float  *cf_Twiddle,			
					float  *cf_iTwiddle,		
					int    i_PCPoint			 //��ѹ�Ĵ������
				  );
 *	��������: 	����ѹ������
 *	����˵��:	
1.	cf_PRTData���������ݵ��׵�ַ	
2.	cf_PCReference���ο������׵�ַ	
3.	cf_PCResult�������ѹ���
4.	tempBuf�� ��ʱ�洢�ռ�    ��СΪ��ѹ�Ĵ��������2��
5.	cf_Twiddle��fft��ת�����׵�ַ ���ֵ��СΪ��ѹ�Ĵ��������2��
6.	cf_iTwiddle��ifft��ת�����׵�ַ ���ֵ��СΪ��ѹ�Ĵ��������2��
7.	i_PCPoint����ѹ�Ĵ������

 *	����ֵ: 		��
 ***************************************************************************************/						
extern void PulseCompress(
					float  *cf_PRTData,         
					float  *cf_PCReference,		
					float  *cf_PCResult,		
					float  *tempBuf,           
					float  *cf_Twiddle,			 
					float  *cf_iTwiddle,		
					int    i_PCPoint			 
				  );

//////////////////////////////////////////////////
//typedef struct {
//	Uint32   CC[8];
//	Uint32   Chan_in[8];
//	Uint32   Para_in[8];
//	Uint32	 TCNum[8];
//	Uint32	 RegionNum[8];
//}   EDMA_Channel;			//EDMA������ʼ������ſ�������ͨ���š�������

typedef struct _EDMA_Channel
{
	Uint32   CC;//EDMA������
	Uint32   Chan_in;//EDMAͨ����
	Uint32   Para_in;//�������PARAM��
	Uint32	 TCNum;//������
	Uint32	 RegionNum;//�����
}EDMA_Channel;

typedef enum {
	vlfft_2k = 11,
	vlfft_4k = 12,
	vlfft_8k = 13,
	vlfft_16k = 14,
	vlfft_32k = 15,
	vlfft_64k = 16,
	vlfft_128k = 17,
	vlfft_256k = 18
//	vlfft_512k = 19,
//	vlfft_1024k = 20
}FFT_POINTNUM;   //��������ֵ�����ǵ���ȡ��2�Ķ�������Խ������Ĳ��������кô�
/***************************************************************************************
 *	������:	void vlfft_tw_gen(float *w, int n);
 *	��������: ����FFT�ĵ�������
 *	����˵��:	float*pInPut���������Ӵ�ŵ�ַ
 * 	        int  n������
 *	����ֵ: 		��
 ***************************************************************************************/
extern void vlfft_tw_gen(float *w, int n);
/***************************************************************************************
 *	������:	void vlfft_itw_gen(float *w, int n);
 *	��������: ����IFFT�ĵ�������
 *	����˵��:	float*pInPut���������Ӵ�ŵ�ַ
 * 	        int  n������
 *	����ֵ: 		��
 ***************************************************************************************/
extern void vlfft_itw_gen(float *w, int n);
/***************************************************************************************
 *	������:	void vlfft_genTwiddle(float *vlfft_widdle,int numFFTsPerCore,int coreNum,FFT_POINTNUM pointnum));
 *	��������:  ������άFFT�Ľ�������
 *	����˵��:	float*vlfft_widdle���������Ӵ�ŵ�ַ
 * 	        int  numFFTsPerCore��ÿ���˼���FFT�ĵ���=N2/�������ĺ���;
 * 	        int coreNum ���˺�
 * 	        FFT_POINTNUM pointnum������FFT����N��2��ָ����Ŀǰ֧��vlfft_2k~vlfft_256k��
 *
 *	����ֵ: 		��
 ***************************************************************************************/
extern void vlfft_genTwiddle(float *vlfft_widdle,int numFFTsPerCore,int coreNum,FFT_POINTNUM pointnum);
/***************************************************************************************
 *	������:	void vlfft_genITwiddle(float *vlfft_widdle,int numFFTsPerCore,int coreNum,FFT_POINTNUM pointnum));
 *	��������:  ������άIFFT�Ľ�������
 *	����˵��:	float*vlfft_widdle���������Ӵ�ŵ�ַ
 * 	        int  numFFTsPerCore��ÿ���˼���FFT�ĵ���=N2/�������ĺ���;
 * 	        int coreNum ���˺�
 * 	        FFT_POINTNUM pointnum������FFT����N��2��ָ����Ŀǰ֧��vlfft_2k~vlfft_256k��
 *
 *	����ֵ: 		��
 ***************************************************************************************/
extern void vlfft_genITwiddle(float	*vlfft_widdle,int numFFTsPerCore,int coreNum,FFT_POINTNUM pointnum);

/***************************************************************************************
 *	������:		void vlfft_compute_notHomePos(float  *pInData,
						float 			*pOutData,
						FFT_POINTNUM 	pointnum,
						EDMA_Channel 	edma_channel,
						float 			*vlfft_wcolfft,
						float 			*vlfft_wrowfft,
						float 			*vlfft_twiddle,
						float			*computeBuf_1,
						float			*computeBuf_2,
						float			*fftBuf,
						int 			coreNum,
						int             mastercore,
						int 			mode,
						int             LOG2_NUM_OF_CORES_FOR_COMPUTE);
 *	��������: 	��Ƭ8��ʵ�ֳ�������FFT�Լ�IFFT��Ŀǰ���128k�㣩����ԭλ����
 *	����˵��:
1.  pInData: ԭʼ���������Լ������������ַ��Ҫ�����ݿռ���������              �ڶ��롣��λ�ڹ����ڴ�MSMC����СΪ�������ʵ��ռ�� �ռ��С��
2.  pOutData: ���˼�����ʱ���档��λ�ڹ����ڴ�MSMC����СΪ�������ʵ��ռ�� �ռ��С��
3.  pointnum���������N��2��ָ����Ŀǰ֧��vlfft_2k~vlfft_256k��
4.  edma��EDMA��ʼ����ͨ������ʼ����ʽ��ʾ������
5.  vlfft_wcolfft����FFT����IFFT�ĵ������ӣ�ռ�ÿռ��СΪ8*N1�ֽڣ�λ�ڸ��˶����ڴ�L2
6.  vlfft_wrowfft����FFT����IFFT�ĵ������ӣ�ռ�ÿռ��СΪ8*N2�ֽڣ�λ�ڸ��˶����ڴ�L2
7.  vlfft_twiddle����ת���ӣ�ռ�ÿռ��СΪ8*N2�ֽڣ�λ�ڸ��˶����ڴ�L2
8.  computeBuf_1�����˼�����ʱ���棬��СΪ128* N1���ֽڣ�λ�ڸ��˶����ڴ�L2
9.  computeBuf_2�����˼�����ʱ���棬��СΪ128* N1���ֽڣ�λ�ڸ��˶����ڴ�L2��
10. fftBuf����С����Ϊ0
11. coreNum����Ժ˺ţ����3�ͺ�4���˴���ʱ�������˷ֱ�����0��1
12. mastercore��������������С�˺ŵľ��Ժ˺ţ����3�ͺ�4���˴���ʱ�������˶�����3
13. mode��ģʽ��0��aft��1��ifft
14. LOG2_NUM_OF_CORES_FOR_COMPUTE����������ܺ���2��ָ��
 *	����ֵ: 		��
 ***************************************************************************************/
extern void vlfft_compute_notHomePos(float  *pInData,
				float 			*pOutData,
				FFT_POINTNUM 	pointnum,
				EDMA_Channel 	edma_channel,
				float 			*vlfft_wcolfft,
				float 			*vlfft_wrowfft,
				float 			*vlfft_twiddle,
				float			*computeBuf_1,
				float			*computeBuf_2,
				float			*fftBuf,
				int 			coreNum,
				int             mastercore,
				int 			mode,
				int             LOG2_NUM_OF_CORES_FOR_COMPUTE
);


/***************************************************************************************
 *	������:	void vlfft_compute_HomePos(float *InOutData,
					FFT_POINTNUM 	pointnum,
					EDMA_Channel 	edma_channel,
					float 			*vlfft_wcolfft,
					float 			*vlfft_wrowfft,
					float 			*vlfft_twiddle,
					float			*computeBuf_1,
					float			*computeBuf_2,
					float			*fftBuf,
					int 			coreNum,
					int             mastercore,
					int 			mode,
					int             LOG2_NUM_OF_CORES_FOR_COMPUTE
);
									float *outBuf);
 *	��������: 	��Ƭ8��ʵ�ֳ�������FFT�Լ�IFFT��Ŀǰ���256k�㣩��ԭλ����
 *	����˵��:
1.  pinoutData : ԭʼ���������Լ������������ַ��Ҫ�����ݿռ���������              �ڶ��롣��λ�ڹ����ڴ�MSMC����СΪ�������ʵ��ռ�� �ռ��С��
2.  pointnum���������N��2��ָ����Ŀǰ֧��vlfft_2k~vlfft_256k��
3.  edma��EDMA��ʼ����ͨ������ʼ����ʽ��ʾ������
4.  vlfft_wcolfft����FFT����IFFT�ĵ������ӣ�ռ�ÿռ��СΪ8*N1�ֽڣ�λ�ڸ��˶����ڴ�L2
5.  vlfft_wrowfft����FFT����IFFT�ĵ������ӣ�ռ�ÿռ��СΪ8*N2�ֽڣ�λ�ڸ��˶����ڴ�L2
6.  vlfft_twiddle����ת���ӣ�ռ�ÿռ��СΪ8*N2�ֽڣ�λ�ڸ��˶����ڴ�L2
7.  computeBuf_1�����˼�����ʱ���棬��СΪmax��4*N/Corenum��128* N1�����ֽڣ�λ�ڸ��˶����ڴ�L2
8.  computeBuf_2�����˼�����ʱ���棬��СΪmax��4*N/Corenum��128* N1�����ֽڣ�����NΪ�ܸ���������CorenumΪ�������ĺ�����λ�ڸ��˶����ڴ�L2��������computeBuf_1�������
9.  fftBuf�����˼�����ʱ���棬��СΪ16*N2*8���ֽڣ�λ�ڸ��˶����ڴ�L2
10. coreNum����Ժ˺ţ����3�ͺ�4���˴���ʱ�������˷ֱ�����0��1
11. mastercore��������������С�˺ŵľ��Ժ˺ţ����3�ͺ�4���˴���ʱ�������˶�����3
12. mode��ģʽ��0��fft��1��ifft
13. LOG2_NUM_OF_CORES_FOR_COMPUTE����������ܺ���2��ָ��

 *	����ֵ: 		��
 ***************************************************************************************/
extern void vlfft_compute_HomePos(float *InOutData,
	    FFT_POINTNUM 	pointnum,
		EDMA_Channel 	edma_channel,
		float 			*vlfft_wcolfft,
		float 			*vlfft_wrowfft,
		float 			*vlfft_twiddle,
		float			*computeBuf_1,
		float			*computeBuf_2,
		float			*fftBuf,
		int 			coreNum,
		int             mastercore,
		int 			mode,
		int             LOG2_NUM_OF_CORES_FOR_COMPUTE
);
/***************************************************************************************
 *	������:		void Vec_sin_cos_polatio(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��sin��cos
 *	����˵��:	float* X:��������   Ϊ����ֵX/2PI
 *				float *Y������������ ��ŵ�һ����cosֵ���ڶ�����sinֵ
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ  ,��ʹ��16384���exptable��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_sin_cos_polatio(float* X,float *Y,int n,const float *table,float  table_num);
/***************************************************************************************
 *	������:		void Vec_sin_cos_polatio1(float* X,float *Y,int n,const float *table,float  table_num)
 *	��������: 	ʵ�ָ������� ��sin��cos,�Ż��汾�������Բ�
 *	����˵��:	float* X:��������   Ϊ����ֵX/2PI
 *				float *Y������������ ��ŵ�һ����cosֵ���ڶ�����sinֵ
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ ,��ʹ��8192���cos_sin_table��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_sin_cos_polatio1(float* X,float *Y,int n,const float *table,float  table_num);

/***************************************************************************************
 *	������:		void Vec_LinearAdd_Mul(float pa,float pb,int pn,float *pcOut)
 *	��������: 	���Լӳ������ٳ˳���
 *	����˵��:	float pa:����ӳ���
 *				float pb������˳���
 *				int pn����������ĸ�����n����2��Ϊ2�ı���
 *				 float *pcOut�����������飬��ʼ��ַ����2�� ������
 *
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_LinearAdd_Mul(float pa,float pb,int pn,float *pcOut);

/***************************************************************************************
 *	������:		void Vec_cplxmulmat(float* pInPut1,float* pInPut2,Uint32 rol,Uint32 col, float* pOutPut);
 *	��������: 	�����������Ը�������
 *	����˵��:	float pInPut1:���븴������
 *				float pInPut2�����븴������
 *
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_cplxmulmat(float* pInPut1,float* pInPut2,Uint32 rol,Uint32 col, float* pOutPut);

/***************************************************************************************
 *	������:		void Vec_LinearAdd_Pow_Mul(float pa,float pb,int pn,float *pcOut)
 *	��������: 	���Լӳ����ĺ�ƽ���ٳ˳���
 *	����˵��:	float pa:����ӳ���
 *				float pb������˳���
 *				int pn����������ĸ�����n����2��Ϊ2�ı���
 *				 float *pcOut�����������飬��ʼ��ַ����2�� ������
 *
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_LinearAdd_Pow_Mul(float pa,float pb,int pn,float *pcOut);

/***************************************************************************************
 *	������:		void Vec_CplxConjMulCplx_1(float*pX, float*pY, float*pZ, unsigned int n)
 *	��������: 	�����������г˸�������
 *	����˵��:	float pX:��ʾ����ĸ����������ʼ��ַ,��һ������ʵ��,�ڶ�����ʾ�鲿
 *				float pY����ʾ��һ����ĸ����������ʼ��ַ,��һ������ʵ��,�ڶ�����ʾ�鲿
 *				float pZ: ��ʾ����Ľ����ŵ���ʼ��ַ,�õ�ַ�������һ���������ߵڶ���������ͬ,�������������Դ
 *				int pn�����븴�����еĵ������������N>=12,���������������4�ı���
 *
 *				 ��ע��1 ���Խ������������ǵڶ����������У�Ч�����������ǵ�һ���������л��������������ϸ�
 *                    2 ��Ҫ������ʵ�ֶԵ�һ�����������������ڶ����������е��
 *
 *	����ֵ: 		��
 ***************************************************************************************/
//extern void Vec_CplxConjMulCplx(float*pX, float*pY, float*pZ, unsigned int n);

extern void Vec_CplxConjMulCplx_1_sa(float*pX, float*pY, float*pZ, unsigned int n);

/***************************************************************************************
 *	������:		void Vec_CplxAddConst2(float*pa, float*pb, float pfc, float pfd, unsigned int n)
 *	��������: 	�������мӷ���ʵ�����鲿�ֱ�Ӳ�ͬ�����ݣ�����ʵ���鲽�ֱ�Ӳ�ͬ������ (CPLX * a, CPLX * b,float c, float d,int n)
 *	����˵��:	float pa:��ʾ����ĸ����������ʼ��ַ,��һ������ʵ��,�ڶ�����ʾ�鲿
 *				float pa����ʾ�������ĸ����������ʼ��ַ,��һ������ʵ��,�ڶ�����ʾ�鲿
 *				float pfc: ��ʾʵ���ӵĳ���
 *				float pfd: ��ʾ�鲿�ӵĳ���
 *				int pn�����븴�����еĵ������������N>=12,���������������4�ı���
 *
 *				 ��ע��
 *
 *	����ֵ: 		��
 ***************************************************************************************/
extern void Vec_CplxAddConst2(float*pa, float*pb, float pfc, float pfd, unsigned int n);

/***************************************************************************************
 *	������:		void Vec_MulConst_sin_cos(float* X,float *Y,float pfc,int n,const float *table,float  table_num)
 *	��������: 	����Ƕȳ�ʵ������ ��sin��cos
 *	����˵��:	float* X:��������   Ϊ�Ƕ�ֵ
 *				float *Y������������ ��ŵ�һ����cosֵ���ڶ�����sinֵ *
 *				float pfc: ���뱻�˳�����fc = c/2PI
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ                        ��cos��Ϊһ��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 *	��ע�� 1 ������ʵ�֣����������Ƕȳ˸���������sincos (float * a, CPLX * b, float c,nt n)
 *	for(i=0;i<n;i++)
 *	{
 *		b[i].re=cos(2*PI*a[i]*c);
 *		b[i].im=sin(2*PI*a[i]*c);
 *	}
 *	    2  �������������Ƕ�����a,��ô������ýӿڵı��˵ĳ���ֵ pfc= ʵ�ʱ��˳���c;������������㻡��ֵ����a,��ôҪ��������ýӿڵı��˵ĳ���ֵ pfc= ʵ�ʱ��˳���c/(2*PI)
 ***************************************************************************************/
extern void Vec_MulConst_sin_cos(float* X,float *Y,float pfc,int n,const float *table,float  table_num);

/***************************************************************************************
 *	������:		void Vec_sin_cos_MulConst(float* X,float *Y,float pfc,int n,const float *table,float  table_num)
 *	��������: 	������Ƕȳ�ʵ������ ��sin��cos������ָ���ĸ��㳣�����
 *	����˵��:	float* X:��������   Ϊ�Ƕ�ֵ,�����ǻ���ֵ/2PI
 *				float *Y������������ ��ŵ�һ����cosֵ���ڶ�����sinֵ *
 *				float pfc: ���뱻�˳�����fc = c
 *				int n����������ĵ�����n����2��Ϊ2�ı���
 *				const float *table������ַ                        ��cos��Ϊһ��
 *		    	float  table_num���������ĸ���
 *	����ֵ: 		��
 *	��ע�� 1 �����������Ƕ���sincos�� �˸�����(float * a, CPLX * b, float c,nt n)
 *	for(i=0;i<n;i++)
 *	{
 *		b[i].re=c*cos(2*PI*a[i]);
 *		b[i].im=c*sin(2*PI*a[i]);
 *	}
 *	    2  �����������Ƕ�����a,Ҫ��������ýӿڵı��˵ĳ���ֵ pfc= ʵ�ʱ��˳���c
 ***************************************************************************************/
extern void Vec_sin_cos_MulConst(float* X,float *Y,float pfc,int n,const float *table,float  table_num);

/***********************************************************
 * �������
 * pUnCacheAddr��ӳ��Ĳ���cache�ռ�
 * iSL2BaseAddr    : ����L2�ڴ����ʼ��ַ����CMD�е����ֳ�һ������
 * CpuIndex:cpuһ������ӳ��16�ԡ�0,1,2�ѱ�Ĭ��ӳ�䣬����ֻ��3��15�����û��޸ġ�
			 3~15

 * ���أ�
 * * ��
 */
extern void synFlagmap(Uint32 pUnCacheAddr,Uint32 iSL2BaseAddr,Uint32 CpuIndex);
/*******************************************
 * �����ӿڣ�
 * �������ܣ����ò���cache����ռ����8��ͬ��������ͬ��������2��32�η���
 * �����������
 * ͬ�����ڣ�300 ��Cycle
 *
 *****************************************/
extern void C6678_core8_FlagSyn();//
#endif /* MY_H_ */
