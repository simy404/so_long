/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:42:16 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 01:55:57 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../minilibx/mlx.h"
#include <stdio.h>
int movement(int keycode, t_game *game)
{
	printf("Keycode: %d\n", keycode);
	if (keycode == ESC)
		safe_exit_with_error(game, NULL, NULL);
	if (keycode == UP)
	{
		if (game->map->map[game->map->player_col - 1][game->map->player_row] == WALL)
			return (0);
		else if (game->map->map[game->map->player_col - 1][game->map->player_row] == COLLECTIBLE)
			game->map->collectible--;
		else if (game->map->map[game->map->player_col - 1][game->map->player_row] == EXIT && game->map->collectible == 0)
			game->map->exit--;

		mlx_put_image_to_window(game->graphics->mlx, game->graphics->mlx_win, game->graphics->player_img,  (game->map->player_row) * TILE_SIZE, (game->map->player_col -1 )  * TILE_SIZE);
		game->map->map[game->map->player_col - 1][game->map->player_row] = PLAYER;
		game->map->map[game->map->player_col][game->map->player_row] = EMPTY;
		game->map->player_col--;
		printf("Player moved up\n");
	}
	else if (keycode == DOWN)
	{

	}
	else if (keycode == LEFT)
	{

	}
	else if (keycode == RIGHT)
	{

	}
	return (0);
}
