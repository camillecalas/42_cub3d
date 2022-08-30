/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:05:10 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/01 09:46:03 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *s1, size_t n)
{
	int					i;
	size_t				temp;
	char				*src;

	src = (char *)s1;
	temp = ft_strlen(dst);
	i = 0;
	if (n <= ft_strlen(dst))
		return (n + ft_strlen(src));
	while (src[i] && temp + 1 < n)
	{
		dst[temp] = src[i];
		i++;
		temp++;
	}
	dst[temp] = '\0';
	return (temp + ft_strlen(&src[i]));
}
