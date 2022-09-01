#include "../include/cub3D.h"

void	ft_step_and_sidedist(t_init *init, double *stepX, double *stepY)
{
	if (init->game->rayDirX < 0)
	{
		*stepX = -1;
		init->game->sideDistX = (init->game->posX - init->game->mapX)
			* init->game->deltaDistX;
	}
	else
	{
		*stepX = 1;
		init->game->sideDistX = (init->game->mapX + 1 - init->game->posX)
			* init->game->deltaDistX;
	}
	if (init->game->rayDirY < 0)
	{
		*stepY = -1;
		init->game->sideDistY = (init->game->posY - init->game->mapY)
			* init->game->deltaDistY;
	}
	else
	{
		*stepY = 1;
		init->game->sideDistY = (init->game->mapY + 1 - init->game->posY)
			* init->game->deltaDistY;
	}
}

void	ft_dda(t_init *init, int *side, double stepX, double stepY)
{
	int	hit;

	hit = 0;
	// dans cette boucle doit etre inclus une mise a jour de la valeur de deltaDist
	while (!hit)
	{
		if (init->game->sideDistX < init->game->sideDistY)
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
		hit = 1;
		// if (init->map[(int)init->game->mapX][(int)init->game->mapY] == '1')
		// 	hit++;
	}
}

void	ft_game_loop(t_init *init)
{
	int		i;
	int		side;
	double	stepx;
	double	stepy;

	while (1)
	{
		i = 960;
		while (i < WIDTH)
		{
			init->game->cameraX = 2 * i / (double)WIDTH - 1;
			init->game->rayDirX = init->game->dirX + init->game->planeX
				* init->game->cameraX;
			init->game->rayDirY = init->game->dirY + init->game->planeY
				* init->game->cameraX;
			init->game->mapX = init->game->posX;
			init->game->mapY = init->game->posY;
			printf("rayDirX: %f\n", init->game->rayDirX);
			printf("rayDirY: %f\n", init->game->rayDirY);
			if (!init->game->rayDirX)
				init->game->deltaDistX = 1e30;
			else
				init->game->deltaDistX = fabs(1 / init->game->rayDirX);
			printf("deltaDistX: %f\n", init->game->deltaDistX);
			if (!init->game->rayDirY)
				init->game->deltaDistY = 1e30;
			else
				init->game->deltaDistY = fabs(1 / init->game->rayDirY);
			printf("deltaDistY: %f\n", init->game->deltaDistY);
			ft_step_and_sidedist(init, &stepx, &stepy);
			printf("sideDistX: %f\n", init->game->sideDistX);
			printf("sideDistY: %f\n", init->game->sideDistY);
			ft_dda(init, &side, stepx, stepy);
			if (!side)
				init->game->perpWallDist = init->game->sideDistX
					- init->game->deltaDistX;
			else
				init->game->perpWallDist = init->game->sideDistY
					- init->game->deltaDistY;
			printf("perpWallDist: %f\n", init->game->perpWallDist);
			// ft_draw_vertical_line(init);
			break ;
			i++;
		}
		break ;
	}
}
