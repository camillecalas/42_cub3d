#include "../include/cub3D.h"

int	ft_color_convert(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
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
	while (*init->map)
		printf("%s\n", *init->map++);
	ft_game_loop(init);
	return (0);
}
