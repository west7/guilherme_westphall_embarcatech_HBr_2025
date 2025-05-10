#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "inc/ssd1306.h"
#include "ball.h"
#include "board.h"

#define A 5
#define B 6

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15

static ball_t balls[MAX_BALLS]; 
int histogram[BUCKETS];
uint32_t total_balls = 0;
static uint32_t tick = 0;
static bool show_histogram = false; 

int main()
{
    stdio_init_all();

    gpio_init(B);
    gpio_set_dir(B, GPIO_IN);
    gpio_pull_up(B);

    i2c_init(I2C_PORT, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();

    struct render_area frame = {
        .start_column = 0,
        .end_column = ssd1306_width - 1,
        .start_page = 0,
        .end_page = ssd1306_n_pages - 1,
    };
    calculate_render_area_buffer_length(&frame);

    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);

    draw_board(ssd, BOARD_ROWS);
    render_on_display(ssd, &frame);

    for (int i = 0; i < MAX_BALLS; i++)
        balls[i].active = false;

    static bool prev_b_state = true;

    while (true)
    {
        bool curr_b_state = gpio_get(B);

        if (!curr_b_state && prev_b_state)
            show_histogram = !show_histogram;

        prev_b_state = curr_b_state;

        // Atualização da lógica das bolinhas SEMPRE ocorre
        if (tick % SPAWN_INTERVAL == 0)
        {
            for (int i = 0; i < MAX_BALLS; i++)
            {
                if (!balls[i].active)
                {
                    init_ball(&balls[i]);
                    break;
                }
            }
        }

        for (int i = 0; i < MAX_BALLS; i++)
        {
            update_ball(&balls[i]);
        }

        // Desenho na tela
        memset(ssd, 0, ssd1306_buffer_length);

        if (show_histogram)
        {
            draw_histogram(ssd);
            render_on_display(ssd, &frame);
        }
        else
        {
            draw_board(ssd, BOARD_ROWS);
        }

        for (int i = 0; i < MAX_BALLS; i++)
        {
            draw_ball(ssd, &balls[i]);
        }

        render_on_display(ssd, &frame);
        sleep_ms(30);
        tick++;
    }
}
