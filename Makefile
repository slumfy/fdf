# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 16:07:40 by rvalenti          #+#    #+#              #
#    Updated: 2019/02/08 08:30:26 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC =	main.c\
	parse_map.c\
	draw_map.c\

LIBFT = ./libft/
MINILIBX = ./minilibx_macos/
CC = gcc -Wall -Werror -Wextra
INCLUDES = ./
MINILIB = -I ./minilibx_macos -L ./minilibx_macos -lmlx -framework opengl -framework AppKit
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(MINILIBX)
	make -C $(LIBFT)
	$(CC) $(OBJ) -o$(NAME) -I$(LIBFT) -I$(INCLUDES) -L $(LIBFT) -lft $(MINILIB)
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
re:	fclean all
