#include "../include/cub3D.h"

void	ft_draw_vertical_line(t_init *init)
{
	int	lineheight;

	lineheight = HEIGHT / (int)init->game->perpWallDist;
	printf("lineheight: %d\n", lineheight);
}
