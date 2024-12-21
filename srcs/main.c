#include "../headers/pingpong.h"

// void	draw_menu(t_data *param)
// {
// 	char	*menu;

// 	menu = "press W-A-S-D to move";
// 	mlx_string_put(param->mlx, param->win, 20, 115, 0xffffff, menu);
// 	menu = "press ESC or RED-X to exit";
// 	mlx_string_put(param->mlx, param->win, 20, 140, 0xffffff, menu);
// 	menu = "press R to reset the map";
// 	mlx_string_put(param->mlx, param->win, 20, 175, 0xffffff, menu);
// 	return ;
// }

int	end(t_data *hook)
{
	mlx_destroy_window(hook->mlx, hook->win);
	mlx_destroy_image(hook->mlx, hook->img);
	free(hook);
	exit(0);
	return (0);
}

int	keys_pressed(int keycode, t_data *hook)
{
	if (keycode == 53)
		end(hook);
	return (0);
}

void	colorise(t_data *data, int x, int y, int colour)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->h)
		return ;
	dst = data->addr + (y * data->llen + x * (data->bbp / 8));
	*(unsigned int *)dst = colour;
}

void	initialisation(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->width = 680;
	mlx->h = 480;
	mlx->game = malloc(sizeof(t_pingpong));
	if (!mlx->game)
		return;
	mlx->game->x = 340.0;
    mlx->game->y = 240.0;
	mlx->game->radius = 10.0;
    mlx->game->colour = 0xFF0000;
	mlx->game->start = 1;
	mlx->game->angle = (double)(rand() % 100) / 100.0 * 2 * M_PI; // produce a random angle from 0 to 2*Pi
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->h, "fdf");
	mlx->img = mlx_new_image(mlx->mlx, mlx->width, mlx->h);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bbp, &mlx->llen, &mlx->end);
	if (!mlx->addr || !mlx->img)
	{
		write(1, "Error: Failed to create image or get address\n", 45);
		exit(1);
	}
	mlx_hook(mlx->win, 17, 0, end, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, keys_pressed, mlx);
	return ;
}

int	main()
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	if (!mlx)
	{
		write(1, "Error: Invalid arguments\n", 25);
		exit(1);
		return (1);
	}
	else
		initialisation(mlx);
	draw_bounce(mlx, mlx->game);
//	mlx_loop_hook(mlx->mlx, draw_bounce, &mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
