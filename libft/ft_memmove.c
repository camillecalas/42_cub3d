/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:42:54 by hcherpre          #+#    #+#             */
/*   Updated: 2021/11/26 14:34:05 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*save_dest;
	unsigned char	*save_src;

	save_dest = (unsigned char *)dest;
	save_src = (unsigned char *)src;
	if (!save_dest && !src)
		return (0);
	i = 0;
	if (save_src < save_dest)
	{
		while (len--)
		{
			save_dest[len] = save_src[len];
		}
	}
	else
	{
		while (i < len)
		{
			save_dest[i] = save_src[i];
			i++;
		}
	}
	return (save_dest);
}
