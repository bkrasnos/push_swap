# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 12:40:35 by bkrasnos          #+#    #+#              #
#    Updated: 2022/06/23 11:03:07 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

INCLUDES = -Iincludes -Ilibft/libft.h

LIB = libft/libft.a 

SRC =	push_swap.c \
		init.c \
		utils.c \
		init_utils.c \
		tools.c \
		five.c \
		ps.c \
		rr.c \
		main.c

OBJ =	$(SRC:.c=.o)

all:	libft $(NAME)

%.o : %.c
			gcc $(FLAGS) -c $< $(INCLUDES) -o $@

$(NAME):	${OBJ}
			gcc $(FLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)

libft:
			make -C ./libft

clean:
			make -C libft clean
			rm -f ${OBJ}

fclean:		clean
			make -C libft fclean
			rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean libft re