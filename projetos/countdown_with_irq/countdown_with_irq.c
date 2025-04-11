#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"

#define BTN_A 5
#define BTN_B 6
#define I2C_SDA 14
#define I2C_SCL 15

volatile bool reset = true;

void btn_a_callback(uint gpio, uint32_t events)
{
    if (gpio == BTN_A && (events & GPIO_IRQ_EDGE_FALL))
        reset = true;
}

int main()
{
    stdio_init_all();

    // Botão A
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &btn_a_callback);

    // Botão B
    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);

    // Display OLED
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init();

    struct render_area frame = {
        start_column : 0,
        end_column : ssd1306_width - 1,
        start_page : 0,
        end_page : ssd1306_n_pages - 1,
    };

    calculate_render_area_buffer_length(&frame);

    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame);

    char *msg[] = {
        "9",
        "8",
        "7",
        "6",
        "5",
        "4",
        "3",
        "2",
        "1",
        "0",
    };

    int x_pos = 64; // Centraliza o texto horizontalmente na tela
    int y_pos = 16; // Centraliza o texto verticalmente na tela

    int x2_pos = x_pos - 48;
    int y2_pos = y_pos + 16;

    bool last_btn_b_state = true;
    char str_buffer[16];

    while (true)
    {
        if (reset)
        {
            reset_loop:
        
            reset = false;
            
            const size_t msg_len = sizeof(msg) / sizeof(msg[0]);
            uint16_t count_btn_b = 0;

            for (size_t i = 0; i < msg_len; i++)
            {
                memset(ssd, 0, ssd1306_buffer_length);
                ssd1306_draw_string(ssd, x_pos, y_pos, msg[i]);
                sprintf(str_buffer, "Button b: %d", count_btn_b);
                ssd1306_draw_string(ssd, x2_pos, y2_pos, str_buffer);
                render_on_display(ssd, &frame);

                uint32_t start_time = to_ms_since_boot(get_absolute_time());
                while (to_ms_since_boot(get_absolute_time()) - start_time < 1000)
                {
                    bool btn_b_state = gpio_get(BTN_B);

                    if (!btn_b_state && last_btn_b_state)
                    {
                        count_btn_b++;
                        memset(ssd, 0, ssd1306_buffer_length);
                        ssd1306_draw_string(ssd, x_pos, y_pos, msg[i]);
                        sprintf(str_buffer, "Button b: %d", count_btn_b);
                        ssd1306_draw_string(ssd, x2_pos, y2_pos, str_buffer);
                        render_on_display(ssd, &frame);
                    }
                    last_btn_b_state = btn_b_state;

                    if (!gpio_get(BTN_A)) {
                        sleep_ms(50);
                        goto reset_loop;
                    }

                    sleep_ms(10);
                }

                sprintf(str_buffer, "Button b: %d", count_btn_b);
                ssd1306_draw_string(ssd, x2_pos, y2_pos, str_buffer);
                render_on_display(ssd, &frame);
            }
        }

        tight_loop_contents();
    }
}
