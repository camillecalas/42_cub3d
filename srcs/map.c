#include "../include/cub3D.h"

void	ft_cpy_map(int fd, t_init *init, char *filepath, int n)
{
	char	*line;
	int		nb;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (ft_strlen(line) == 1)
		line = get_next_line(fd);
	nb = 0;
	while (line)
	{
		nb++;
		line = get_next_line(fd);
	}
	close(fd);
	init->map = ft_calloc(nb + 1, sizeof(char *));
	fd = open(filepath, O_RDONLY);
	while (n--)
		line = get_next_line(fd);
	line = get_next_line(fd);
	while (nb--)
	{
		init->map[i] = ft_strndup(line, 0, ft_strlen(line) - 1);
		i++;
		line = get_next_line(fd);
	}
}
