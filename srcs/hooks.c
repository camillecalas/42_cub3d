#include "../include/cub3D.h"

void	ft_key_hook_moves(int keycode, t_init *init)
{
	if (keycode == MOVE_F)
	{
		init->moves.move_f = 1;
		ft_move_forward(init, init->game);
	}
	else if (keycode == MOVE_B)
	{
		init->moves.move_b = 1;
		ft_move_backward(init, init->game);
	}
	else if (keycode == MOVE_R)
	{
		init->moves.move_r = 1;
		ft_move_right(init, init->game);
	}
	else if (keycode == MOVE_L)
	{
		init->moves.move_l = 1;
		ft_move_left(init, init->game);
	}
}

void	ft_key_hook_camera(int keycode, t_init *init)
{
	if (keycode == CAMERA_R)
	{
		init->moves.camera_r = 1;
		ft_move_camera(init, init->game);
		// ft_move_camera_right(init, init->game);
	}
	else if (keycode == CAMERA_L)
	{
		init->moves.camera_l = 1;
		ft_move_camera(init, init->game);
		// ft_move_camera_left(init, init->game);
	}
}

int	ft_key_hook(int keycode, t_init *init)
{
	if (keycode == 65307)
		ft_error("", init);
	ft_key_hook_moves(keycode, init);
	ft_key_hook_camera(keycode, init);
	return (0);
}

int	ft_key_release(int keycode, t_init *init)
{
	if (keycode == MOVE_F)
		init->moves.move_f = 0;
	else if (keycode == MOVE_B)
		init->moves.move_b = 0;
	else if (keycode == MOVE_R)
		init->moves.move_r = 0;
	else if (keycode == MOVE_L)
		init->moves.move_l = 0;
	else if (keycode == CAMERA_R)
		init->moves.camera_r = 0;
	else if (keycode == CAMERA_L)
		init->moves.camera_l = 0;
	return (0);
}