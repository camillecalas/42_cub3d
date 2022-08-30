/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:51:20 by baubigna          #+#    #+#             */
/*   Updated: 2022/08/30 13:55:46 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_check_scene(char *scene)
{
	if (ft_strlen(scene) < 5)
		return (1);
	if (scene[ft_strlen(scene) - 1] != 'b' || scene[ft_strlen(scene) - 2] != 'u' ||
		scene[ft_strlen(scene) - 3] != 'c' || scene[ft_strlen(scene) - 4] != '.')
		return (1);
	return (0);
}

void	ft_init_game(t_game *game)
{

}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		printf("Error\nThis program takes one argument\n");
		return (1);
	}
	if (ft_check_scene(av[1]))
	{
		printf("Error\nPlease provide a valid scene description file\n");
		return (1);
	}
	ft_init_game(game);
	return (0);
}
