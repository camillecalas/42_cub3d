#include "../include/cub3D.h"

void	ft_move_forward(t_init *init, t_game *game)
{
	if (init->moves.move_f == 1)
	{
		if (init->map[(int)(game->posX + (game->rayDirX * game->moveSpeed * 2))]
			[(int)game->posY] == '0')
			game->posX = game->
	}
	if (init->map[(int)game->posX]
		[(int)(game->posX + (game->rayDirY * game->moveSpeed * 2)) == '0'])
		printf("OLA\n");
}