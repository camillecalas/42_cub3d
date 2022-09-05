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
		if ((init->game->sideDistX && init->game->sideDistX < init->game->sideDistY) || !init->game->sideDistY)
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
		printf("map[%d][%d]: %c\n", y, x, init->map[y][x]);
		if (init->map[y][x] == '1')
			hit++;
	}
	printf("mapX: %f\n", init->game->mapX);
	printf("mapY: %f\n", init->game->mapY);
}

void	ft_game_loop(t_init *init)
{
	int		i;
	int		side;
	double	stepx;
	double	stepy;

	while (1)
	{
		i = 480 * 2;
		while (i < WIDTH)
		{
			init->game->cameraX = 2 * i / (double)WIDTH - 1;
			init->game->rayDirX = init->game->dirX + init->game->planeX
				* init->game->cameraX;
			init->game->rayDirY = init->game->dirY + init->game->planeY
				* init->game->cameraX;
			init->game->mapX = init->game->posX;
			init->game->mapY = init->game->posY;
			printf("mapX: %f\n", init->game->mapX);
			printf("mapY: %f\n", init->game->mapY);
			printf("rayDirX: %f\n", init->game->rayDirX);
			printf("rayDirY: %f\n", init->game->rayDirY);
			if (!init->game->rayDirX)
				init->game->deltaDistX = 0;
			else
				init->game->deltaDistX = fabs(sqrt(pow(init->game->rayDirX, 2) + pow(init->game->rayDirY, 2)) / init->game->rayDirX);
			printf("deltaDistX: %f\n", init->game->deltaDistX);
			if (!init->game->rayDirY)
				init->game->deltaDistY = 0;
			else
				init->game->deltaDistY = fabs(sqrt(pow(init->game->rayDirX, 2) + pow(init->game->rayDirY, 2)) / init->game->rayDirY);
			printf("deltaDistY: %f\n", init->game->deltaDistY);
			init->game->sideDistX = init->game->deltaDistX;
			init->game->sideDistY = init->game->deltaDistY;
			ft_step_and_sidedist(init, &stepx, &stepy);
			printf("sideDistX: %f\n", init->game->sideDistX);
			printf("sideDistY: %f\n", init->game->sideDistY);
			printf("stepX: %f\n", stepx);
			printf("stepY: %f\n", stepy);
			ft_dda(init, &side, stepx, stepy);
			printf("side: %d\n", side);
			if (!side)
				init->game->perpWallDist = fabs(init->game->posX
					- init->game->mapX);
			else
				init->game->perpWallDist = fabs(init->game->posY
					- init->game->mapY);
			printf("perpWallDist: %f\n", init->game->perpWallDist);
			ft_draw_vertical_line(init);
			break ;
			i++;
		}
		break ;
	}
}
