/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:56:28 by hcherpre          #+#    #+#             */
/*   Updated: 2021/11/26 13:35:25 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int		i;
	unsigned char		*s1;
	unsigned char		*s2;

	i = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (i < n)
	{
		if (s1[i] > s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		else if (s1[i] < s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		else
			i++;
	}
	return (0);
}
