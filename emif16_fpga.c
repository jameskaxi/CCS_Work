/*
 * emif16_fpga.c
 *
 *  Created on: 2012-4-6
 *      Author: wangjie
 */

#include "./c6678_driver/c6678.h"
/********************************************************************
 * �ڲ�����ȫ�ֱ���
 *******************************************************************/
 /**
  *  Handle to access BOOTCFG registers.
  */
#define hEmif16Cfg     ((CSL_Emif16Regs*)CSL_EMIF16_REGS)
#define EMIF16_FPGA_DATA_ADDR  0x70000000  /*emif16_cs4_base */

/********************************************************************
 * �ڲ�����ṹ��
 *******************************************************************/

/********************************************************************
 * �ڲ����躯��
 *******************************************************************/
Bool Emif16FpgaOpenDevice(void);
Bool Emif16FpgaConfig (void);
/********************************************************************
	��������

	�����ļ�:   emif16_fpga.c
	����:		wj

	������:
	  Bool C6678_Emif16_Fpga_Init(void)
	����˵��:
	  �������ǳ�ʼ��emif16_fpga
	����˵��:
	  ��
	����ֵ:
	   TRUE:�ɹ�
	   FALSE��ʧ��
	��ע: ��
*********************************************************************/
Bool C6678_Emif16_Fpga_Init(void)
{
	/* Open the NAND Device */
	Bool isok;

    while ((CSL_semAcquireDirect (EMIF16_SW_SEM)) == 0)
	{
	}

	isok = Emif16FpgaOpenDevice();

    CSL_semReleaseSemaphore (EMIF16_SW_SEM);
	return isok;
}
/********************************************************************
	��������

	�����ļ�:   emif16_fpga.c
	����:		wj

	������:
	 	 Bool C6678_Emif16_Fpga_ReadByte(uint32_t byte_addr,uint32_t uiNumBytes,uint16_t *DataBuffer)
	����˵��:
	  ��������ͨ��emif16��fpga�е�����
	����˵��:
	  DataBuffer���������ݴ洢�������ָ��
 	  uiNumBytes���������ݵĳ��ȣ�16bitΪ��λ��(���2048)
	  byte_addr��������fpga�Ļ���ַ��16bitΪ��λ��
	����ֵ:
	   TRUE:�ɹ�
	   FALSE��ʧ��
	��ע: ��
*********************************************************************/
Bool C6678_Emif16_Fpga_ReadByte(uint32_t byte_addr,uint32_t uiNumBytes,uint16_t *DataBuffer)
{
	uint32_t i;
	uint16_t* dest;

    while ((CSL_semAcquireDirect (EMIF16_SW_SEM)) == 0)
	{
	}

	dest = (uint16_t *)(EMIF16_FPGA_DATA_ADDR+byte_addr);
	for(i=0;i<uiNumBytes;i++)
	{
		DataBuffer[i]= dest[i];
	}

    CSL_semReleaseSemaphore (EMIF16_SW_SEM);

	return TRUE;
}
/********************************************************************
	��������

	�����ļ�:   emif16_fpga.c
	����:		wj

	������:
	 	 Bool C6678_Emif16_Fpga_WriteByte(uint32_t byte_addr,uint32_t uiNumBytes,uint16_t *DataBuffer)
	����˵��:
	  ��������ͨ��emif16дfpga��ĳ�οռ�
	����˵��:
	  DataBuffer��д�����ݴ洢�������ָ��
 	  uiNumBytes��д�����ݵĳ��ȣ�16bitΪ��λ��(���2048)
	  byte_addr��������fpga�Ļ���ַ��16bitΪ��λ��
	����ֵ:
	   TRUE:�ɹ�
	   FALSE��ʧ��
	��ע: ��
*********************************************************************/
Bool C6678_Emif16_Fpga_WriteByte(uint32_t byte_addr,uint32_t uiNumBytes,uint16_t *DataBuffer)
{
	uint32_t i;
    uint16_t* dest;

    while ((CSL_semAcquireDirect (EMIF16_SW_SEM)) == 0)
	{
	}

	dest = (uint16_t *)(EMIF16_FPGA_DATA_ADDR+byte_addr);
	for(i=0;i<uiNumBytes;i++)
	{
		 dest[i] = DataBuffer[i];
	}

    CSL_semReleaseSemaphore (EMIF16_SW_SEM);

	return TRUE;
}
/******************************************************************************
*
* Function:    Emif16FpgaOpenDevice
*
* Description: This function is used to open the NAND device and configure it
*
* Parameters:  None
*
* Return Value: Error/Success codes
*
*****************************************************************************/
Bool Emif16FpgaOpenDevice(void)
{
	/* Initialize NAND interface */
	if (Emif16FpgaConfig() != TRUE) {
		//IFPRINT(platform_write("NandOpenDevice ... could not initialize the Nand Interface. \n"));
		return FALSE;
	}

	return TRUE;
}


