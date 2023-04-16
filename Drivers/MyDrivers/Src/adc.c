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

ADC_HandleTypeDef ADC1_Handler;//ADC���

//���ADCֵ
//ch: ͨ��ֵ 0~16��ȡֵ��ΧΪ��ADC_CHANNEL_0~ADC_CHANNEL_16
//����ֵ:ת�����
uint16_t Get_Adc(uint32_t ch) {
    ADC_ChannelConfTypeDef ADC1_ChanConf;

    ADC1_ChanConf.Channel = ch;                                   //ͨ��
    ADC1_ChanConf.Rank = 1;                                       //��1�����У�����1
    ADC1_ChanConf.SamplingTime = ADC_SAMPLETIME_480CYCLES;        //����ʱ��
    ADC1_ChanConf.Offset = 0;
    HAL_ADC_ConfigChannel(&ADC1_Handler, &ADC1_ChanConf);        //ͨ������

    HAL_ADC_Start(&ADC1_Handler);                               //����ADC

    HAL_ADC_PollForConversion(&ADC1_Handler, 10);                //��ѯת��

    return (uint16_t) HAL_ADC_GetValue(&ADC1_Handler);            //�������һ��ADC1�������ת�����
}

//��ȡָ��ͨ����ת��ֵ��ȡtimes��,Ȼ��ƽ��
//times:��ȡ����
//����ֵ:ͨ��ch��times��ת�����ƽ��ֵ
uint16_t Get_Adc_Average(uint32_t ch, uint8_t times) {
    uint32_t temp_val = 0;
    uint8_t t;
    for (t = 0; t < times; t++) {
        temp_val += Get_Adc(ch);
        HAL_Delay(5);
    }
    return temp_val / times;
} 
