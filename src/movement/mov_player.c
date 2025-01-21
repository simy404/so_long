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
#include "../../minilibx/mlx.h"
#include <stdio.h>

int	mov_player_if_valid(t_game *game, int new_col, int new_row)
{
	if (game->map->map[new_col][new_row] == WALL)
		return (0);
	set_player_position(game->map, new_row, new_col);
	return (1);
}
int	key_input_handler(int keycode, t_game *game)
{
	int is_mov;

	is_mov = 0;
	if (keycode == ESC)
		safe_exit_with_error(game, NULL, NULL);
	if (!(keycode == UP || keycode == DOWN || keycode == LEFT
			|| keycode == RIGHT))
		return (0);
	if (keycode == UP)
		is_mov = mov_player_if_valid(game, game->map->player_col - 1,
				game->map->player_row);
	else if (keycode == DOWN && game->map->map[game->map->player_col
		+ 1][game->map->player_row] != WALL)
		is_mov = mov_player_if_valid(game, game->map->player_col + 1,
				game->map->player_row);
	else if (keycode == LEFT
		&& game->map->map[game->map->player_col][game->map->player_row
		- 1] != WALL)
		is_mov = mov_player_if_valid(game, game->map->player_col,
				game->map->player_row - 1);
	else if (keycode == RIGHT
		&& game->map->map[game->map->player_col][game->map->player_row
		+ 1] != WALL)
		is_mov = mov_player_if_valid(game, game->map->player_col,
				game->map->player_row + 1);
	if (!is_mov)
		return (0);
	if (game->map->map[game->map->player_col][game->map->player_row] == COLLECTIBLE)
	{
		game->map->map[game->map->player_col][game->map->player_row] = EMPTY;
		game->map->collectible--;
	}
	// printf("Move:%d\n", game->move_count++);
	if (game->map->map[game->map->player_col][game->map->player_row] == EXIT
		&& game->map->collectible == 0)
		safe_exit_with_error(game, NULL, "You won!");
	render_map(game);
	render_player(game);
	return (0);
}
