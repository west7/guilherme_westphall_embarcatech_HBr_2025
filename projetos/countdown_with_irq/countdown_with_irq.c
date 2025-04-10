#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"

#define BTN_A 5
#define BTN_B 6
#define I2C_SDA 14
#define I2C_SCL 15

int main()
{
    stdio_init_all();

    // Botão A
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);

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
        start_column: 0,
        end_column: ssd1306_width - 1,
        start_page: 0,
        end_page: ssd1306_n_pages - 1,
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
    int y_pos = 32; // Centraliza o texto verticalmente na tela

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);

        const size_t msg_len = sizeof(msg) / sizeof(msg[0]);
        for (size_t i = 0; i < msg_len; i++) {

            ssd1306_draw_string(ssd, x_pos, y_pos, msg[i]);
            render_on_display(ssd, &frame);
            sleep_ms(1000);
        }

        ssd1306_draw_string(ssd, 0, y_pos, "End of countdown"); 
        render_on_display(ssd, &frame);
        sleep_ms(100);
        return 0;
    }
}
