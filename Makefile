# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 12:40:35 by bkrasnos          #+#    #+#              #
#    Updated: 2022/06/23 12:26:46 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FLAGS = -Wall -Wextra -Werror

# NAME = push_swap

# INCLUDES = -Iincludes -Ilibft/libft.h

# LIB = libft/libft.a 

# SRC =	push_swap.c \
# 		init.c \
# 		utils.c \
# 		init_utils.c \
# 		tools.c \
# 		five.c \
# 		ps.c \
# 		rr.c \
# 		main.c

# OBJ =	$(SRC:.c=.o)

# all:	libft $(NAME)

# %.o : %.c
# 			gcc $(FLAGS) -c $< $(INCLUDES) -o $@

# $(NAME):	${OBJ}
# 			gcc $(FLAGS) $(OBJ) $(LIB) $(INCLUDES) -o $(NAME)

# libft:
# 			make -C ./libft

# clean:
# 			make -C libft clean
# 			rm -f $(OBJ)

# fclean:		clean
# 			make -C libft fclean
# 			rm -f $(NAME)

# re:			fclean all

# .PHONY: all clean fclean libft re

NAME	=	push_swap

SRCS	=		push_swap.c \
				init.c \
				utils.c \
				init_utils.c \
				tools.c \
				five.c \
				ps.c \
				rr.c \
				main.c

OBJS	=	$(SRCS:.c=.o)

NAME_B	=	checker

SRCS_B	=	checker/arguments.c \
			checker/checker.c \
			checker/operations.c \
			checker/stdin.c \
			checker/utils_checker 

OBJS_B	=	$(SRCS_B:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/
			$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

bonus:		$(OBJS_B)
			make -C libft/ bonus
			$(CC) $(CFLAGS) $(OBJS_B) -Llibft -lft -o $(NAME_B)

clean:
			rm -rf $(OBJS)
			make -C libft/ clean

fclean:
			rm -rf $(OBJS_B) $(OBJS)
			make -C libft/ fclean

re:			fclean $(NAME)

.PHONY:		all clean fclean re