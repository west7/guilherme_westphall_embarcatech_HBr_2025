#ifndef BALL_H
#define BALL_H

#include "inc/ssd1306.h"
#include "stdlib.h"

#define MAX_BALLS 100
#define SPAWN_INTERVAL 1

typedef struct ball_t
{
    int x;
    int y;
    int row;
    bool active;
} ball_t;

void init_ball(ball_t *ball);
void update_ball(ball_t *ball);
void draw_ball(uint8_t *ssd, ball_t *ball);

#endif