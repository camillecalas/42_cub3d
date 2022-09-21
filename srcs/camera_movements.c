/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:11:42 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 15:48:20 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_dispatch_map_func(char *filepath, int fd, int nb, t_init *init)
{
	ft_cpy_map_lines(filepath, fd, nb, init);
	ft_check_map(init);
}

void	ft_move_camera_left(t_init *init, t_game *game, \
double prevplanex, double prevdirx)
{
	if (init->moves.camera_l == 1)
	{
		game->dirX = game->dirX * cos(-(game->rotSpeed / 2)) - game->dirY \
			* sin(-(game->rotSpeed) / 2);
		game->dirY = prevdirx * sin(-(game->rotSpeed / 2)) + game->dirY \
			* cos(-(game->rotSpeed) / 2);
		game->planeX = game->planeX * cos(-(game->rotSpeed) / 2) \
			- game->planeY * sin(-(game->rotSpeed) / 2);
		game->planeY = prevplanex * sin(-(game->rotSpeed) / 2) + game->planeY \
			* cos(-(game->rotSpeed / 2));
	}
}

void	ft_move_camera(t_init *init, t_game *game)
{
	double	prevplanex;
	double	prevdirx;
	double	oldplanex;

	prevplanex = game->planeX;
	prevdirx = game->dirX;
	if (init->moves.camera_r == 1)
	{
		prevdirx = game->dirX;
		oldplanex = game->planeX;
		game->dirX = game->dirX * cos(game->rotSpeed / 2) - game->dirY \
			* sin(game->rotSpeed / 2);
		game->dirY = prevdirx * sin(game->rotSpeed / 2) + game->dirY \
			* cos(game->rotSpeed / 2);
		game->planeX = game->planeX * cos(game->rotSpeed / 2) - game->planeY \
			* sin(game->rotSpeed / 2);
		game->planeY = oldplanex * sin(game->rotSpeed / 2) + game->planeY \
			* cos(game->rotSpeed / 2);
	}
	ft_move_camera_left(init, game, prevplanex, prevdirx);
}
