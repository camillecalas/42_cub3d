#include "../include/cub3D.h"

void	ft_draw_vertical_line(t_init *init, int i)
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
		init->addr[j * init->size_line / 4 + i] = init->floor_hexa;
		j++;
	}
	j = linehigh;
	while (j < init->height)
	{
		init->addr[j * init->size_line / 4 + i] = init->ceiling_hexa;
		j++;
	}
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
}
