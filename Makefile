# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msorin <msorin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/08 13:07:13 by msorin            #+#    #+#              #
#    Updated: 2016/12/12 15:47:27 by msorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC		= algo_color.c \
		calc_pos.c \
		fdf.c \
		ft_fdfmap.c \
		get_img.c \
		get_map.c \
		get_win_and_norme.c \
		getter_fdf.c \
		init.c \
		main.c \
		rotate.c

OBJ		= $(SRC:.c=.o)

CMP		= clang

FLAGS	= -Wall -Wextra -Wmissing-prototypes -Werror

LIBH	= -I./libft -I./minilibx_macos -I./lib_h

LIBA	= -lft -L./libft -lmlx -L./minilibx_macos

OPTMLX	= -framework OpenGL -framework Appkit

DBG		= -O0 -g

all:		$(NAME)

$(NAME):	$(OBJ)
	@(cd libft && $(MAKE))
	@(cd minilibx_macos && $(MAKE))
	$(CMP) $(DBG) $(FLAGS) $(OPTMLX) $(LIBA) $(LIBH) $(OBJ) -o $(NAME)

%.o:		%.c
	@$(CMP) $(DBG) $(LIBH) -c $? $(FLAGS)

norme:
	norminette $(SRC)
	norminette lib_h/fdf.h lib_h/struct_fdf.h
	@(cd libft && $(MAKE) $@)

test: re
	./fdf ~/Desktop/maps/42.fdf
	./fdf ~/Desktop/maps/42.fdf 0.78
	./fdf ~/Desktop/maps/42.fdf -0.78
	./fdf ~/Desktop/maps/42.fdf 0 0.78
	./fdf ~/Desktop/maps/42.fdf 0 -0.78
	./fdf ~/Desktop/maps/42.fdf 0 0 0.78
	./fdf ~/Desktop/maps/42.fdf 0 0 -0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 -0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 -0.78
	./fdf ~/Desktop/maps/42.fdf 0 0.78 0.78
	./fdf ~/Desktop/maps/42.fdf 0 -0.78 0.78
	./fdf ~/Desktop/maps/42.fdf 0 0.78 -0.78
	./fdf ~/Desktop/maps/42.fdf 0 -0.78 -0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 0 0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 0 0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 0 -0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 0 -0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 0.78 0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 0.78 0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 -0.78 0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 0.78 -0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 -0.78 0.78
	./fdf ~/Desktop/maps/42.fdf 0.78 -0.78 -0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 0.78 -0.78
	./fdf ~/Desktop/maps/42.fdf -0.78 -0.78 -0.78

hard: re
	./fdf ~/Desktop/maps/elem-fract.fdf
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 0 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 0 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 -0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 0.78 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0 -0.78 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 0 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 0 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 0 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 0 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 -0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 0.78 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 -0.78 0.78
	./fdf ~/Desktop/maps/elem-fract.fdf 0.78 -0.78 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 0.78 -0.78
	./fdf ~/Desktop/maps/elem-fract.fdf -0.78 -0.78 -0.78

clean:
	@rm -f $(OBJ)
	@(cd libft && $(MAKE) $@)
	@(cd minilibx_macos && $(MAKE) $@)

fclean:		clean
	@rm -f $(NAME)
	@rm -rf fdf.dSYM
	@(cd libft && $(MAKE) $@)

re: fclean all

compile: re
	$(MAKE) fclean

.PHONY: all norme test hard clean fclean re compile
