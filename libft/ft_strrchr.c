/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:40:26 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/01 09:45:55 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	char			*string;
	unsigned char	k;

	k = (unsigned char) c;
	i = 0;
	string = (char *)str;
	while (string[i])
		i++;
	while (i >= 0)
	{
		if (string[i] == k)
			return (&string[i]);
		else
			i--;
	}
	return (NULL);
}
