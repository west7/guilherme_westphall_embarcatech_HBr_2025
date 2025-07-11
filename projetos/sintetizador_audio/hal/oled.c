#include "inc/oled.h"

char *text[] = {
    " Gravando     ",
    " Reproduzindo "};


void update_loading_animation(uint8_t *ssd, struct render_area *area, absolute_time_t start_time)
{
    const float duration_s = (float)SAMPLES / SAMPLE_RATE;
    const float duration_us = duration_s * 1000000.0f;
    const int total_width = area->end_column - area->start_column;

    int64_t elapsed_us = absolute_time_diff_us(start_time, get_absolute_time());

    int current_width = (int)((elapsed_us / duration_us) * total_width);
    current_width = current_width > total_width ? total_width
                                                : (current_width < 0 ? 0 : current_width);

    ssd1306_draw_line(ssd, area->start_column, 32, area->start_column + current_width, 32, true);

    render_on_display(ssd, area);
}

void draw_recording_text(uint8_t *ssd, struct render_area *area)
{
    memset(ssd, 0, ssd1306_buffer_length);
    ssd1306_draw_string(ssd, 0, 5, text[0]);
    render_on_display(ssd, area);
}

void draw_audio_wave(uint8_t *ssd, struct render_area *area, uint16_t *adc_buffer)
{

    const float adc_mid = 2048.0f;
    const float gain = 0.10f;

    memset(ssd, 0, ssd1306_buffer_length);

    int prev_x = 0;
    int prev_y = CENTER_Y;

    ssd1306_draw_string(ssd, 0, 5, text[1]);

    for (int i = 0; i < ssd1306_width && i < SAMPLES; i++)
    {
        int x = i;

        // Calcula a variação em torno do centro e aplica o ganho
        float delta = (float)adc_buffer[i] - adc_mid;
        int y = CENTER_Y - (int)(delta * gain);

        y = y < 0 ? 0 : (y >= ssd1306_height ? ssd1306_height - 1 : y);

        if (i > 0)
            ssd1306_draw_line(ssd, prev_x, prev_y, x, y, true);

        prev_x = x;
        prev_y = y;
        render_on_display(ssd, area);
    }
}