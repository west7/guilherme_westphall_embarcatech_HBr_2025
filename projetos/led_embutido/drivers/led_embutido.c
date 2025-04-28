#include "pico/cyw43_arch.h"

int led_init()
{
    return cyw43_arch_init(); 
}

void led_on()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
}

void led_off()
{
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
}