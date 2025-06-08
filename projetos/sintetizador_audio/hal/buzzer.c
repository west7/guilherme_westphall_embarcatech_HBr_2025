#include "inc/buzzer.h"

uint slice_num;
uint channel_num;

void pwm_buzzer_init()
{
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);

    slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    channel_num = pwm_gpio_to_channel(BUZZER_PIN);

    uint16_t top = 4095;

    pwm_config config = pwm_get_default_config();
    pwm_config_set_wrap(&config, top);     
    pwm_config_set_clkdiv(&config, 1.0f); 
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(BUZZER_PIN, 0);
}

void buzzer_play(uint16_t *adc_buffer)
{
    const uint32_t delay_us = 1000000 / SAMPLE_RATE;

    for (size_t i = 0; i < SAMPLES; i++)
    {
        pwm_set_gpio_level(BUZZER_PIN, adc_buffer[i]);
        sleep_us(delay_us);
    }

    pwm_set_gpio_level(BUZZER_PIN, 0);
}