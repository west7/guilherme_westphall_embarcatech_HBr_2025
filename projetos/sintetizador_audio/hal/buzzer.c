#include "inc/buzzer.h"

uint slice_num;
uint channel_num;

void pwm_buzzer_init()
{
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    
    slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
    channel_num = pwm_gpio_to_channel(BUZZER_PIN);

    // pwm_set_wrap(slice_num, 4095); // O que é wrap ??

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.0f);
    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(BUZZER_PIN, 0);
}

void buzzer_play(uint16_t *adc_buffer)
{
    /* const uint32_t delay_us = 1000000 / SAMPLE_RATE;

    for (size_t i = 0; i < SAMPLES; i++)
    {
        pwm_set_chan_level(slice_num, channel_num, adc_buffer[i]);
        sleep_ms(delay_us);
    } */
   // Ajustar função
}