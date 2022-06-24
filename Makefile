# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 12:40:35 by bkrasnos          #+#    #+#              #
#    Updated: 2022/06/24 10:37:39 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -fsanitize=address -fno-omit-frame-pointer

NAME = push_swap

INCLUDES = -Iincludes -Ilibft/libft.h

LIB = libft/libft.a 

SRC =	src/push_swap.c \
		src/init.c \
		src/utils.c \
		src/init_utils.c \
		src/tools.c \
		src/five.c \
		src/ps.c \
		src/rr.c \
		src/main.c

OBJ =	$(SRC:.c=.o)

all:	libft $(NAME)

%.o : %.c
			gcc $(FLAGS) -c $< $(INCLUDES) -o $@

$(NAME):	$(OBJ)
			gcc $(FLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)

libft:
			make -C ./libft

clean:
			make -C libft clean
			rm -f $(OBJ)

fclean:		clean
			make -C libft fclean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean libft re