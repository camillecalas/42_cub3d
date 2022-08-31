#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_texture
{
	void	*img;
}	t_texture;

typedef struct s_init
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	int			floor_hexa;
	int			ceiling_hexa;
	char		**map;
	t_texture	textures[4];
}	t_init;

/* check_param.c */
int		ft_check_scene(char *scene);
void	ft_check_texture_parameters(char **elements);
void	ft_ignore_spaces_and_comma(char *line, size_t *i);
void	ft_check_color_parameters(char *line, t_init *init);
int		ft_check_color(char *line, size_t *i);

/* clean.c */
void	ft_free_split(char **split);

/* get_next_line.c */
void	free_ptr(char **ptr);
char	*join_line(int nl_pos, char **wip);
char	*read_line(int fd, char **wip, char *buf);
char	*get_next_line(int fd);

/* init.c */
void	ft_init_init(t_init *init);
void	ft_get_map_info(char *line, t_init *init);
void	ft_open_map_file(char *filepath, t_init *init);

/* main.c */
int		ft_color_convert(int r, int g, int b);
int		main(int ac, char **av);

/* map.c */
void	ft_check_map(t_init *init);
void	ft_cpy_map(int fd, t_init *init, char *filepath, int n);

#endif
