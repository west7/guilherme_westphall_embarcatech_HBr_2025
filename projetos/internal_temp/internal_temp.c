#include "internal_temp.h"

float adc_2_celsius(uint16_t adc_val)
{
    float voltage = adc_val * 3.3 / 4095.0f;
    float temp = 27 - (voltage - 0.706) / 0.001721;
    return temp;
}


