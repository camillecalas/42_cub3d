/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:26:56 by baubigna          #+#    #+#             */
/*   Updated: 2022/05/18 15:27:23 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i + 1], charset) == 1
			&& is_sep(str[i], charset) == 0)
			word++;
		i++;
	}
	return (word);
}

void	write_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (is_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	word_size(char **tab, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_sep(str[i + j], charset) == 0)
				j++;
			tab[word] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(tab[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		word_count;

	word_count = count_word(str, charset);
	tab = (char **)malloc(sizeof(char *) * (word_count + 1));
	tab[word_count] = 0;
	word_size(tab, str, charset);
	return (tab);
}
