/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/13 14:24:59 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 01:55:12 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42
# define TILE_SIZE 60
# define ESC 65307

typedef enum e_direction
{
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100
} t_direction;

typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C'
} t_tile;

typedef struct s_context
{
	char **map;
	int map_row_count;
	int map_col_count;
	int player_row;
	int player_col;
	int player;
	int exit;
	int collectible;
} t_context;

char	**load_map_array(char *file_path);
char	*read_map_file(char *file_path);
char	*read_file_from_fd(int fd);
int	has_sequential_newline(char *str);

int	print_error(char *error);
void	*print_error_null(char *error);

int	is_valid_file_extension(char *file_path);
int	is_map_large_enough(t_context *context);
int	is_tile_type_valid(char c);
int	is_border_tile(int r, int c, t_context *context);
int	validate_required_elements(t_context *context);
int	validate_tile(t_context *context, int r, int c);

t_context	*init_map_context(char **map_array);
void	update_map_elements(t_context *map_context, char tile);
int	free_context(t_context *context);
int	process_map_if_valid(t_context *map_context);
int	is_map_elements_reachable(t_context *context);
void	set_player_position(t_context *context, int r, int c);
char	**duplicate_map(t_context *context);
void	free_map(char **map);

#endif
