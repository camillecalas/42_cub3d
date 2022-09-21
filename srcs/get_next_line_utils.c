/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:12:04 by baubigna          #+#    #+#             */
/*   Updated: 2022/09/21 11:12:05 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_cpy_join(char *dest, char *buff, size_t *i, size_t *j)
{
	while (buff[(*j)] != '\0')
	{
		dest[(*i)] = buff[(*j)];
		(*i)++;
		(*j)++;
	}
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
	ft_cpy_join(dest, buff, &i, &j);
	dest[ft_strlen2(line_wip) + ft_strlen2(buff)] = '\0';
	free (line_wip);
	return (dest);
}
