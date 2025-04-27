#include <stdio.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "internal_temp.h"

float adc_2_celsius(uint16_t adc_val)
{
    float voltage = adc_val * 3.3 / 4095.0f;
    float temp = 27 - (voltage - 0.706) / 0.001721;
    return temp;
}

int main()
{
    stdio_init_all();

    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(ADC_TEMPERATURE_CHANNEL_NUM);

    while (true)
    {
        float temp = adc_2_celsius(adc_read());
        printf("Temperatura: %2.f Cº\n", temp);
        sleep_ms(1000);
    }
}
