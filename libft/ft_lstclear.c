/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:37:53 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/01 17:29:22 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*next;

	if (!del)
		return ;
	if (lst)
	{
		temp = *lst;
		while (temp)
		{
			next = temp->next;
			ft_lstdelone(temp, del);
			temp = next;
		}
		*lst = NULL;
	}
}
