# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 16:20:54 by baubigna          #+#    #+#              #
#    Updated: 2022/08/31 14:12:09 by baubigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRCS	=	./srcs/check_param.c \
			./srcs/clean.c \
			./srcs/get_next_line.c \
			./srcs/init.c \
			./srcs/main.c

OBJS	=	${SRCS:.c=.o}
CC		=	clang
FLAGS	=	-Wall -Werror -Wextra

INCS	= -I ./includes -I ./libft/includes -I ./mlx
LIBC	= ./mlx/libmlx.a ./libft/libft.a
MLX_FLAGS	=	-L./mlx -lmlx -lX11 -lbsd -lXext -lm
MLX_USED = mlx

all:		${NAME}

.c.o:
			${CC} ${FLAGS} -Ofast ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			${MAKE} -C libft >/dev/null
			${MAKE} -C ${MLX_USED} >/dev/null
			${CC} ${FLAGS} ${INCS} ${MLX_FLAGS} -o ${NAME} ${OBJS} ${LIBC}

clean:		
			${MAKE} -C libft clean >/dev/null
			${MAKE} -C ${MLX_USED} clean >/dev/null
			rm -f ${OBJS} ${OBJS_BONUS}


fclean:		clean
			${MAKE} -C libft fclean >/dev/null
			rm -f ${NAME}

re:			fclean all

.PHONY:		all fclean clean all bonus