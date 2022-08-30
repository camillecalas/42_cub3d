/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:56:56 by hcherpre          #+#    #+#             */
/*   Updated: 2021/11/26 12:29:07 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	char				*s1;
	char				*s2;
	unsigned int		i;

	s1 = (char *)str1;
	s2 = (char *)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (i != n && (s1[i] || s2[i]))
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
