/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:51:51 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/01 13:11:23 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*liste;

	liste = malloc(sizeof(t_list));
	if (!liste)
		return (NULL);
	liste->content = content;
	liste->next = NULL;
	return (liste);
}
