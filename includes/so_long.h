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
	int 	player_row;
	int 	player_col;
	int		exit;
	int		collectible;
} t_context;


char		**load_map_array(char* file_path);
char*		read_map_file(char* file_path);
char*		read_file_from_fd(int fd);
int			multiple_sequency_nl(char *str);

int			print_error(char *error);

int			is_valid_file_extension(char *file_path);
int			is_map_large_enough(t_context* context);
int			is_valid_tile(char c);
int			is_border_tile(int r, int c, t_context* context);

t_context*	initialize_map_context(char **map_array);
void		update_map_elements(t_context* map_context, char tile);
void		free_context(t_context* context);
int 		process_map_if_valid(t_context* map_context);
int	is_map_fully_accessible(t_context* context, int c, int r);

#endif
