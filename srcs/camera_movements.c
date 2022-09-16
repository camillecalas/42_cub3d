#include "../include/cub3D.h"

void	ft_move_camera(t_init *init, t_game *game)
{
	double	prevPlaneX;
	double	prevDirX;
	double oldPlaneX;

	prevPlaneX = game->planeX;
	prevDirX = game->dirX;
	if (init->moves.camera_r == 1)
	{
		game->dirX = game->dirX * cos(-(game->rotSpeed / 2)) - game->dirY * sin(-(game->rotSpeed) / 2);
		game->dirY = prevDirX * sin(-(game->rotSpeed / 2)) + game->dirY * cos(-(game->rotSpeed) / 2);
		game->planeX = game->planeX * cos(-(game->rotSpeed) / 2) - game->planeY * sin(-(game->rotSpeed) / 2);
		game->planeY = prevPlaneX * sin(-(game->rotSpeed) / 2) + game->planeY * cos(-(game->rotSpeed / 2));
	}
	if (init->moves.camera_l == 1)
	{
		prevDirX = game->dirX;
		oldPlaneX = game->planeX;
		game->dirX = game->dirX * cos(game->rotSpeed / 2) - game->dirY * sin(game->rotSpeed / 2);
		game->dirY = prevDirX * sin(game->rotSpeed / 2) + game->dirY * cos(game->rotSpeed / 2);
		game->planeX = game->planeX * cos(game->rotSpeed / 2) - game->planeY * sin(game->rotSpeed / 2);
		game->planeY = oldPlaneX * sin(game->rotSpeed / 2) + game->planeY * cos(game->rotSpeed / 2);
	}
}

void	ft_move_camera_right(t_init *init, t_game *game)
{
	double	prevPlanX;
	double	prevDirX;

	prevPlanX = game->planeX;
	prevDirX = game->dirX;
	if (init->moves.camera_r == 1)
	{
		game->dirX = game->dirX * cos(-(game->rotSpeed / 2)) - game->dirY * sin(-(game->rotSpeed) / 2);
		game->dirY = prevDirX * sin(-(game->rotSpeed / 2)) + game->dirY * cos(-(game->rotSpeed) / 2);
		game->planeX = game->planeX * cos(-(game->rotSpeed) / 2) - game->planeY * sin(-(game->rotSpeed) / 2);
		game->planeY = prevPlanX * sin(-(game->rotSpeed) / 2) + game->planeY * cos(-(game->rotSpeed / 2));
	}
}


void	ft_move_camera_left(t_init *init, t_game *game)
{
	double	prevPlanX;
	double	prevDirX;

	if (init->moves.camera_l == 1)
	{
		prevPlanX = game->planeX;
		prevDirX = game->dirX;
		game->dirX = game->dirX * cos(game->rotSpeed / 2) - game->dirY * sin(game->rotSpeed) / 2;
		game->dirY = prevDirX * sin(game->rotSpeed / 2) + game->dirY * cos(game->rotSpeed) / 2;
		game->planeX = game->planeX * cos(game->rotSpeed / 2) - game->planeY * sin(game->rotSpeed) / 2;
		game->planeY = prevPlanX * sin(game->rotSpeed / 2) + game->planeY * cos(game->rotSpeed / 2);
	}
}



// void	ft_rotate_right_left(t_recup *recup)
// {
// 	double oldplanx;
// 	double olddirx;

// 	oldplanx = recup->ray.planx;
// 	olddirx = recup->ray.dirx;
// 	if (recup->data.rotate_right == 1)
// 	{
// 		recup->ray.dirx = recup->ray.dirx * cos(-recup->ray.rotspeed / 2) -
// 			recup->ray.diry * sin(-recup->ray.rotspeed / 2);
// 		recup->ray.diry = olddirx * sin(-recup->ray.rotspeed / 2) +
// 			recup->ray.diry * cos(-recup->ray.rotspeed / 2);
// 		recup->ray.planx = recup->ray.planx * cos(-recup->ray.rotspeed / 2)
// 			- recup->ray.plany * sin(-recup->ray.rotspeed / 2);
// 		recup->ray.plany = oldplanx * sin(-recup->ray.rotspeed / 2) +
// 			recup->ray.plany * cos(-recup->ray.rotspeed / 2);
// 	}
// 	ft_rotate_left(recup, olddirx);
// }
// void	ft_rotate_left(t_recup *recup, double olddirx)
// {
// 	double oldplanex;

// 	if (recup->data.rotate_left == 1)
// 	{
// 		olddirx = recup->ray.dirx;
// 		oldplanex = recup->ray.planx;
// 		recup->ray.dirx = recup->ray.dirx * cos(recup->ray.rotspeed / 2) -
// 			recup->ray.diry * sin(recup->ray.rotspeed / 2);
// 		recup->ray.diry = olddirx * sin(recup->ray.rotspeed / 2) + recup->
// 			ray.diry * cos(recup->ray.rotspeed / 2);
// 		recup->ray.planx = recup->ray.planx * cos(recup->ray.rotspeed / 2) -
// 			recup->ray.plany * sin(recup->ray.rotspeed / 2);
// 		recup->ray.plany = oldplanex * sin(recup->ray.rotspeed / 2) +
// 			recup->ray.plany * cos(recup->ray.rotspeed / 2);
// 	}
// }
