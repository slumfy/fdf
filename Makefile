# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 16:07:40 by rvalenti          #+#    #+#              #
#    Updated: 2019/01/29 16:23:05 by rvalenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF
SRC = main.c

LIBFT = ./libft/
CC = gcc -Wall -Werror -Wextra
INCLUDES = ./
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(OBJ) -o$(NAME) -I$(LIBFT) -I$(INCLUDES) -L $(LIBFT) -lft
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
re:	fclean all
