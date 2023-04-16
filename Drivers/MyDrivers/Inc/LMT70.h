//
// Created by 17795 on 2023/4/16.
//

#ifndef CUBEMXSTUDY_LMT70_H
#define CUBEMXSTUDY_LMT70_H
#include "stm32f4xx_hal.h"
#include "math.h"

double ADC2Voltage(uint16_t ADC_value);
double LMT70Voltage2Temperature(double LMT70_voltage);

#endif //CUBEMXSTUDY_LMT70_H
