/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:53:47 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/01 09:45:51 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	char			*string;
	unsigned char	k;

	k = (unsigned char) c;
	string = (char *)str;
	i = 0;
	while (string[i] != '\0' && k != string[i])
	{
		i++;
	}
	if (string[i] == k)
	{
		return (&string[i]);
	}
	return (NULL);
}
