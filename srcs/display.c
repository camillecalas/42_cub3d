#include "../include/cub3D.h"

void	ft_which_texture(t_init *init, int side)
{
	if (!side && init->game->rayDirX < 0)
		init->t.dir = 0;
	else if (!side && init->game->rayDirX >= 0)
		init->t.dir = 1;
	else if (side && init->game->rayDirY < 0)
		init->t.dir = 2;
	else
		init->t.dir = 3;
	// if (!side)
	// 	init->t.wallX = init->game->posY + init->game->perpWallDist \
	// 	* init->game->rayDirY;
	// else
	// 	init->t.wallX = init->game->posX + init->game->perpWallDist \
	// 	* init->game->rayDirX;
	// init->t.wallX -= floor(init->t.wallX);
}

void	ft_draw_walls(t_init *init, int i, int j, int side, int linehigh)
{
	int	col;

	ft_which_texture(init, side);
	if (init->t.dir == 0)
		col = ft_color_convert(0, 255, 255);
	else if (init->t.dir == 1)
		col = ft_color_convert(255, 247, 0);
	else if (init->t.dir == 2)
		col = ft_color_convert(239, 20, 255);
	else if (init->t.dir == 3)
		col = ft_color_convert(0, 255, 247);
	while (j <= linehigh)
	{
		init->addr[j * init->size_line / 4 + i] = col;
		j++;
	}
	// init->text.step = init->textures[0].height / init->line;
	// init->text.x = init->text.wallX * (double)init->textures[init->text.dir].width;
	// if ((!side && init->game->rayDirX > 0) || (side && init->game->rayDirY < 0))
	// 	init->text.x = init->textures[init->text.dir].width - init->text.x - 1;
	// init->text.pos = (init->game->linelow - init->height / 2 + init->line / 2) * init->text.step;	
	// while (j <= init->game->linehigh)
	// {
	// 	init->text.y = init->text.pos & (init->textures[init->text.dir].height - 1);
	// 	init->text.pos += init->text.step;
	// 	if (j < init->height && i < init->width)
	// 		init->addr[j * init->size_line / 4 + i] =
	// 			init->textures[init->text.dir].address[init->text.y * init->size_line / 4 + init->text.x];
	// 	j++;
	// }
}

void	ft_draw_vertical_line(t_init *init, int i, int side)
{
	int	line;
	int	linelow;
	int	linehigh;
	int	j;

	line = init->height / fabs(init->game->perpWallDist);
	linelow = - line / 2 + init->height / 2;
	if (linelow < 0)
		linelow = 0;
	linehigh = line / 2 + init->height / 2;
	if (linehigh >= init->height)
		linehigh = init->height;
	j = 0;
	while (j < linelow)
	{
		init->addr[j * init->size_line / 4 + i] = init->ceiling_hexa;
		j++;
	}
	ft_draw_walls(init, i, j, side, linehigh);
	j = linehigh;
	while (j < init->height)
	{
		init->addr[j * init->size_line / 4 + i] = init->floor_hexa;
		j++;
	}
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
}
