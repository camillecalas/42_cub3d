/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:11:47 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 14:34:46 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_check_direction(t_init *init)
{
	int	nswe;
	int	i;
	int	j;

	nswe = 0;
	i = -1;
	while (init->map[++i])
	{	
		j = 0;
		while (init->map[i][j])
		{
			if (init->map[i][j] == 'S' || init->map[i][j] == 'N'
				|| init->map[i][j] == 'W' || init->map[i][j] == 'E')
			{
				init->game->posX = j;
				init->game->posY = i;
				ft_init_dir(init, init->map[i][j]);
				ft_init_plane(init, init->map[i][j]);
				nswe++;
			}
			j++;
		}
	}
	if (nswe != 1)
		ft_error("Error\nInvalid map\n", init);
}

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

void	ft_ignore_spaces_and_comma(char *line, size_t *i, t_init *init, \
char **elements)
{
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] != ',')
	{
		free(line);
		ft_free_split(elements);
		ft_error("Error\nInvalid color informations\n", init);
	}
	(*i)++;
	while (line[*i] == ' ')
		(*i)++;
}

void	ft_check_color_parameters(char *line, t_init *init, char **elements)
{
	size_t	i;
	int		r;
	int		g;
	int		b;

	i = 1;
	while (i < ft_strlen(line))
	{
		while (line[i] == ' ')
			i++;
		r = ft_check_color(line, &i, init, elements);
		ft_ignore_spaces_and_comma(line, &i, init, elements);
		g = ft_check_color(line, &i, init, elements);
		ft_ignore_spaces_and_comma(line, &i, init, elements);
		b = ft_check_color(line, &i, init, elements);
		if (line[i] != '\n' && line[i] != '\0')
		{
			free(line);
			ft_free_split(elements);
			ft_error("Error\nInvalid color informations\n", init);
		}
		else
			break ;
	}
	if (line[0] == 'C')
		init->ceiling_hexa = ft_color_convert(r, g, b);
	else
		init->floor_hexa = ft_color_convert(r, g, b);
}

int	ft_check_color(char *line, size_t *i, t_init *init, char **elements)
{
	int	c;

	c = 0;
	if (line[*i] < 48 || line[*i] > 57)
	{
		free(line);
		ft_free_split(elements);
		ft_error("Error\nInvalid color informations\n", init);
	}
	while (line[*i] > 47 && line[*i] < 58)
	{
		c = c * 10 + line[*i] - 48;
			(*i)++;
	}
	if (c < 0 || c > 255)
	{
		free(line);
		ft_free_split(elements);
		ft_error("Error\nInvalid color informations\n", init);
	}
	return (c);
}
