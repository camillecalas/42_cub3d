/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:32 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 16:13:48 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

void	ft_check_empty_line(char *line, t_init *init)
{
	if (line && ft_strlen(line) != 1)
	{
		if (line)
			free(line);
		ft_error("Error\nInvalid map informations\n", init);
	}
}

void	ft_open_map_file(char *filepath, t_init *init)
{
	char	*line;

	init->n = 0;
	ft_open_fd(filepath, init);
	line = get_next_line(init->fd);
	while (line)
	{
		init->n++;
		if (init->no && init->we && init->so && init->ea && init->f && init->c)
			break ;
		if (ft_strlen(line) == 1)
		{
			if (line)
				free(line);
			line = get_next_line(init->fd);
			continue ;
		}
		ft_get_map_info(line, init);
		if (line)
			free(line);
		line = get_next_line(init->fd);
	}
	ft_check_empty_line(line, init);
	if (line)
		free(line);
}

void	ft_free_col_param(char *line, char **elements, t_init *init)
{
	free(line);
	ft_free_split(elements);
	ft_error("Error\nInvalid color informations\n", init);
}

int	main(int ac, char **av)
{
	t_init	*init;

	init = NULL;
	if (ac != 2)
		ft_error("Error\nThis program takes one argument\n", init);
	if (ft_check_scene(av[1]))
		ft_error("Error\nPlease provide a valid scene description file\n", init);
	init = ft_calloc(1, sizeof(t_init));
	if (!init)
		ft_error("Error\nCould not allocate memory for init\n", init);
	ft_init_init(init);
	ft_open_map_file(av[1], init);
	if (init->no != 1 || init->we != 1 || init->so != 1 || init->ea != 1
		|| init->f != 1 || init->c != 1)
		ft_error("Error\nInvalid map informations\n", init);
	ft_cpy_map(init->fd, init, av[1]);
	ft_init_mlx(init);
	ft_clean_all(init);
	return (0);
}
