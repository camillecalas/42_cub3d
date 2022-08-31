#include "../include/cub3D.h"

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

void	ft_get_map_info(char *line, t_init *init)
{
	char	**elements;

	elements = ft_split(line, " ");
	if (ft_strcmp("NO", elements[0]) && ft_strcmp("WE", elements[0]) && 
		ft_strcmp("SO", elements[0]) && ft_strcmp("EA", elements[0]) &&
		ft_strcmp("F", elements[0]) && ft_strcmp("C", elements[0]))
	{
		ft_putstr_fd("Error\nInvalid identifier\n", 2);
		ft_free_split(elements);
		exit(0);
	}
	if (!ft_strcmp("NO", elements[0]))
	{
		ft_check_texture_parameters(elements);
		init->no++;
	}
	else if (!ft_strcmp("SO", elements[0]))
	{
		ft_check_texture_parameters(elements);
		init->so++;
	}
	else if (!ft_strcmp("WE", elements[0]))
	{
		ft_check_texture_parameters(elements);
		init->we++;
	}
	else if (!ft_strcmp("EA", elements[0]))
	{
		ft_check_texture_parameters(elements);
		init->ea++;
	}
	else if (!ft_strcmp("C", elements[0]))
	{
		ft_check_color_parameters(line, init);
		init->c++;
	}
	else if (!ft_strcmp("F", elements[0]))
	{
		ft_check_color_parameters(line, init);
		init->f++;
	}
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
		if (ft_strlen(line) == 1)
		{
			line = get_next_line(fd);
			continue ;
		}
		ft_get_map_info(line, init);
		line = get_next_line(fd);
	}
	if (init->no != 1 || init->we != 1 || init->so != 1 || init->ea != 1 ||
		init->f != 1 || init->c != 1)
	{
		ft_putstr_fd("Error\nInvalid map informations\n", 2);
		exit(0);
	}
	// ft_cpy_map()
}
