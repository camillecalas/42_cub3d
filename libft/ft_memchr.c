/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:34:09 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/01 09:45:32 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char			*mem;
	unsigned int			i;
	unsigned char			k;

	k = (unsigned char) c;
	mem = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (mem[i] == k)
			return (&mem[i]);
		else
			i++;
	}
	return (NULL);
}
