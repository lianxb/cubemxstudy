#ifndef __ADC_H
#define __ADC_H
#include "stm32f4xx_hal.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//ADC驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2017/4/11
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
uint16_t  Get_Adc(ADC_HandleTypeDef *hadc); 		        //获得某个通道值
uint16_t Get_Adc_Average(ADC_HandleTypeDef *hadc,uint8_t times);//得到某个通道给定次数采样的平均值
#endif 
