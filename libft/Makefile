# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:46:58 by bkrasnos          #+#    #+#              #
#    Updated: 2022/06/08 09:07:17 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

PATH_SRC = ./libc/

CFLAGS = -Wall -Wextra -Werror

INC = -I./includes

SRC	= ft_atoi.c									\
	  ft_bzero.c								\
	  ft_coincidence.c							\
	  ft_strcpy.c								\
	  ft_fill_tables.c							\
	  ft_is_space.c								\
	  ft_isalpha.c								\
	  ft_isdigit.c								\
	  ft_isalnum.c								\
	  ft_isascii.c								\
	  ft_isprint.c								\
	  ft_itoa.c									\
	  ft_memcpy.c								\
	  ft_memcpy_compare.c						\
	  ft_memmove.c								\
	  ft_memchr.c								\
	  ft_memcmp.c								\
	  ft_memalloc.c								\
	  ft_memdel.c								\
	  ft_putchar.c								\
	  ft_putstr.c								\
	  ft_putendl.c								\
	  ft_putnbr.c								\
	  ft_putchar_fd.c							\
	  ft_putstr_fd.c							\
	  ft_putendl_fd.c							\
	  ft_putnbr_fd.c 							\
	  ft_strlen.c								\
	  ft_strdup.c								\
	  ft_strncpy.c								\
	  ft_strcat.c								\
	  ft_strlcat.c								\
	  ft_strchr.c								\
	  ft_strrchr.c								\
	  ft_strstr.c								\
	  ft_strnstr.c								\
	  ft_strncmp.c								\
	  ft_strnew.c								\
	  ft_strdel.c								\
	  ft_strclear.c								\
	  ft_striter.c								\
	  ft_striteri.c								\
	  ft_strmap.c								\
	  ft_strmapi.c								\
	  ft_str_equal.c							\
	  ft_strn_equal.c							\
	  ft_substr.c								\
	  ft_strjoin.c								\
	  ft_strtrim.c								\
	  ft_split_str.c							\
	  ft_swap.c									\
	  ft_sqrt.c									\
	  ft_toupper.c								\
	  ft_tolower.c								\
	  get_next_line.c							\
	  ./ft_printf/ft_printf.c					\
	  ./ft_printf/ft_putcharr.c					\
	  ./ft_printf/ft_putstrr.c					\
	  ./ft_printf/ft_output_char.c				\
	  ./ft_printf/ft_output_string.c			\
	  ./ft_printf/ft_output_number.c			\
	  ./ft_printf/ft_output_number_unsigned.c	\
	  ./ft_printf/ft_output_hexadicimal.c		\
	  ./ft_printf/ft_output_hexadicimal_capital.c\
	  ./ft_printf/ft_output_pointer.c			\

OBJ = $(SRC:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\x1b[36m[LIBFT COMPILED]\x1b[0m"

%.o: %.c
	@echo "\x1b[32mSources compiling...\x1b[0m"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@echo "\x1b[33mall libft .o files are removed\x1b[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\x1b[31m$(NAME) is deleted\x1b[0m"

re: fclean all

.PHONY: all clean fclean re