/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:11:34 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 11:11:36 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 1

# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum	orientation
{
	NORTH,
	WEST,
	SOUTH,
	EAST
} t_orientation;

typedef enum movements
{
	MOVE_F = 119,
	MOVE_B = 115,
	MOVE_R = 100,
	MOVE_L = 97,
	CAMERA_R = 65363,
	CAMERA_L = 65361

} t_movements;

typedef struct s_texture
{
	t_orientation	orientation;
	int				width;
	int				height;
	int				*address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*path;
	void			*img;
}	t_texture;

typedef struct s_game
{
	int		linelow;
	int		linehigh;
	int		mapX;
	int		mapY;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	time;
	double	oldTime;
	double	frameTime;
	double	moveSpeed;
	double	rotSpeed;
}	t_game;

typedef struct s_t
{
	int		dir;
	int		x;
	int		y;
	double	wallX;
	double	step;
	double	pos;
}	t_t;

typedef struct s_moves
{
	int	move_f;
	int	move_b;
	int	move_l;
	int	move_r;
	int	camera_r;
	int	camera_l;
} t_moves;

typedef struct s_init
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			fd;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			n;
	int			width;
	int			height;
	int			floor_hexa;
	int			ceiling_hexa;
	int			line;
	char		**map;
	t_game		*game;
	t_moves		moves;
	t_texture	textures[4];
	t_t			t;
}	t_init;

/* check_param.c */
void	ft_check_direction(t_init *init);
int		ft_check_scene(char *scene);
void	ft_ignore_spaces_and_comma(char *line, size_t *i, t_init *init);
void	ft_check_color_parameters(char *line, t_init *init);
int		ft_check_color(char *line, size_t *i, t_init *init);

/* clean.c */
void	ft_free_split(char **split);
void	ft_close_int_fd(void);
void	ft_clean_more(t_init *init);
int		ft_clean_all(t_init *init);
void	ft_error(char *msg, t_init *init);

/* display.c */
void	ft_step_texture(t_init *init);
void	ft_texture_coord(t_init *init);
void	ft_which_texture(t_init *init, int side);
void	ft_draw_walls(t_init *init, int i, int j, int side);
void	ft_draw_vertical_line(t_init *init, int i, int side);

/* get_next_line_utils.c */
size_t	ft_strlen2(char *s);
char	*ft_strchr2(char *str, int c);
void	ft_cpy_join(char *dest, char *buff, size_t *i, size_t *j);
char	*ft_strjoin2(char *line_wip, char *buff);

/* get_next_line.c */
char	*ft_line(char *line_wip);
char	*ft_new_start(char	*line_wip);
char	*ft_read_fd(int fd, char *line_wip);
char	*get_next_line(int fd);

/* init.c */
void	ft_init_plane(t_init *init, char c);
void	ft_init_dir(t_init *init, char c);
void	ft_init_init(t_init *init);
void	ft_get_map_info(char *line, t_init *init);
void	ft_open_fd(char *filepath, t_init *init);

/* loop.c */
void	ft_step_and_sidedist(t_init *init, double *stepX, double *stepY);
void	ft_dda(t_init *init, int *side, double stepX, double stepY);
void	ft_perp_dist(t_init *init, int side, int stepx, int stepy);
void	ft_init_vectors(t_init *init, int i);
int		ft_game_loop(t_init *init);

/* main.c */
int		ft_color_convert(int r, int g, int b);
void	ft_open_map_file(char *filepath, t_init *init);
int		main(int ac, char **av);

/* map.c */
void	ft_check_map_col(t_init *init, int i, int j);
void	ft_check_close_map(t_init *init);
void	ft_check_map(t_init *init);
void	ft_cpy_map_lines(char *filepath, int fd, int nb, t_init *init);
void	ft_cpy_map(int fd, t_init *init, char *filepath);

/* mlx.c */
void	ft_get_textures_address(t_init *init);
void	ft_load_textures(t_init *init);
void	ft_init_mlx(t_init *init);

/* hooks.c */
void	ft_key_hook_moves(int keycode, t_init *init);
void	ft_key_hook_camera(int keycode, t_init *init);
int		ft_key_hook(int keycode, t_init *init);
int		ft_key_release(int keycode, t_init *init);

/* movements.c */
void	ft_init_moves(t_init *init);
void	ft_move_forward(t_init *init, t_game *game);
void	ft_move_backward(t_init *init, t_game *game);
void	ft_move_right(t_init *init, t_game *game);
void	ft_move_left(t_init *init, t_game *game);

/* camera_movements.c */
void	ft_move_camera_left(t_init *init, t_game *game, \
double prevplanex, double oldplanex);
void	ft_move_camera(t_init *init, t_game *game);

/* textures.c */
void	ft_check_authorised_char(t_init *init);
void	ft_check_map_line(t_init *init, int i, int j);
void	ft_orientation_id_cmp(char **elements, t_init *init);
void	ft_store_textures_paths(char **elements, t_init *init, char *path);
void	ft_check_texture_parameters(char **elements, t_init *init);


#endif
