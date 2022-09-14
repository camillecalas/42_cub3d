#include "../include/cub3D.h"

void	ft_step_and_sidedist(t_init *init, double *stepX, double *stepY)
{
	if (init->game->rayDirX < 0)
	{
		*stepX = -1;
		// init->game->sideDistX = (init->game->posX - init->game->mapX)
		// 	* init->game->deltaDistX;
	}
	else if (init->game->rayDirX > 0)
	{
		*stepX = 1;
		// init->game->sideDistX = (init->game->mapX + 1 - init->game->posX)
			// * init->game->deltaDistX;
	}
	else
		*stepX = 0;
	if (init->game->rayDirY < 0)
	{
		*stepY = -1;
		// init->game->sideDistY = (init->game->posY - init->game->mapY)
		// 	* init->game->deltaDistY;
	}
	else if (init->game->rayDirY > 0)
	{
		*stepY = 1;
		// init->game->sideDistY = (init->game->mapY + 1 - init->game->posY)
		// 	* init->game->deltaDistY;
	}
	else
		*stepY = 0;
}

void	ft_dda(t_init *init, int *side, double stepX, double stepY)
{
	int	hit;
	int	x;
	int	y;

	hit = 0;
	while (!hit)
	{
		// if ((init->game->deltaDistX && init->game->deltaDistX < init->game->deltaDistY) || !init->game->deltaDistY)
		if ((init->game->sideDistX
				&& init->game->sideDistX < init->game->sideDistY)
			|| !init->game->sideDistY)
		{
			init->game->sideDistX += init->game->deltaDistX;
			init->game->mapX += stepX;
			*side = 0;
		}
		else
		{
			init->game->sideDistY += init->game->deltaDistY;
			init->game->mapY += stepY;
			*side = 1;
		}
		x = (int)init->game->mapX;
		y = (int)init->game->mapY;
		if (init->map[y][x] == '1')
			hit++;
	}
}

void	ft_perp_dist(t_init *init, int side, int stepx, int stepy)
{
	if (!side)
		init->game->perpWallDist = (init->game->mapX - init->game->posX) + \
				(1 - stepx / 2) / init->game->rayDirX;
		// init->game->perpWallDist = fabs(init->game->posX
		// 		- init->game->mapX);
	else
		init->game->perpWallDist = (init->game->mapY - init->game->posY) + \
				(1 - stepy / 2) / init->game->rayDirY;
		// init->game->perpWallDist = fabs(init->game->posY
		// 		- init->game->mapY);
}

int	ft_game_loop(t_init *init)
{
	int		i;
	int		side;
	double	stepx;
	double	stepy;

	i = 0;
	while (i < init->width)
	{
		init->game->cameraX = 2 * i / (double)init->width - 1;
		init->game->rayDirX = init->game->dirX + init->game->planeX
			* init->game->cameraX;
		init->game->rayDirY = init->game->dirY + init->game->planeY
			* init->game->cameraX;
		init->game->mapX = init->game->posX;
		init->game->mapY = init->game->posY;
		if (!init->game->rayDirX)
			init->game->deltaDistX = 0;
		else
			init->game->deltaDistX = fabs(sqrt(pow(init->game->rayDirX, 2) \
			+ pow(init->game->rayDirY, 2)) / init->game->rayDirX);
		if (!init->game->rayDirY)
			init->game->deltaDistY = 0;
		else
			init->game->deltaDistY = fabs(sqrt(pow(init->game->rayDirX, 2) \
			+ pow(init->game->rayDirY, 2)) / init->game->rayDirY);
		init->game->sideDistX = init->game->deltaDistX;
		init->game->sideDistY = init->game->deltaDistY;
		ft_step_and_sidedist(init, &stepx, &stepy);
		ft_dda(init, &side, stepx, stepy);
		ft_perp_dist(init, side, stepx, stepy);
		ft_draw_vertical_line(init, i, side);
		i++;
	}
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	// printf("init->game->rayDirX %f\n", init->game->rayDirX );
	ft_move_forward(init, init->game);
	return (0);
}
