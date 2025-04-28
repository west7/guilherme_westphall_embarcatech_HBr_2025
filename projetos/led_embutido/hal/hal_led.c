#include "pico/cyw43_arch.h"
#include "include/led_embutido.h"

int hal_led_init()
{
    return led_init();
}

void hal_led_on()
{
    led_on();
}

void hal_led_off()
{

    led_off();
}