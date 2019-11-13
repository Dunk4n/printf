# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niduches <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 16:00:17 by niduches          #+#    #+#              #
#    Updated: 2019/10/26 12:23:09 by niduches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

SRC_PATH	=	ft_printf.c				\
				conv_char.c				\
				conv_hex.c				\
				conv_int.c				\
				conv_ptr.c				\
				conv_str.c				\
				conv_uhex.c				\
				conv_uint.c				\
				conv_nb_print_char.c	\
				conv_float.c			\
				conv_sct.c				\
				ft_get_flags.c			\
				ft_isconv.c				\
				ft_isflag.c				\
				ft_makeconv.c			\
				ft_putnstr.c			\
				ft_put_long_nbr.c		\

SRC = $(addprefix src/,$(SRC_PATH))

OBJ		=	$(SRC:%.c=%.o)

CFLAGS	+= -Wall -Wextra -Werror -I./include

NAME	=	libftprintf.a

BUILD_DIR	=	build

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

re:	fclean $(NAME)

.PHONY: all clean fclean re
