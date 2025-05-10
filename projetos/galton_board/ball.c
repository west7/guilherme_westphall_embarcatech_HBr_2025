#include "ball.h"
#include "board.h"

extern int histogram[BUCKETS];
extern uint32_t total_balls;

void init_ball(ball_t *ball)
{
    ball->row = 0;
    ball->x = CENTER_X;
    ball->y = START_Y;
    ball->active = true;
}

void update_ball(ball_t *ball)
{
    if (!ball->active)
        return;

    if (ball->y % PADDING_Y == 0)
    {
        float r = (float)rand() / (float)RAND_MAX;
        float threshold = 0.5f + (BIAS / 2.0f);
        int shift = (r < threshold) ? -PADDING_X / 2 : +PADDING_X / 2;
        ball->x += shift;

        int board_half = BOARD_ROWS * PADDING_X / 2;
        if (ball->x < CENTER_X - board_half)
            ball->x = CENTER_X - board_half;

        if (ball->x > CENTER_X + board_half)
            ball->x = CENTER_X + board_half;
    }

    ball->y++;

    if (ball->y >= ssd1306_height - 1)
    {
        int bucket = ball->x / (ssd1306_width / BUCKETS);
        if (bucket >= 0 && bucket < BUCKETS)
        {
            histogram[bucket]++;
            total_balls++;
        }
        ball->active = false;
    }
}

void draw_ball(uint8_t *ssd, ball_t *ball)
{
    if (!ball->active)
        return;

    if (ball->x >= 0 && ball->x < ssd1306_width && ball->y >= 0 && ball->y < ssd1306_height)
        ssd1306_set_pixel(ssd, ball->x, ball->y, true);
}