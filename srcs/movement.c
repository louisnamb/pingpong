#include "../headers/pingpong.h"

void    move_diagonally(t_data *data, t_pingpong *ball)
{
    if (ball->start)
    {
        draw_circle(data, ball);
        ball->start = 0;
    //    printf("here\n");
        return ;
    }
 //   ball->colour = 0x000000;
  //  draw_circle(data, ball);
    ball->colour = 0x0000FF;
    ball->y += (ball->hypotenuse * (sin(ball->angle))) * 0.2;  
    ball->x += (ball->hypotenuse * (cos(ball->angle))) * 0.2;
    draw_circle(data, ball);
    return ;
}

int draw_bounce(t_data *data, t_pingpong *ball)
{
    if (!data || !ball)
        return (1);
    ball->angle = atan((double)ball->y/ball->x);
    ball->hypotenuse = sqrt((ball->x * ball->x) + (ball->y * ball->y));
    while (ball->x + ball->radius < data->width && (ball->y + ball->radius) < data->h)
    {
        move_diagonally(data, ball);
        mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
        usleep(16000);
    }
    return (0);
}