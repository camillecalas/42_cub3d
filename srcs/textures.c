#include "../include/cub3D.h"

void	ft_store_textures_paths(char **elements, t_init *init, char *path)
{
	if (!ft_strcmp(elements[0], "NO"))
	{
		init->textures[0].orientation = NORTH;
		init->textures[0].path = ft_strdup(path);
	}
	if (!ft_strcmp(elements[0], "WE"))
	{
		init->textures[1].orientation = WEST;
		init->textures[1].path = ft_strdup(path);
	}
	if (!ft_strcmp(elements[0], "SO"))
	{
		init->textures[2].orientation = SOUTH;
		init->textures[2].path = ft_strdup(path);
	}
	if (!ft_strcmp(elements[0], "EA"))
	{
		init->textures[3].orientation = EAST;
		init->textures[3].path = ft_strdup(path);
	}
}

void	ft_check_texture_parameters(char **elements, t_init *init)
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
		ft_error("Error\nInvalid texture information\n", init);
	}
	close(fd);
	ft_store_textures_paths(elements, init, path);
	if (elements[1])
		free(path);
}
