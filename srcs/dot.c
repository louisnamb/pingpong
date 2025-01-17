#include "../headers/pingpong.h"

void draw_circle(t_data *data, t_pingpong *ball)
{
    int step_x;
    int step_y;

    step_x = (int)ball->x - (int)ball->radius;
    while (step_x <= (int)ball->x + (int)ball->radius)
    {
        if ((int)ball->radius * (int)ball->radius - (step_x - (int)ball->x) * (step_x - (int)ball->x) >= 0)
        {
            step_y = sqrt(((int)ball->radius * (int)ball->radius - (step_x - (int)ball->x) * (step_x - (int)ball->x)));
            colorise(data, step_x, ball->y - step_y, ball->colour);
            colorise(data, step_x, ball->y + step_y, ball->colour);
            solid_fill(data, step_x, ball->y + step_y, ball->y - step_y, ball->colour);
        //    printf("ball->x: %d step_x %d\n", ball->x, step_x);
        }
        step_x++;
    }
}

void    solid_fill(t_data *data, int x, int start, int end, int colour)
{
    while (start != end)
    {
        colorise(data, x, start, colour);
        start--;
    }
    return ;
}