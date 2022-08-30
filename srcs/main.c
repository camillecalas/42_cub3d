/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:51:20 by baubigna          #+#    #+#             */
/*   Updated: 2022/08/30 15:29:58 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_check_scene(char *scene)
{
	if (ft_strlen(scene) < 5)
		return (1);
	if (scene[ft_strlen(scene) - 1] != 'b'
		|| scene[ft_strlen(scene) - 2] != 'u'
		|| scene[ft_strlen(scene) - 3] != 'c'
		|| scene[ft_strlen(scene) - 4] != '.')
		return (1);
	return (0);
}

void	ft_init_init(t_init *init)
{
	init->no = 0;
	init->so = 0;
	init->we = 0;
	init->ea = 0;
	init->f = 0;
	init->c = 0;
	init->texture[0].img = NULL;
	init->texture[1].img = NULL;
	init->texture[2].img = NULL;
	init->texture[3].img = NULL;
}

void	ft_open_map_file(char *filepath)
{
	int		fd;
	char	*line;

	fd = open(filepath, O_DIRECTORY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nMap cannot be a directory\n", 2);
		exit(0);
	}
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nInvalid map file\n", 2);
		exit(0);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strlen(line))
			continue ;
		if (line[0] == 'N' && ft_load_north_texture(line))
		{
			ft_putstr_fd("Error\nInvalid NO texture\n", 2);
			exit(0);
		}
		line = get_next_line(fd);
	}
}

int	main(int ac, char **av)
{
	t_init	*init;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nThis program takes one argument\n", 2);
		return (1);
	}
	if (ft_check_scene(av[1]))
	{
		ft_putstr_fd("Error\nPlease provide a valid scene description file\n", 2);
		return (1);
	}
	ft_init_init(init);
	ft_open_map_file(av[1]);
	return (0);
}
