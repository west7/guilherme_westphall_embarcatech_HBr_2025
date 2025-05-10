#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "inc/ssd1306.h"
#include "ball.h"

#define PADDING_X 4
#define PADDING_Y 4
#define BOARD_ROWS 10
#define CENTER_X (ssd1306_width / 2)
#define START_Y 0
#define BOTTOM_Y (ssd1306_width - ((BOARD_ROWS - 1) * PADDING_Y))
#define BUCKETS 64
#define BUCKETS_W (ssd1306_width / BUCKETS)
#define HIST_SCALE 50
#define BIAS 0.0f // 0.0 - Neutro, +0.6 - 80% para esq, -0.6 - 80% para dir

void draw_board(uint8_t *ssd, int rows);
void draw_bar(uint8_t *ssd, int bucket, int h, int y_base);
void draw_histogram(uint8_t *ssd);

#endif