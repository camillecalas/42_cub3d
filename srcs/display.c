#include "../include/cub3D.h"

void	ft_step_texture(t_init *init)
{
	if (init->t.dir == 0)
		init->t.step = 1.0 * init->textures[0].height / init->line;
	else if (init->t.dir == 1)
		init->t.step = 1.0 * init->textures[1].height / init->line;
	if (init->t.dir == 2)
		init->t.step = 1.0 * init->textures[2].height / init->line;
	else
		init->t.step = 1.0 * init->textures[3].height / init->line;
	init->t.pos = init->game->linelow - init->height / 2 + init->line / 2 * init->t.step;
}

void	ft_texture_coord(t_init *init)
{
	if (init->t.dir == 0)
		init->t.x = (int)(init->t.wallX * (double)init->textures[0].width);
	else if (init->t.dir == 1)
	{
		init->t.x = (int)(init->t.wallX * (double)init->textures[1].width);
		init->t.x = init->textures[1].width - init->t.x - 1;
	}
	if (init->t.dir == 2)
	{
		init->t.x = (int)(init->t.wallX * (double)init->textures[2].width);
		init->t.x = init->textures[2].width - init->t.x - 1;
	}
	else
		init->t.x = (int)(init->t.wallX * (double)init->textures[3].width);
	ft_step_texture(init);
}

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
	if (!side)
		init->t.wallX = init->game->posY + init->game->perpWallDist \
		* init->game->rayDirY;
	else
		init->t.wallX = init->game->posX + init->game->perpWallDist \
		* init->game->rayDirX;
	init->t.wallX -= floor(init->t.wallX);
	ft_texture_coord(init);
}

void	ft_draw_walls(t_init *init, int i, int j, int side)
{
	ft_which_texture(init, side);
	while (j <= init->game->linehigh)
	{
		init->t.y = (int)init->t.pos & (init->textures[init->t.dir].height - 1);
		init->t.pos += init->t.step;
		if (j < init->height && i < init->width)
			init->addr[j * init->size_line / 4 + i] =
				init->textures[init->t.dir].address[init->t.y * init->textures[init->t.dir].size_line / 4 + init->t.x];
		j++;
	}
}

void	ft_draw_vertical_line(t_init *init, int i, int side)
{
	int	j;

	init->line = init->height / fabs(init->game->perpWallDist);
	init->game->linelow = - init->line / 2 + init->height / 2;
	if (init->game->linelow < 0)
		init->game->linelow = 0;
	init->game->linehigh = init->line / 2 + init->height / 2;
	if (init->game->linehigh >= init->height)
		init->game->linehigh = init->height;
	j = 0;
	while (j < init->game->linelow)
	{
		init->addr[j * init->size_line / 4 + i] = init->ceiling_hexa;
		j++;
	}
	ft_draw_walls(init, i, j, side);
	j = init->game->linehigh;
	while (j < init->height)
	{
		init->addr[j * init->size_line / 4 + i] = init->floor_hexa;
		j++;
	}
}
