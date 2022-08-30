/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:45:06 by hcherpre          #+#    #+#             */
/*   Updated: 2022/06/24 17:59:03 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*final_str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	final_str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!final_str)
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s1))
	{
		final_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen((char *)s2))
	{
		final_str[i++] = s2[j++];
	}
	final_str[i] = '\0';
	return (final_str);
}

char	*ft_strjoin_char(char *s1, char c)
{
	char	*dest;
	int		i;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = c;
	i++;
	dest[i] = '\0';
	return (dest);
}
