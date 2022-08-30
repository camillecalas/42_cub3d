/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:00:05 by hcherpre          #+#    #+#             */
/*   Updated: 2021/11/26 14:28:15 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*save_dest;
	unsigned char	*save_src;

	save_dest = (unsigned char *) dest;
	save_src = (unsigned char *) src;
	if (!save_dest && !save_src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		save_dest[i] = save_src[i];
		i++;
	}
	return (dest);
}
