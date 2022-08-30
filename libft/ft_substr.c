/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:45:09 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/02 09:50:39 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*new_str;
	unsigned int		i;

	if (!s)
		return (NULL);
	if (ft_strlen((char *)s) < len)
		len = ft_strlen((char *)s);
	if (ft_strlen((char *)s) < start)
	{
		new_str = malloc(sizeof(char) * 1);
		if (!new_str)
			return (NULL);
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (start <= ft_strlen((char *)s) && i < len)
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
