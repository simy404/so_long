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
src/map/map_rules.c \
src/utils/file_utils.c \
src/utils/map_utils.c \
src/utils/free_utils.c \
src/utils/init_utils.c \
src/graphics/gfx.c \
src/utils/graphics_utils.c \
src/movement/mov_player.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
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
