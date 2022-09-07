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
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	mapX;
	double	mapY;
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
	int			width;
	int			height;
	int			floor_hexa;
	int			ceiling_hexa;
	char		**map;
	t_game		*game;
	t_texture	textures[4];
}	t_init;

/* check_param.c */
int		ft_check_scene(char *scene);
void	ft_check_texture_parameters(char **elements, t_init *init);
void	ft_ignore_spaces_and_comma(char *line, size_t *i, t_init *init);
void	ft_check_color_parameters(char *line, t_init *init);
int		ft_check_color(char *line, size_t *i, t_init *init);

/* clean.c */
void	ft_free_split(char **split);
int		ft_clean_all(t_init *init);
void	ft_error(char *msg, t_init *init);

/* display.c */
void	ft_draw_vertical_line(t_init *init, int i);

/* get_next_line.c */
void	free_ptr(char **ptr);
char	*join_line(int nl_pos, char **wip);
char	*read_line(int fd, char **wip, char *buf);
char	*get_next_line(int fd);

/* init.c */
void	ft_init_plane(t_init *init, char c);
void	ft_init_dir(t_init *init, char c);
void	ft_init_init(t_init *init);
void	ft_get_map_info(char *line, t_init *init);
void	ft_open_map_file(char *filepath, t_init *init);

/* loop.c */
int		ft_game_loop(t_init *init);

/* main.c */
int		ft_color_convert(int r, int g, int b);
void	ft_print_map(t_init *init);
int		main(int ac, char **av);

/* map.c */
void	ft_check_map(t_init *init);
void	ft_cpy_map(int fd, t_init *init, char *filepath, int n);

/* mlx.c */
void	ft_get_textures_address(t_init *init);
void	ft_load_textures(t_init *init);
int		ft_key_hook(int keycode, t_init *init);
void	ft_init_mlx(t_init *init);

#endif
