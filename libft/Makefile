# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 11:46:58 by bkrasnos          #+#    #+#              #
#    Updated: 2022/06/23 12:07:33 by bkrasnos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDES = libft.h

SRC =	ft_printf.c\
		ft_flag_bx.c\
		ft_flag_c.c\
		ft_flag_d.c\
		ft_flag_i.c\
		ft_flag_p.c\
		ft_flag_perc.c\
		ft_flag_s.c\
		ft_flag_u.c\
		ft_flag_x.c\
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_free_tab.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_front.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstmap.c \
		ft_lstclear.c \
		ft_lstadd_back.c \
		ft_lstiter.c \
		get_next_line.c \
		get_next_line_utils.c

OBJ =	$(SRC:.c=.o)

%.o : %.c
			gcc $(FLAGS) -c $< -I $(INCLUDES) -o $@

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			# ranlib $(NAME)
	
clean:
			rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re