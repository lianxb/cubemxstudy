#include "adc.h"
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

//获得ADC值
//ch: 通道值 0~16，取值范围为：ADC_CHANNEL_0~ADC_CHANNEL_16
//返回值:转换结果
uint16_t Get_Adc(ADC_HandleTypeDef *hadc) {

    //开启ADC
    HAL_ADC_Start(hadc);
    //轮询转换
    HAL_ADC_PollForConversion(hadc, 10);
    //判断转换是否完成
    if (HAL_IS_BIT_SET(HAL_ADC_GetState(hadc), HAL_ADC_STATE_REG_EOC)) {
        //返回最近一次ADC1规则组的转换结果
        return (uint16_t) HAL_ADC_GetValue(hadc);
    }
    //ADC读取失败，返回0xFFFF
    return UINT16_MAX;
}

//获取指定通道的转换值，取times次,然后平均
//times:获取次数
//返回值:通道ch的times次转换结果平均值
__attribute__((unused)) uint16_t Get_Adc_Average(ADC_HandleTypeDef *hadc, uint8_t times) {
    uint32_t temp_val = 0;
    uint8_t t;
    for (t = 0; t < times; t++) {
        uint16_t adc_val = Get_Adc(hadc);
        //ADC读取失败，返回0xFFFF
        if(adc_val == UINT16_MAX) {
            return UINT16_MAX;
        }
        temp_val += adc_val;
        HAL_Delay(5);
    }
    return temp_val / times;
} 
