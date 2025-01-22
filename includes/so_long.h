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
# define TILE_SIZE 64
# define ESC 65307

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

typedef struct s_map
{
	char	**map;
	int		map_row_count;
	int		map_col_count;
	int		player_row;
	int		player_col;
	int		player;
	int		exit;
	int		collectible;
}	t_map;

typedef struct s_graphics {
	void	*mlx;
	void	*mlx_win;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*empty_img;
	void	*exit_img;
}	t_graphics;

typedef struct s_game
{
	t_map		*map;
	t_graphics	*graphics;
	int			move_count;
}	t_game;

char		**load_map_array(char *file_path);
char		*read_map_file(char *file_path);
char		*read_file_from_fd(int fd);
int			has_sequential_newline(char *str);

int			print_error(char *error);
void		*print_error_null(char *error);
void		*free_with_error_null(char *error, void *ptr);
void		print_move_count(int count);
void		print_message(char *message);
int			is_valid_file_extension(char *file_path);
int			is_map_large_enough(t_map *map);
int			is_tile_type_valid(char c);
int			is_border_tile(int r, int c, t_map *map);
int			validate_required_elements(t_map *map);
int			validate_tile(t_map *map, int r, int c);

t_game		*init_game(char **map);
void		update_map_elements(t_map *map, char tile);
int			free_context(t_game *context);
int			process_map_if_valid(t_map *map);
int			is_map_elements_reachable(t_game *game);
void		set_player_position(t_map *map, int r, int c);
char		**duplicate_map(t_map *map);
void		free_map(t_map *map);
void		free_map_arr(char **map);
void		*get_image_by_tile(t_graphics *graphics, char tile);
int			initialize_graphics(t_game *game);
void		*load_image(t_graphics *graphics, char *path);
int			safe_exit_with_error(t_game *game, char **map, char *error);
void		safe_exit_with_message(t_game *game, char **map, char *message);
int			close_window(t_game *game);
int			get_map_col_count(char **map);
int			key_input_handler(int keycode, t_game *game);
void		render_map(t_game *game);
void		render_player(t_game *game);
int			is_collectible(t_game *game);

#endif
