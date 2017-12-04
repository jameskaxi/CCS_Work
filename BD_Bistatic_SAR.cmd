/******************************************************************************
 * Copyright (c) 2010-2011 Texas Instruments Incorporated - http://www.ti.com
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 *****************************************************************************/
/*
 *  Linker command file
 *
 */

SECTIONS
{

	/**************ʸ���㷨�����ö�*******************/
	.racovec: >MSMCSRAM
	{
			*.* (.text:Raco_Vec_C6678_Text) {START(Raco_Vec_C6678_Start) SIZE(Raco_Vec_C6678_Size)}
	}

//	.test > L2SRAM
//	{
//		*(.fardata:ti_sysbios_knl_Task_Object__table__V)
//	}
	.Raco_Vec_C6678_L2	load >> L2SRAM
	.Raco_Vec_C6678_L3	load >> MSMCSRAM

	/**************�������ö�*******************/
    GROUP  //�������MSMCSRAM
    {
    	.qmssSharedMem
      	.cppiSharedMem
    	.i2ceeprom         //i2ceeprom�α������MSMCSRAM
    	.emif16nandflash 	//emif16nandflash�α������MSMCSRAM
    	.srioSharedMem    	//srio����msmc�ϵĴ���
    	.ChipIntc           //Ƭ���жϿ������Ķ�
    	.Sharemem           //edma3��˲���main.c�����еĶ�
    	.timerSharedMem      //timer��˲���main.c�����еĶ�
    	.GPIO
    	.csl_vect
    } > MSMCSRAM
    GROUP //�������L2��
    {
    	.srioL2Mem	//srio����L2�ϵĴ���
    	.qmssL2Mem          //qmss����L2�ϵĴ���
    	.cppiL2Mem          //cppi����L2�ϵĴ���
    	.CoreIntcL2Mem		//coreintc����L2�ϵĴ���
    	.edma3				//edma3����L2�ϵĴ���
    	.VlfftSyn
    } > L2SRAM

	/***************�û��Զ����**********************/
	.L2:  > L2SRAM
	.L3   > MSMCSRAM
	.DDR  > DDR3

}
