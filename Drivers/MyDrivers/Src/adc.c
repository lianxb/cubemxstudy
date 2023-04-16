#include "adc.h"
//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//ADC��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/4/11
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	

//���ADCֵ
//ch: ͨ��ֵ 0~16��ȡֵ��ΧΪ��ADC_CHANNEL_0~ADC_CHANNEL_16
//����ֵ:ת�����
uint16_t Get_Adc(ADC_HandleTypeDef *hadc) {

    //����ADC
    HAL_ADC_Start(hadc);
    //��ѯת��
    HAL_ADC_PollForConversion(hadc, 10);
    //�ж�ת���Ƿ����
    if (HAL_IS_BIT_SET(HAL_ADC_GetState(hadc), HAL_ADC_STATE_REG_EOC)) {
        //�������һ��ADC1�������ת�����
        return (uint16_t) HAL_ADC_GetValue(hadc);
    }
    //ADC��ȡʧ�ܣ�����0xFFFF
    return UINT16_MAX;
}

//��ȡָ��ͨ����ת��ֵ��ȡtimes��,Ȼ��ƽ��
//times:��ȡ����
//����ֵ:ͨ��ch��times��ת�����ƽ��ֵ
__attribute__((unused)) uint16_t Get_Adc_Average(ADC_HandleTypeDef *hadc, uint8_t times) {
    uint32_t temp_val = 0;
    uint8_t t;
    for (t = 0; t < times; t++) {
        uint16_t adc_val = Get_Adc(hadc);
        //ADC��ȡʧ�ܣ�����0xFFFF
        if(adc_val == UINT16_MAX) {
            return UINT16_MAX;
        }
        temp_val += adc_val;
        HAL_Delay(5);
    }
    return temp_val / times;
} 
