//
// Created by 17795 on 2023/4/16.
//

#include "LMT70.h"

//ADCֵת����ʵ�ʵ�ѹ����λΪmV
double ADC2Voltage(uint16_t ADC_value) {
    return (double) (ADC_value * 3.3 / 4096 * 1000);
}

//LMT70�¶ȴ������ĵ�ѹֵת�����������״��ݺ���
double LMT70Voltage2Temperature(double LMT70_voltage) {
    double a = 1.809628E-09;
    double b = 3.325395E-06;
    double c = 1.814103E-01;
    double d = 2.055894E+02;
    double temp;
    temp = d - a * pow(LMT70_voltage, 3) - b * pow(LMT70_voltage, 2) - c * LMT70_voltage;
    return temp;
}