# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niduches <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 16:00:17 by niduches          #+#    #+#              #
#    Updated: 2019/10/21 15:18:33 by niduches         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= 	gcc

SRC		=	ft_printf.c				\
			conv_char.c				\
			conv_hex.c				\
			conv_int.c				\
			conv_ptr.c				\
			conv_str.c				\
			conv_uhex.c				\
			conv_uint.c				\
			conv_nb_print_char.c	\
			conv_float.c			\
			ft_get_flags.c			\
			ft_isconv.c				\
			ft_isflag.c				\
			ft_makeconv.c			\
			ft_putnstr.c			\

OBJ		=	$(SRC:%.c=%.o)

#==============================================================================
CFLAGS	+=#	-Wall -Wextra -Werror
#==============================================================================

NAME	=	libftprintf.a

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

re:	fclean $(NAME)

.PHONY: all clean fclean re
