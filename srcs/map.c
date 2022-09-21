/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:36 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 15:09:52 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_check_map_col(t_init *init, int i, int j)
{
	int	j2;

	j2 = j;
	while (j2 >= 0 && init->map[i][j2] != '1'
		&& init->map[i][j2] != ' ')
		j2--;
	if (j2 < 0 || init->map[i][j2] == ' ')
		ft_error("Error\nMap not closed\n", init);
	j2 = j;
	while (init->map[i][j2] && init->map[i][j2] != '1'
		&& init->map[i][j2] != ' ')
		j2++;
	if ((size_t)j2 == ft_strlen(init->map[i])
		|| init->map[i][j2] == ' ')
		ft_error("Error\nMap not closed\n", init);
}

void	ft_check_close_map(t_init *init)
{
	int	i;
	int	j;

	i = -1;
	while (init->map[++i])
	{	
		j = -1;
		while (init->map[i][++j])
		{
			if (init->map[i][j] == '0' || init->map[i][j] == 'S'
				|| init->map[i][j] == 'N' || init->map[i][j] == 'W'
				|| init->map[i][j] == 'E')
			{
				ft_check_map_line(init, i, j);
				ft_check_map_col(init, i, j);
			}
		}
	}
}

void	ft_check_map(t_init *init)
{
	ft_check_direction(init);
	ft_check_authorised_char(init);
	ft_check_close_map(init);
}

void	ft_cpy_map_lines(char *filepath, int fd, int nb, t_init *init)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	fd = open(filepath, O_RDONLY);
	while (init->n--)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	line = get_next_line(fd);
	while (nb--)
	{
		if (line)
			init->map[i] = ft_strndup(line, 0, ft_strlen(line));
		i++;
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
}

void	ft_cpy_map(int fd, t_init *init, char *filepath)
{
	char	*line;
	int		nb;
	int		i;

	i = 0;
	line = NULL;
	nb = 0;
	while (1)
	{
		if (line)
			free(line);
		nb++;
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	if (!nb)
	{
		free(line);
		ft_error("Error\nNo map provided\n", init);
	}
	close(fd);
	init->map = ft_calloc(nb + 1, sizeof(char *));
	ft_cpy_map_lines(filepath, fd, nb, init);
	ft_check_map(init);
}
