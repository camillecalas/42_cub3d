/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:20:48 by hcherpre          #+#    #+#             */
/*   Updated: 2021/11/26 12:11:27 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *find, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	char			*to_find;

	str = (char *)string;
	to_find = (char *)find;
	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && (i + j < len))
		{
			if (to_find[j + 1] == '\0')
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
