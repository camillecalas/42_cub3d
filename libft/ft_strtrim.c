/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:54:25 by hcherpre          #+#    #+#             */
/*   Updated: 2022/05/16 15:06:11 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_start(char const *s1, char const *set)
{
	int		i;

	i = 0;
	while (*s1 && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set)
{
	int		i;

	i = ft_strlen((char *)s1);
	while (*s1 && ft_strchr(set, s1[i - 1]))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*new;
	int		start;
	int		end;

	if (!set || !s1)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	new = malloc(sizeof(*s1) * (end - start + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start < end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
