/*
*********************************************************************************************************
*
*	ģ������ : ͷ�ļ�����
*	�ļ����� : includes.h
*	��    �� : V1.0
*	˵    �� : ��ǰʹ��ͷ�ļ�����
*
*	�޸ļ�¼ :
*		�汾��    ����        ����     ˵��
*		V1.0    2015-08-02  Eric2013   �״η���
*
*	Copyright (C), 2015-2020, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#ifndef  __INCLUDES_H__
#define  __INCLUDES_H__

/*
*********************************************************************************************************
*                                         ��׼��
*********************************************************************************************************
*/
#include  <stdarg.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>


/*
*********************************************************************************************************
*                                           OS
*********************************************************************************************************
*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "croutine.h"
#include "semphr.h"
#include "event_groups.h"
#include "cpu_utils.h"


/*
*********************************************************************************************************
*                                           �궨��
*********************************************************************************************************
*/
/* ���ֲ������õ����¼���־ */
#define DspTaskInfo_13	        (1 << 13)  
#define DspMultiMeterPro_14	    (1 << 14)
#define DspFFT2048Pro_15	    (1 << 15)  


/*
*********************************************************************************************************
*                                        APP / BSP
*********************************************************************************************************
*/
#include "ff.h"
#include "rt_Memory.h"
#include  <bsp.h>


/*
*********************************************************************************************************
*                                          �����ͺ���
*********************************************************************************************************
*/
extern EventGroupHandle_t xCreatedEventGroup;
extern TaskHandle_t xHandleTaskMsgPro;

/* ���������е��� */
extern void vSetupSysInfoTest(void);


/*
*********************************************************************************************************
*                                          FatFS
*********************************************************************************************************
*/
extern FRESULT result;
extern FIL file;
extern UINT bw;
extern FATFS fs;

extern void MountSD(void);
extern void UnmountSD(void);
extern void _WriteByte2File(U8 Data, void * p); 
#endif

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/