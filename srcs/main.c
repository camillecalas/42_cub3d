#include "../include/cub3D.h"

int	ft_color_convert(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	ft_get_textures_address(t_init *init)
{
	init->textures[0].address = (int *)mlx_get_data_addr(init->textures[0].img,
			&init->textures[0].bits_per_pixel,
			&init->textures[0].size_line, &init->textures[0].endian);
}

void	ft_load_images(t_init *init)
{
	if (!(init->textures[0].img = mlx_xpm_file_to_image(init->mlx, init->textures[0].path,
		&(init->textures[0].width), &(init->textures[0].height))))
		ft_error("Error\nCould not load NO texture\n", init);
	if (!(init->textures[1].img = mlx_xpm_file_to_image(init->mlx, init->textures[1].path,
		&(init->textures[1].width), &(init->textures[1].height))))
		ft_error("Error\nCould not load WE texture\n", init);
	if (!(init->textures[2].img = mlx_xpm_file_to_image(init->mlx, init->textures[2].path,
		&(init->textures[2].width), &(init->textures[2].height))))
		ft_error("Error\nCould not load SO texture\n", init);
	if (!(init->textures[3].img = mlx_xpm_file_to_image(init->mlx, init->textures[3].path,
		&(init->textures[3].width), &(init->textures[3].height))))
		ft_error("Error\nCould not load EA texture\n", init);
	ft_get_textures_address(init);
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
	init->mlx = mlx_init();
	if (!init->mlx)
		ft_error("Error\nCould not initialize mlx\n", init);
	init->win = mlx_new_window(init->mlx, WIDTH, HEIGHT, "cub3D");
	ft_open_map_file(av[1], init);
	ft_load_images(init);
	ft_game_loop(init);
	ft_clean_all(init);
	return (0);
}
