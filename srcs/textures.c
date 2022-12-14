/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:54 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 16:05:03 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_check_authorised_char(t_init *init)
{
	int	i;
	int	j;

	i = 0;
	while (init->map[i])
	{	
		j = 0;
		while (init->map[i][j])
		{
			if (init->map[i][j] != '1' && init->map[i][j] != '0'
				&& init->map[i][j] != ' ' && init->map[i][j] != '\n'
				&& init->map[i][j] != 'S' && init->map[i][j] != 'N'
				&& init->map[i][j] != 'W' && init->map[i][j] != 'E')
				ft_error("Error\nInvalid map\n", init);
			j++;
		}
		i++;
	}
}

void	ft_check_map_line(t_init *init, int i, int j)
{
	int	i2;

	i2 = i;
	if (init->map)
	{
		while (i2 >= 0 && init->map[i2] && init->map[i2][j]
			&& (init->map[i2][j] == '0' || ft_is_player(init->map[i2][j])))
			i2--;
		if (i2 < 0 || (init->map[i2] && !init->map[i2][j])
			|| (init->map[i2] && init->map[i2][j] && init->map[i2][j] != '1'))
			ft_error("Error\nMap not closed\n", init);
		i2 = i;
		while (init->map[i2] && init->map[i2][j] &&
			(init->map[i2][j] == '0' || ft_is_player(init->map[i2][j])))
			i2++;
		if (!init->map[i2] || (init->map[i2] && !init->map[i2][j])
			|| (init->map[i2] && init->map[i2][j] && init->map[i2][j] != '1'))
			ft_error("Error\nMap not closed\n", init);
	}
}

void	ft_orientation_id_cmp(char **elements, t_init *init, char *line)
{
	if (!ft_strcmp("NO", elements[0]))
	{
		ft_check_texture_parameters(elements, init, line);
		init->no++;
	}
	else if (!ft_strcmp("SO", elements[0]))
	{
		ft_check_texture_parameters(elements, init, line);
		init->so++;
	}
	else if (!ft_strcmp("WE", elements[0]))
	{
		ft_check_texture_parameters(elements, init, line);
		init->we++;
	}
	else if (!ft_strcmp("EA", elements[0]))
	{
		ft_check_texture_parameters(elements, init, line);
		init->ea++;
	}
}

void	ft_store_textures_paths(char **elements, t_init *init, char *path)
{
	if (!ft_strcmp(elements[0], "NO"))
	{
		init->textures[0].orientation = NORTH;
		if (!init->no)
			init->textures[0].path = ft_strdup(path);
	}
	if (!ft_strcmp(elements[0], "WE"))
	{
		init->textures[1].orientation = WEST;
		if (!init->we)
			init->textures[1].path = ft_strdup(path);
	}
	if (!ft_strcmp(elements[0], "SO"))
	{
		init->textures[2].orientation = SOUTH;
		if (!init->so)
			init->textures[2].path = ft_strdup(path);
	}
	if (!ft_strcmp(elements[0], "EA"))
	{
		init->textures[3].orientation = EAST;
		if (!init->ea)
			init->textures[3].path = ft_strdup(path);
	}
}

void	ft_check_texture_parameters(char **elements, t_init *init, char *line)
{
	char	*path;
	int		fd;

	path = NULL;
	if (elements[1])
		path = ft_strndup(elements[1], 0, ft_strlen(elements[1]) - 1);
	fd = open(path, O_RDONLY);
	if (!elements[1] || elements[2] || fd == -1)
	{
		ft_free_split(elements);
		free(path);
		free(line);
		ft_error("Error\nInvalid texture information\n", init);
	}
	close(fd);
	ft_store_textures_paths(elements, init, path);
	if (elements[1])
		free(path);
}
