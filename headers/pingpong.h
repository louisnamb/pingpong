#include <math.h>
#include "../mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>

typedef struct pingpong
{
	double x;
	double y;
	int colour;
	int	hypotenuse;
	double	angle;
	int	direction_x;
	int direction_y;
	int	radius;
	int	start;
} t_pingpong;

typedef struct window_info {
	void				*mlx;
	void				*img;
	void				*win;
	void				*addr;
	int					bbp;
	int					llen;
	int					end;
	int					width;
	int					h;
	int					min;
	t_pingpong			*game;
}	t_data;



void	colorise(t_data *data, int x, int y, int colour);
void	draw_circle(t_data *data, t_pingpong *ball);
int		draw_bounce(t_data *data, t_pingpong *ball);
void    solid_fill(t_data *data, int x, int start, int end, int colour);
void    move_diagonally(t_data *data, t_pingpong *ball);