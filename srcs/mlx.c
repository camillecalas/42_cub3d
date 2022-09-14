#include "../include/cub3D.h"

void	ft_get_textures_address(t_init *init)
{
	init->textures[0].address = (int *)mlx_get_data_addr(init->textures[0].img,
			&init->textures[0].bits_per_pixel,
			&init->textures[0].size_line, &init->textures[0].endian);
	init->textures[1].address = (int *)mlx_get_data_addr(init->textures[1].img,
			&init->textures[1].bits_per_pixel,
			&init->textures[1].size_line, &init->textures[1].endian);
	init->textures[2].address = (int *)mlx_get_data_addr(init->textures[2].img,
			&init->textures[2].bits_per_pixel,
			&init->textures[2].size_line, &init->textures[2].endian);
	init->textures[3].address = (int *)mlx_get_data_addr(init->textures[3].img,
			&init->textures[3].bits_per_pixel,
			&init->textures[3].size_line, &init->textures[3].endian);
}

void	ft_load_textures(t_init *init)
{
	init->textures[0].img = mlx_xpm_file_to_image(init->mlx,
			init->textures[0].path, &(init->textures[0].width),
			&(init->textures[0].height));
	if (!init->textures[0].img)
		ft_error("Error\nCould not load NO texture\n", init);
	init->textures[1].img = mlx_xpm_file_to_image(init->mlx,
			init->textures[1].path, &(init->textures[1].width),
			&(init->textures[1].height));
	if (!init->textures[1].img)
		ft_error("Error\nCould not load WE texture\n", init);
	init->textures[2].img = mlx_xpm_file_to_image(init->mlx,
			init->textures[2].path, &(init->textures[2].width),
			&(init->textures[2].height));
	if (!init->textures[2].img)
		ft_error("Error\nCould not load SO texture\n", init);
	init->textures[3].img = mlx_xpm_file_to_image(init->mlx,
			init->textures[3].path, &(init->textures[3].width),
			&(init->textures[3].height));
	if (!init->textures[3].img)
		ft_error("Error\nCould not load EA texture\n", init);
	ft_get_textures_address(init);
}

void	ft_init_mlx(t_init *init)
{
	init->mlx = mlx_init();
	if (!init->mlx)
		ft_error("Error\nCould not initialize mlx\n", init);
	mlx_get_screen_size(init->mlx, &init->width, &init->height);
	ft_load_textures(init);
	init->img = mlx_new_image(init->mlx, init->width, init->height);
	init->addr = (int *)mlx_get_data_addr(init->img, &init->bits_per_pixel,
			&init->size_line, &init->endian);
	init->win = mlx_new_window(init->mlx, init->width, init->height, "cub3D");
	mlx_hook(init->win, 17, 0L, ft_clean_all, init);
	mlx_hook(init->win, 2, 1L << 0, ft_key_hook, init);
	mlx_loop_hook(init->mlx, ft_game_loop, init);
	mlx_hook(init->win, 3, 1L << 1, ft_key_release, init);
	mlx_loop(init->mlx);
}
