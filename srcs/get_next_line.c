/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:08 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 17:53:14 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

char	*ft_line(char *line_wip)
{
	char	*str;
	int		i;

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
	int		i;
	int		j;

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

char	*get_next_line(int fd, int close)
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
	if (close)
	{
		if (line_wip)
			free(line_wip);
		if (line)
			free(line);
	}
	return (line);
}
