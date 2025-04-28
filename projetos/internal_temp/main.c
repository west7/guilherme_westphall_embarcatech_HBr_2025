#include <stdio.h>
#include <pico/stdlib.h>
#include "internal_temp.h"

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