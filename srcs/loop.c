/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:26 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 11:12:27 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		init->game->sideDistX = (init->game->mapX + 1.0 - init->game->posX)
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
		init->game->sideDistY = (init->game->mapY + 1.0 - init->game->posY)
			* init->game->deltaDistY;
	}
}

void	ft_dda(t_init *init, int *side, double stepX, double stepY)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (init->game->sideDistX < init->game->sideDistY)
		{
			init->game->sideDistX += init->game->deltaDistX;
			init->game->mapX += (int)stepX;
			*side = 0;
		}
		else
		{
			init->game->sideDistY += init->game->deltaDistY;
			init->game->mapY += (int)stepY;
			*side = 1;
		}
		if (init->map[init->game->mapY][init->game->mapX] == '1')
			hit++;
	}
}

void	ft_perp_dist(t_init *init, int side, int stepx, int stepy)
{
	if (!side)
		init->game->perpWallDist = ((double)init->game->mapX - \
				init->game->posX + (1 - stepx) / 2) / init->game->rayDirX;
	else
		init->game->perpWallDist = ((double)init->game->mapY - \
				init->game->posY + (1 - stepy) / 2) / init->game->rayDirY;
}

void	ft_init_vectors(t_init *init, int i)
{
	init->game->cameraX = 2 * i / (double)init->width - 1;
	init->game->rayDirX = init->game->dirX + init->game->planeX
		* init->game->cameraX;
	init->game->rayDirY = init->game->dirY + init->game->planeY
		* init->game->cameraX;
	init->game->mapX = (int)init->game->posX;
	init->game->mapY = (int)init->game->posY;
	if (!init->game->rayDirY)
		init->game->deltaDistX = 0;
	else if (!init->game->rayDirX)
		init->game->deltaDistX = 1;
	else
		init->game->deltaDistX = sqrt(1 + pow(init->game->rayDirY, 2) \
		/ pow(init->game->rayDirX, 2));
	if (!init->game->rayDirX)
		init->game->deltaDistY = 0;
	else if (!init->game->rayDirY)
		init->game->deltaDistY = 1;
	else
		init->game->deltaDistY = sqrt(1 + pow(init->game->rayDirX, 2) \
		/ pow(init->game->rayDirY, 2));
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
		ft_init_vectors(init, i);
		ft_step_and_sidedist(init, &stepx, &stepy);
		ft_dda(init, &side, stepx, stepy);
		ft_perp_dist(init, side, stepx, stepy);
		ft_draw_vertical_line(init, i, side);
		i++;
	}
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	return (0);
}
