#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main()
{
    stdio_init_all();

    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(ADC_TEMPERATURE_CHANNEL_NUM);

    while (true)
    {
        float voltage = adc_read() * 3.3 / 4095.0f ;
        float temp = 27 - (voltage - 0.706) / 0.001721;
        printf("Temperatura: %2.f Cº\n", temp);
        sleep_ms(1000);
    }
}
