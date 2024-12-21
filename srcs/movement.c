#include "../headers/pingpong.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void    move_diagonally(t_data *data, t_pingpong *ball)
{
//    ft_bzero(data->addr, data->width * data->h * (data->bbp / 8));
    if (ball->start)
    {
        draw_circle(data, ball);
        ball->start = 0;
        return ;
    }
 //   ball->colour = 0x000000;
  //  draw_circle(data, ball);
    ball->colour = 0x0000FF;
    ball->y += sin(ball->angle);  
    ball->x += cos(ball->angle);
    printf("(%d)")
    draw_circle(data, ball);
    return ;
}

int draw_bounce(t_data *data, t_pingpong *ball)
{
    if (!data || !ball)
        return (1);
    while ((int)(ball->x + ball->radius) < data->width && (int)(ball->y + ball->radius) < data->h)
    {
        printf("here\n");
        move_diagonally(data, ball);
        usleep(16000);
    }
  //  printf("%d < %d && %d < %d\n", ball->x + ball->radius, data->width, (ball->y + ball->radius), data->h);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    // while (1)
    // {
    //     if (ball->x + ball->radius + 5 >= data->width && (ball->y + ball->radius) < data->h)
    //     {
    //         ball->direction_x = 1;
    //         ball->direction_y = 1;
    //         move_diagonally(data, ball);
    //         mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    //         usleep(16000);
    //     }
    // }
    return (0);
}