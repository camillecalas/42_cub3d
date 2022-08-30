/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:44:31 by hcherpre          #+#    #+#             */
/*   Updated: 2021/11/30 14:17:23 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_convert(char *tab, unsigned int n, long int len)
{
	while (n > 0)
	{
		tab[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char			*tab;
	int				len;
	unsigned int	nb;

	len = get_len(n);
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len--] = '\0';
	if (n == 0)
		tab[0] = '0';
	if (n < 0)
	{
		nb = n * -1;
		tab[0] = '-';
	}
	else
		nb = n;
	tab = ft_convert(tab, nb, len);
	return (tab);
}
