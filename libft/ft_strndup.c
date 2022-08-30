/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:12:36 by hcherpre          #+#    #+#             */
/*   Updated: 2022/06/24 18:00:38 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t i, size_t len)
{
	size_t	j;
	char	*new;

	new = malloc(sizeof(char) * len + 2);
	if (!new)
		return (NULL);
	j = 0;
	while (j < len)
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
