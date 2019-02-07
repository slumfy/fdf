# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 16:07:40 by rvalenti          #+#    #+#              #
#    Updated: 2019/02/07 22:52:11 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC =	main.c\
	parse_map.c\
	print_map.c\
	ft_list_pushback.c\
	ft_create_elem.c\
	bresenham.c\
	draw_map.c\
	key_hook.c\

LIBFT = ./libft/
CC = gcc -Wall -Werror -Wextra
INCLUDES = ./
MINILIB = -I ./minilibx_macos -L ./minilibx_macos -lmlx -framework opengl -framework AppKit
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) -o$(NAME) -I$(LIBFT) -I$(INCLUDES) -L $(LIBFT) -lft $(MINILIB)
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
re:	fclean all
