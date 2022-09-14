#include "../include/cub3D.h"

void	ft_move_forward(t_init *init, t_game *game)
{
	if (init->moves.move_f == 1)
	{
		printf("PosX = %f\n", game->posX);
		printf("RayDirX = %f\n", game->rayDirX); 
		printf("Movespeed = %f\n", game->moveSpeed); 
		printf("1ere condition = [%d][%d]\n", (int)(game->posX + game->rayDirX * game->moveSpeed * 2), (int)game->posY);
		printf("2eme condition [%d][%d]\n", (int)game->posX, (int)(game->posY + game->rayDirY * game->moveSpeed * 2));
		if (init->map[(int)(game->posX + game->rayDirX * game->moveSpeed * 2)]
			[(int)game->posY] == '0')
		{
			printf("ICI\n");
			game->posX += game->rayDirX * game->moveSpeed;
		}
		if (init->map[(int)game->posX]
			[(int)(game->posY + game->rayDirY * game->moveSpeed * 2)] == '0')
		{
			printf("LA\n");
			game->posY += game->rayDirY * game->moveSpeed;
		}
	}
}
	// 	if (recup->data.forward == 1)
	// {
	// 	if (recup->map[(int)(recup->ray.posx + (recup->ray.dirx * recup->
	// 					ray.movespeed * 2))][(int)recup->ray.posy] == '0')
	// 		recup->ray.posx += recup->ray.dirx * recup->ray.movespeed;
	// 	if (recup->map[(int)(recup->ray.posx)][(int)(recup->ray.posy +
	// 				(recup->ray.diry * recup->ray.movespeed * 2))] == '0')
	// 		recup->ray.posy += recup->ray.diry * recup->ray.movespeed;
	// }

