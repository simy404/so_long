/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/01/13 14:42:16 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 01:55:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/libft.h"
#include "../../minilibx/mlx.h"

int	mov_player_if_valid(t_game *game, int new_col, int new_row)
{
	if (game->map->map[new_col][new_row] == WALL)
		return (0);
	set_player_position(game->map, new_row, new_col);
	return (1);
}

int	process_key(int keycode, t_game *game)
{
	int	new_row;
	int	new_col;

	new_row = game->map->player_row;
	new_col = game->map->player_col;
	if (keycode == UP)
		new_col--;
	else if (keycode == DOWN)
		new_col++;
	else if (keycode == LEFT)
		new_row--;
	else if (keycode == RIGHT)
		new_row++;
	else
		return (0);
	return (mov_player_if_valid(game, new_col, new_row));
}

int	key_input_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		safe_exit_with_message(game, NULL, "You exited the game!");
	if (!process_key(keycode, game))
		return (0);
	if (is_collectible(game))
	{
		game->map->map[game->map->player_col][game->map->player_row] = EMPTY;
		game->map->collectible--;
	}
	print_move_count(game->move_count++);
	if (game->map->map[game->map->player_col][game->map->player_row] == EXIT
		&& game->map->collectible == 0)
		safe_exit_with_message(game, NULL, "You won!");
	render_map(game);
	render_player(game);
	return (0);
}
