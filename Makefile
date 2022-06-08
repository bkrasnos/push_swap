# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 12:40:35 by bkrasnos          #+#    #+#              #
#    Updated: 2022/06/06 15:38:44 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP =		push_swap
CHECKER =		checker
NAME =			$(PUSH_SWAP) $(CHECKER)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIB = ./libft/libft.a
LIB_PATH = ./libft
INCLUDES = -I libft get_next_line -I ./includes
SRC_PATH = ./srcs
OBJ_PATH = ./objs
SRC_CHECKER =	checker.c		\
				lst.c			\
				create_list.c	\
				push.c			\
				reverse_rotate.c\
				rotate.c		\
				swap.c			\
				utilities.c		\
						
SRC_PUSH_SWAP = push_swap.c		\
				solution.c		\
				fast_solution.c	\
				lst.c			\
				create_list.c	\
				push.c			\
				middle.c		\
				reverse_rotate.c\
				rotate.c		\
				swap.c			\
				utilities.c		\
							
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_CHECKER))

SRC2 = $(addprefix $(SRC_PATH)/, $(SRC_PUSH_SWAP))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_CHECKER))

OBJ2 = $(addprefix $(OBJ_PATH)/, $(OBJ_PUSH_SWAP))

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJ_CHECKER)
		@make -C $(LIB_PATH)
		@$(CC) $(CFLAGS) $(OBJ_CHECKER) $(INCLUDES) $(LIB) -o $(NAME)
		@echo "\x1b[36m[CHECKER COMPILED]\x1b[0m"

$(PUSH_SWAP): $(OBJ_PUSH_SWAP)
		@make -C $(LIB_PATH)
		@$(CC) $(CFLAGS) $(OBJ_PUSH_SWAP) $(INCLUDES) $(LIB) -o $(NAME)
		@echo "\x1b[36m[PUSH_SWAP COMPILED]\x1b[0m"
		
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
		@make clean -C $(LIB_PATH)
		@rm -rf $(OBJ_CHECKER)
		@rm -rf $(OBJ_PUSH_SWAP)
		@echo "\033[33mall $(NAME) and $(NAME2) .o files are removed\033[0m"

fclean: clean
		@make fclean -C $(LIB_PATH)
		@rm -f $(CHECKER) $(PUSH_SWAP)
		@echo "\033[31m$(CHECKER) and $(PUSH_SWAP) is deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re