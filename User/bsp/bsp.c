/*
*********************************************************************************************************
*
*	模块名称 : BSP模块(For STM32F4XX)
*	文件名称 : bsp.c
*	版    本 : V1.1
*	说    明 : 这是硬件底层驱动程序的主文件。每个c文件可以 #include "bsp.h" 来包含所有的外设驱动模块。
*			   bsp = Borad surport packet 板级支持包
*	修改记录 :
*		版本号  日期        作者     说明
*		V1.0    2013-03-01  armfly   正式发布
*		V1.1    2013-06-20  armfly   规范注释，添加必要说明
*
*	Copyright (C), 2013-2014, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/
#include "includes.h"
#include "MainTask.h"



/*
*********************************************************************************************************
*	函 数 名: bsp_Init
*	功能说明: 初始化所有的硬件设备。该函数配置CPU寄存器和外设的寄存器并初始化一些全局变量。只需要调用一次
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
void bsp_Init(void)
{
	/*
		由于ST固件库的启动文件已经执行了CPU系统时钟的初始化，所以不必再次重复配置系统时钟。
		启动文件配置了CPU主时钟频率、内部Flash访问速度和可选的外部SRAM FSMC初始化。

		系统时钟缺省配置为168MHz，如果需要更改，可以修改 system_stm32f4xx.c 文件
	*/
	/* 使能CRC 因为使用STemWin前必须要使能 */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_CRC, ENABLE);
	
	/* 优先级分组设置为4，可配置0-15级抢占式优先级，0级子优先级，即不存在子优先级。*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	SystemCoreClockUpdate();	/* 根据PLL配置更新系统时钟频率变量 SystemCoreClock */

	bsp_InitDWT();       /* 初始DWT */
	bsp_InitUart(); 	/* 初始化串口 */
	bsp_InitKey();		/* 初始化按键变量（必须在 bsp_InitTimer() 之前调用） */
	
	bsp_InitI2C();		/* 配置I2C总线 */
	
	bsp_InitExtSDRAM();
	bsp_DetectLcdType(); /* 检测触摸板和LCD面板型号, 结果存在全局变量 g_TouchType, g_LcdType */
	
	TOUCH_InitHard();	 /* 初始化配置触摸芯片 */
	LCD_ConfigLTDC();    /* 初始化配置LTDC */
	
	DSO_ConfigCtrlGPIO();   /* 初始化示波器模块的引脚配置 */  
	
	bsp_InitADC();          /* 初始化ADC1，ADC2和ADC3 */
	bsp_InitDAC1();         /* 初始化DAC1 */
	
	g_DAC1.ucDuty = 50;     /* 初始化DAC配置，用于信号发生器 */
	g_DAC1.ucWaveType = 0;
	g_DAC1.ulAMP = 4095;
	g_DAC1.ulFreq = 10000;
	dac1_SetSinWave(g_DAC1.ulAMP, g_DAC1.ulFreq);

	MountSD();  			  /* 挂载SD卡 */
		
	TIM8_MeasureTrigConfig(); /* 初始化TIM8用于记录一段波形 */
}

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
