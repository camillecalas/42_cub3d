/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:12:07 by baubigna          #+#    #+#             */
/*   Updated: 2022/08/30 15:12:40 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_ptr(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*join_line(int nl_pos, char **wip)
{
	char	*ret;
	char	*temp;

	temp = NULL;
	if (nl_pos < 1)
	{
		if (**wip == '\0')
		{
			free(*wip);
			*wip = NULL;
			return (NULL);
		}
		ret = *wip;
		*wip = NULL;
		return (ret);
	}
	temp = ft_substr(*wip, nl_pos, BUFFER_SIZE);
	ret = *wip;
	ret[nl_pos] = '\0' ;
	*wip = temp;
	return (ret);
}

char	*read_line(int fd, char **wip, char *buf)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*nl;

	nl = ft_strchr(*wip, '\n');
	temp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 1)
			return (join_line(bytes_read, wip));
		buf[bytes_read] = '\0';
		temp = ft_strjoin(*wip, buf);
		free_ptr(wip);
		*wip = temp;
		nl = ft_strchr(*wip, '\n');
	}
	return (join_line(nl - *wip + 1, wip));
}

char	*get_next_line(int fd)
{
	static char	*wip[12288 + 1];
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 12288)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!wip[fd])
		wip[fd] = ft_strdup("");
	line = read_line(fd, &wip[fd], buf);
	free_ptr(&buf);
	return (line);
}
