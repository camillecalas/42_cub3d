/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:07:21 by baubigna          #+#    #+#             */
/*   Updated: 2022/08/30 15:29:30 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_texture
{
	void	*img;
}	t_texture;

typedef struct s_init
{
	int			no;
	int			so;
	int			we;
	int			ea;
	int			f;
	int			c;
	t_texture	textures[4];
}	t_init;

/* get_next_line.c */
void	free_ptr(char **ptr);
char	*join_line(int nl_pos, char **wip);
char	*read_line(int fd, char **wip, char *buf);
char	*get_next_line(int fd);

#endif
