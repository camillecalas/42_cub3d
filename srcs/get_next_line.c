#include "../include/cub3D.h"

size_t	ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr2(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char) c)
			return ((char *) str);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin2(char *line_wip, char *buff)
{
	char		*dest;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;

	if (!line_wip)
	{
		line_wip = malloc(sizeof(char) * 1);
		line_wip[0] = '\0';
	}
	if (!line_wip || !buff)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen2(line_wip) + ft_strlen2(buff) + 1));
	if (!dest)
		return (NULL);
	while (line_wip[i] != '\0')
	{
		dest[i] = line_wip[i];
		i++;
	}
	while (buff[j] != '\0')
	{
		dest[i] = buff[j];
		i++;
		j++;
	}
	dest[ft_strlen2(line_wip) + ft_strlen2(buff)] = '\0';
	free (line_wip);
	return (dest);
}

char	*ft_line(char *line_wip)
{
	char	*str;
	int			i;

	i = 0;
	if (line_wip[i] == '\0')
		return (NULL);
	while (line_wip[i] && line_wip[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line_wip[i] && line_wip[i] != '\n')
	{
		str[i] = line_wip[i];
		i++;
	}
	if (line_wip[i] == '\n')
	{
		str[i] = line_wip[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_start(char	*line_wip)
{
	char	*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line_wip[i] && line_wip[i] != '\n')
		i++;
	if (line_wip[i] == '\0')
	{
		free(line_wip);
		return (NULL);
	}	
	str = malloc(sizeof(char) * (ft_strlen2(line_wip) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (line_wip[i])
		str[j++] = line_wip[i++];
	str[j] = '\0';
	free(line_wip);
	return (str);
}

char	*ft_read_fd(int fd, char *line_wip)
{
	char	*buff;
	int		bits;

	bits = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr2(line_wip, '\n') && bits > 0)
	{
		bits = read(fd, buff, BUFFER_SIZE);
		if (bits == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[bits] = '\0';
		line_wip = ft_strjoin2(line_wip, buff);
	}
	free (buff);
	return (line_wip);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_wip;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_wip = ft_read_fd(fd, line_wip);
	if (!line_wip)
		return (NULL);
	line = ft_line(line_wip);
	line_wip = ft_new_start(line_wip);
	return (line);
}