/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:51:20 by baubigna          #+#    #+#             */
/*   Updated: 2022/08/30 18:07:41 by baubigna         ###   ########.fr       */
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
	init->textures[0].img = NULL;
	init->textures[1].img = NULL;
	init->textures[2].img = NULL;
	init->textures[3].img = NULL;
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

void	ft_get_map_info(char *line, t_init *init)
{
	char	**elements;

	elements = ft_split(line, " ");
	if (ft_strcmp("NO", elements[0]) && ft_strcmp("WE", elements[0]) && 
		ft_strcmp("SO", elements[0]) && ft_strcmp("EA", elements[0]) &&
		ft_strcmp("F", elements[0]) && ft_strcmp("C", elements[0]))
	{
		ft_putstr_fd("Error\nInvalid map informations\n", 2);
		ft_free_split(elements);
		exit(0);
	}
	if (!ft_strcmp("NO", elements[0]))
		init->no = 1;
	ft_free_split(elements);
}

void	ft_open_map_file(char *filepath, t_init *init)
{
	int		fd;
	char	*line;

	fd = open(filepath, O_DIRECTORY);
	if (fd != -1)
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
		if (init->no && init->we && init->so && init->ea && init->f && init->c)
			break ;
		if (!ft_strlen(line))
			continue ;
		ft_get_map_info(line, init);
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
	init = ft_calloc(1, sizeof(t_init));
	if (!init)
		return (1);
	ft_init_init(init);
	ft_open_map_file(av[1], init);
	return (0);
}
