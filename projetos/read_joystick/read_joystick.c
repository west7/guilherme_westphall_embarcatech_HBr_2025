#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main()
{
    stdio_init_all();

    adc_init();

    adc_gpio_init(26);
    adc_gpio_init(27);

    
    while (true) {
        adc_select_input(1);
        int raw_x = adc_read();

        adc_select_input(0);
        int raw_y = adc_read();

        printf("X: %d, Y: %d\n", raw_x, raw_y);
        sleep_ms(400);
    }
}
