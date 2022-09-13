#include "../include/cub3D.h"

int	ft_color_convert(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	ft_print_map(t_init *init)
{
	int	i;

	i = -1;
	while (init->map[++i])
		printf("map: %s\n", init->map[i]);
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
	ft_init_mlx(init);
	ft_clean_all(init);
	return (0);
}
