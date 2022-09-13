#include "../include/cub3D.h"

void	ft_init_plane(t_init *init, char c)
{
	if (c == 'N')
	{
		init->game->planeX = 1;
		init->game->planeY = 0;
	}
	else if (c == 'W')
	{
		init->game->planeX = 0;
		init->game->planeY = -1;
	}
	else if (c == 'S')
	{
		init->game->planeX = -1;
		init->game->planeY = 0;
	}
	else if (c == 'E')
	{
		init->game->planeX = 0;
		init->game->planeY = 1;
	}
}

void	ft_init_dir(t_init *init, char c)
{
	if (c == 'N')
	{
		init->game->dirX = 0;
		init->game->dirY = -1;
	}
	else if (c == 'W')
	{
		init->game->dirX = -1;
		init->game->dirY = 0;
	}
	else if (c == 'S')
	{
		init->game->dirX = 0;
		init->game->dirY = 1;
	}
	else if (c == 'E')
	{
		init->game->dirX = 1;
		init->game->dirY = 0;
	}
}

void	ft_init_init(t_init *init)
{
	init->no = 0;
	init->so = 0;
	init->we = 0;
	init->ea = 0;
	init->f = 0;
	init->c = 0;
	init->fd = -1;
	init->textures[0].img = NULL;
	init->textures[1].img = NULL;
	init->textures[2].img = NULL;
	init->textures[3].img = NULL;
	init->img = NULL;
	init->win = NULL;
	init->game = ft_calloc(1, sizeof(t_game));
	if (!init->game)
		ft_error("Error\nMemory for init->game could not be allocated\n", init);
	init->game->time = 0;
	init->game->oldTime = 0;
}

void	ft_get_map_info(char *line, t_init *init)
{
	char	**elements;

	elements = ft_split(line, " ");
	if (ft_strcmp("NO", elements[0]) && ft_strcmp("WE", elements[0])
		&& ft_strcmp("SO", elements[0]) && ft_strcmp("EA", elements[0])
		&& ft_strcmp("F", elements[0]) && ft_strcmp("C", elements[0]))
	{
		ft_free_split(elements);
		ft_error("Error\nInvalid identifier\n", init);
	}
	if (!ft_strcmp("NO", elements[0]))
	{
		ft_check_texture_parameters(elements, init);
		init->no++;
	}
	else if (!ft_strcmp("SO", elements[0]))
	{
		ft_check_texture_parameters(elements, init);
		init->so++;
	}
	else if (!ft_strcmp("WE", elements[0]))
	{
		ft_check_texture_parameters(elements, init);
		init->we++;
	}
	else if (!ft_strcmp("EA", elements[0]))
	{
		ft_check_texture_parameters(elements, init);
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
	int		n;
	char	*line;

	n = 0;
	init->fd = open(filepath, O_DIRECTORY);
	if (init->fd != -1)
		ft_error("Error\nMap cannot be a directory\n", init);
	init->fd = open(filepath, O_RDONLY);
	if (init->fd == -1)
		ft_error("Error\nInvalid map file\n", init);
	line = get_next_line(init->fd);
	while (line)
	{
		n++;
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
	if (line)
		free(line);
	if (init->no != 1 || init->we != 1 || init->so != 1 || init->ea != 1
		|| init->f != 1 || init->c != 1)
		ft_error("Error\nInvalid map informations\n", init);
	ft_cpy_map(init->fd, init, filepath, n);
}
