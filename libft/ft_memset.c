/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:19:22 by hcherpre          #+#    #+#             */
/*   Updated: 2021/11/23 14:51:46 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t n)
{
	unsigned int	i;
	unsigned char	*save_p;

	save_p = (unsigned char *)pointer;
	i = 0;
	while (i < n)
	{
		save_p[i] = value;
		i++;
	}
	return (pointer);
}
