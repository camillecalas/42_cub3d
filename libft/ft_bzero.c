/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:49:49 by hcherpre          #+#    #+#             */
/*   Updated: 2022/08/29 15:06:03 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer, size_t n)
{
	unsigned int	i;
	unsigned char	*save_p;

	save_p = (unsigned char *) pointer;
	i = 0;
	while (i < n)
	{
		save_p[i] = '\0';
		i++;
	}
}
