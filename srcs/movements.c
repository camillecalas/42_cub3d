#include "../include/cub3D.h"

void	ft_move_forward(t_init *init, t_game *game)
{
	if (init->moves.move_f == 1)
	{
		if (init && init->map && init->map[(int)game->posY]
			&& init->map[(int)game->posY]
			[(int)(game->posX + game->dirX * game->moveSpeed * 2)]
			&& init->map[(int)game->posY]
			[(int)(game->posX + game->dirX * game->moveSpeed * 2)] == '0')
			game->posX += game->dirX * game->moveSpeed;
		if (init && init->map
			&& init->map[(int)(game->posY + game->dirY * game->moveSpeed * 2)]
			&& init->map[(int)(game->posY + game->dirY * game->moveSpeed * 2)]
			[(int)game->posX]
			&& init->map[(int)(game->posY + game->dirY * game->moveSpeed * 2)]
			[(int)game->posX] == '0')
			game->posY += game->dirY * game->moveSpeed;
	}
}

void	ft_move_backward(t_init *init, t_game *game)
{
	if (init->moves.move_b == 1)
	{
		if (init && init->map && init->map[(int)game->posY]
			&& init->map[(int)game->posY]
			[(int)(game->posX - game->dirX * game->moveSpeed * 2)]
			&& init->map[(int)game->posY]
			[(int)(game->posX - game->dirX * game->moveSpeed * 2)] == '0')
			game->posX -= game->dirX * game->moveSpeed;
		if (init && init->map
			&& init->map[(int)(game->posY - game->dirY * game->moveSpeed * 2)]
			&& init->map[(int)(game->posY - game->dirY * game->moveSpeed * 2)]
			[(int)game->posX]
			&& init->map[(int)(game->posY - game->dirY * game->moveSpeed * 2)]
			[(int)game->posX] == '0')
			game->posY -= game->dirY * game->moveSpeed;
	}
}

void	ft_move_right(t_init *init, t_game *game)
{
	if (init->moves.move_r == 1)
	{
		if (init && init->map && init->map[(int)game->posY]
			&& init->map[(int)game->posY]
			[(int)(game->posX + game->dirY * game->moveSpeed * 2)]
			&& init->map[(int)game->posY]
			[(int)(game->posX + game->dirY * game->moveSpeed * 2)] == '0')
			game->posX += game->dirY * game->moveSpeed;
		if (init && init->map
			&& init->map[(int)(game->posY - game->dirX * game->moveSpeed * 2)]
			&& init->map[(int)(game->posY - game->dirX * game->moveSpeed * 2)]
			[(int)game->posX]
			&& init->map[(int)(game->posY - game->dirX * game->moveSpeed * 2)]
			[(int)game->posX] == '0')
			game->posY -= game->dirX * game->moveSpeed;
	}
}

void	ft_move_left(t_init *init, t_game *game)
{
	if (init->moves.move_l == 1)
	{
		if (init && init->map && init->map[(int)game->posY]
			&& init->map[(int)game->posY]
			[(int)(game->posX - game->dirY * game->moveSpeed * 2)]
			&& init->map[(int)game->posY]
			[(int)(game->posX - game->dirY * game->moveSpeed * 2)] == '0')
			game->posX -= game->dirY * game->moveSpeed;
		if (init && init->map && init->map[(int)game->posX]
			&& init->map[(int)(game->posY + game->dirX * game->moveSpeed * 2)]
			[(int)game->posX]
			&& init->map[(int)(game->posY + game->dirX * game->moveSpeed * 2)]
			[(int)game->posX] == '0')
			game->posY += game->dirX * game->moveSpeed;
	}
}
