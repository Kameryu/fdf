# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msorin <msorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/20 11:29:26 by msorin            #+#    #+#              #
#    Updated: 2016/12/03 12:44:06 by msorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_abs.c \
		ft_atof.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_error.c \
		ft_memalloc.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_minmax.c \
		ft_reallinttab.c \
		ft_round.c \
		ft_signe.c \
		ft_strchr.c \
		ft_strclen.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strnew.c \
		ft_strnjoinf.c \
		ft_strsplit.c \
		ft_strsub.c \
		ft_tdoublemap.c \
		get_next_line.c

OBJ		= $(SRC:.c=.o)

CMP		= clang

FLAGS	= -Wall -Wextra -O0 -g -Wmissing-prototypes -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:		%.c
	@$(CMP) -I. -c $? $(FLAGS)

norme:
	norminette $(SRC)
	norminette libft.h

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all

compile: re
	$(MAKE) fclean

.PHONY: clean fclean re compile
