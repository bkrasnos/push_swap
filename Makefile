# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 12:40:35 by bkrasnos          #+#    #+#              #
#    Updated: 2022/06/21 14:21:50 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS =	srcs/push_swap.c \
		srcs/init.c \
		srcs/utils.c \
		srcs/init_utils.c \
		srcs/tools.c \
		srcs/five.c \
		srcs/ps.c \
		srcs/rr.c \
		srcs/main.c \

OBJS	=	$(SRCS:.c=.o)

NAME_B	=	checker

SRCS_B	=	checker/checker.c		\
			checker/stdin.c		\
			checker/operations.c	\
			checker/arguments.c		\
			checker/utils_checker.c \

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
			rm -f $(OBJS) $(OBJS_B)
			make -C libft/ fclean

re:			fclean $(NAME)

.PHONY:		all clean fclean re