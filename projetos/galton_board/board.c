#include "board.h"

extern int histogram[BUCKETS]; // Variáveis globais definidas em main.c
extern uint32_t total_balls;   // Variáveis globais
extern uint32_t tick;          // Variáveis globais
extern bool show_histogram;    // Controle da tela de histograma

void draw_board(uint8_t *ssd, int rows)
{
    for (int row = 0; row <= rows; row++)
    {
        int y = ssd1306_height - (rows - row + 1) * PADDING_Y;

        for (int col = -row; col <= row; col += 2)
        {
            int x = CENTER_X + col * PADDING_X;

            if (x >= 0 && x < ssd1306_width && y >= 0 && y < ssd1306_height)
            {
                ssd1306_set_pixel(ssd, x, y, true);
            }
        }
    }
}

void draw_bar(uint8_t *ssd, int bucket, int h, int y_base)
{
    if (h <= 0)
        return;

    int x_start = bucket * BUCKETS_W;
    for (int dx = 0; dx < BUCKETS_W; dx++)
    {

        for (int dy = 0; dy < h; dy++)
        {
            ssd1306_set_pixel(ssd, x_start + dx, y_base - dy, true);
        }
    }
    printf("Bar %d: x from %d to %d, y from %d to %d\n", bucket, x_start, x_start + BUCKETS_W - 1, y_base - h + 1, y_base);
}

void draw_histogram(uint8_t *ssd)
{
    int max_height = 0;
    for (int i = 0; i < BUCKETS; i++)
        if (histogram[i] > max_height)
            max_height = histogram[i];

    if (max_height == 0)
        return;

    for (int i = 0; i < BUCKETS; i++)
    {
        int h = (histogram[i] * (ssd1306_height - 8)) / max_height;
        if (h > ssd1306_height - 8)
            h = ssd1306_height - 8;
        draw_bar(ssd, i, h, ssd1306_height - 1);
    }

    char buf[16];
    snprintf(buf, sizeof buf, "%lu", total_balls);
    ssd1306_draw_string(ssd, 0, 0, buf);
}