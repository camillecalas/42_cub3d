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

void	ft_check_texture_parameters(char **elements)
{
	char	*path;

	if (elements[1])
		path = ft_strndup(elements[1], 0, ft_strlen(elements[1]) - 1);
	if (!elements[1] || elements[2] || open(path, O_RDONLY) == -1)
	{
		ft_putstr_fd("Error\nInvalid texture information\n", 2);
		ft_free_split(elements);
		free(path);
		exit(0);
	}
	free(path);
}

void	ft_ignore_spaces_and_comma(char *line, size_t *i)
{
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] != ',')
	{
		ft_putstr_fd("Error\nInvalid color informations\n", 2);
		exit(0);
	}
	(*i)++;
	while (line[*i] == ' ')
		(*i)++;
}

void	ft_check_color_parameters(char *line, t_init *init)
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
		r = ft_check_color(line, &i);
		ft_ignore_spaces_and_comma(line, &i);
		g = ft_check_color(line, &i);
		ft_ignore_spaces_and_comma(line, &i);
		b = ft_check_color(line, &i);
		if (line[i] != '\n')
		{
			ft_putstr_fd("Error\nInvalid color informations\n", 2);
			exit(0);
		}
		else
			break ;
	}
	if (line[0] == 'C')
		init->ceiling_hexa = ft_color_convert(r, g, b);
	else
		init->floor_hexa = ft_color_convert(r, g, b);
}

int	ft_check_color(char *line, size_t *i)
{
	int	c;

	c = 0;
	if (line[*i] < 48 || line[*i] > 57)
	{
		ft_putstr_fd("Error\nInvalid color informations\n", 2);
		exit(0);
	}
	while (line[*i] > 47 && line[*i] < 58)
	{
		c = c * 10 + line[*i] - 48;
			(*i)++;
	}
	if (c < 0 || c > 255)
	{
		ft_putstr_fd("Error\nInvalid color informations\n", 2);
		exit(0);
	}
	return (c);
}