/******************************************************************************
*
* Function:    Emif16FpgaConfig
*
* Description: This function is used to congigure the NAND Device
*
* Parameters:  None
*
* Return Value: Err Status
*
*****************************************************************************/
Bool Emif16FpgaConfig (void)
{
	uint32_t     power_domain_num            = 0;
	uint32_t     mdctl_emif16_module_num     = 3;
	uint32_t     mdstat_emif16_module_num    = 3;
	CSL_PSC_MODSTATE mdstat;

	/* Wake up EMIF16 module:
	 mdstat = CSL_PSC_getModuleState(mdstat_emif16_module_num); */
	uint32_t  loop_cnt = 0;

	/* program pdctl and mdctl to enable the module. */
	CSL_PSC_enablePowerDomain(power_domain_num);
	CSL_PSC_setModuleNextState (mdctl_emif16_module_num, PSC_MODSTATE_ENABLE);

	// start the process and wait. but timeout in 1000 loops.
	CSL_PSC_startStateTransition(power_domain_num);
	while(((CSL_PSC_isStateTransitionDone (power_domain_num)) != 0) && (loop_cnt < 1000)) {
	 loop_cnt++;
	}

	mdstat = CSL_PSC_getModuleState(mdstat_emif16_module_num);
	/* report result. */
	if (mdstat != PSC_MODSTATE_ENABLE) {
	//platform_errno = PLATFORM_ERRNO_PSCMOD_ENABLE;
	return FALSE; /* Could not enable the PSC Module */
	}

  /* Config fpga FCR reg*/
  hEmif16Cfg->A0CR = (0                                         \
	  | (1 << 31)     /* selectStrobe */ \
	  | (0 << 30)     /* extWait (never with NAND) */ \
	  | (0xf << 26)   /* writeSetup  10 ns */ \
	  | (0x3f << 20)  /* writeStrobe 40 ns */ \
	  | (7 << 17)     /* writeHold   10 ns */ \
	  | (0xf << 13)   /* readSetup   10 ns */ \
	  | (0x3f << 7)   /* readStrobe  60 ns */ \
	  | (7 << 4)      /* readHold    10 ns */ \
	  | (3 << 2)      /* turnAround  40 ns */ \
	  | (1 << 0));   /* asyncSize   16-bit bus */ \


	  /* Config fpga FCR reg*/
	  hEmif16Cfg->A1CR = (0                                         \
		  | (1 << 31)     /* selectStrobe */ \
		  | (0 << 30)     /* extWait (never with NAND) */ \
		  | (0xf << 26)   /* writeSetup  10 ns */ \
		  | (0x3f << 20)  /* writeStrobe 40 ns */ \
		  | (7 << 17)     /* writeHold   10 ns */ \
		  | (0xf << 13)   /* readSetup   10 ns */ \
		  | (0x3f << 7)   /* readStrobe  60 ns */ \
		  | (7 << 4)      /* readHold    10 ns */ \
		  | (3 << 2)      /* turnAround  40 ns */ \
		  | (1 << 0));   /* asyncSize   16-bit bus */ \

		  /* Config fpga FCR reg*/
		  hEmif16Cfg->A2CR = (0                                         \
			  | (1 << 31)     /* selectStrobe */ \
			  | (0 << 30)     /* extWait (never with NAND) */ \
			  | (0xf << 26)   /* writeSetup  10 ns */ \
			  | (0x3f << 20)  /* writeStrobe 40 ns */ \
			  | (7 << 17)     /* writeHold   10 ns */ \
			  | (0xf << 13)   /* readSetup   10 ns */ \
			  | (0x3f << 7)   /* readStrobe  60 ns */ \
			  | (7 << 4)      /* readHold    10 ns */ \
			  | (3 << 2)      /* turnAround  40 ns */ \
			  | (1 << 0));   /* asyncSize   16-bit bus */ \

  /* Set the wait polarity */
  hEmif16Cfg->AWCCR = (0x80            /* max extended wait cycle */ \
	  | (0 << 20)     /* 16������ CS2 uses WAIT0 */    \
	  | (0 << 28));  /* 29�� ����WAIT0 polarity low */ \



	/*
	Wait Rise.
	Set to 1 by hardware to indicate rising edge on the
	corresponding WAIT pin has been detected.
	The WP0-3 bits in the Async Wait Cycle Config register have
	no effect on these bits.
	*/

	/*
	Asynchronous Timeout.
	Set to 1 by hardware to indicate that during an extended
	asynchronous memory access cycle, the WAIT signal did not
	go inactive within the number of cycles defined by the
	MAX_EXT_WAIT field in Async Wait Cycle Config register.
	*/

	hEmif16Cfg->IRR = (1                      /* clear async timeout */ \
	  | (1 << 2));   /* clear wait rise */ \

	return TRUE;
}


