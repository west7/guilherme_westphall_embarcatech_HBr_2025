#include <stdio.h>
#include "pico/stdlib.h"
#include "inc/mic.h"
#include "inc/buzzer.h"

#define BUTTON_A 5
#define BUTTON_B 6
#define G_LED 11
#define B_LED 12
#define R_LED 13

volatile bool last_b_state = true;
volatile bool last_a_state = true;

typedef enum
{
    IDLE,
    RECORDING,
    PROCESSING,
    PLAYING
} state_t;

state_t state = IDLE;

int main()
{
    stdio_init_all();

    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    gpio_init(G_LED);
    gpio_set_dir(G_LED, GPIO_OUT);
    gpio_init(B_LED);
    gpio_set_dir(B_LED, GPIO_OUT);
    gpio_init(R_LED);
    gpio_set_dir(R_LED, GPIO_OUT);

    adc_dma_setup();
    sleep_ms(100);
    pwm_buzzer_init();
    sleep_ms(100);

    uint32_t recording_start = 0;
    uint16_t adc_buffer[SAMPLES];

    gpio_put(B_LED, 1);

    while (true)
    {
        bool current_a_state = gpio_get(BUTTON_A);
        bool current_b_state = gpio_get(BUTTON_B);

        switch (state)
        {
        case IDLE:
            if (!current_a_state && last_a_state)
            {
                state = RECORDING;
                gpio_put(B_LED, 0);
            }
            break;

        case RECORDING:
            // recording_start = time_us_32();
            gpio_put(R_LED, 1);
            record_mic(adc_buffer);
            gpio_put(R_LED, 0);

            /* if ((uint64_t)(time_us_32() - recording_start) >=
                ((uint64_t)SAMPLES * 1000000ULL) / 8000ULL)
            {
                state = PROCESSING;
                for (int i = 0; i < SAMPLES; i++)
                {
                    printf("%d ", adc_buffer[i]);
                }
                printf("\n");
            } */
            state = PROCESSING;
            break;

        case PROCESSING:
            if ((time_us_32() / 500000) % 2)
                gpio_put(B_LED, 1);
            else
                gpio_put(B_LED, 0);

            if (!current_b_state && last_b_state)
            {
                state = PLAYING;
                gpio_put(B_LED, 0);
            }
            else if (!current_a_state && last_a_state)
            {
                state = RECORDING;
                gpio_put(B_LED, 0);
            }
            break;

        case PLAYING:
            // Reproduzir aúdio
            gpio_put(G_LED, 1);
            buzzer_play(adc_buffer);
            gpio_put(G_LED, 0);
            
            state = PROCESSING;
            break;
        }

        last_a_state = current_a_state;
        last_b_state = current_b_state;
        sleep_ms(50);
    }
}
