/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:24:59 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 01:55:12 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define BUFFER_SIZE 42
#define TILE_SIZE 32
#define ESC 65307

typedef enum e_direction
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100
}	t_direction;

typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C'
}	t_tile;

typedef struct s_context
{
	char**	map;
	int		map_rows;
	int		map_cols;
	int		player;
	int		exit;
	int		collectible;
} t_context;

int			is_valid_file_extension(char *file_path);

char		**load_map_array(char* file_path);
char*		read_map_file(char* file_path);

int			print_error(char *error);

char*		read_file_from_fd(int fd);

int			is_map_valid(char **map);

t_context	get_map_dimensions(char** map);

int 		process_map_if_valid(t_context* map_context);
t_context*	initialize_map_context(char **map_array);
int is_valid_char(char c);
#endif
