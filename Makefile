# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 13:55:10 by hsamir            #+#    #+#              #
#    Updated: 2025/01/13 23:34:06 by hsamir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c \
src/utils/print_utils.c \
src/map/map_loader.c \
src/map/map_validator.c \
src/utils/read_utils.c \

CC = gcc
CFLAGS = -g
LIBFT = libft/libft.a

MINILBX = minilibx/libmlx.a
MLXFLAG = -lXext -lX11 -lm
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILBX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MINILBX) $(MLXFLAG)

$(LIBFT):
	make -C libft

$(MINILBX):
	make -C minilibx
clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
