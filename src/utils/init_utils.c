/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:02:56 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/21 17:38:31 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/libft.h"
#include <stdlib.h>

t_map	*init_map(char **map_array)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = map_array;
	map->map_row_count = ft_strlen(map_array[0]);
	map->map_col_count = get_map_col_count(map_array);
	map->player_row = -1;
	map->player_col = -1;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	return (map);
}

t_graphics	*init_graphics(void)
{
	t_graphics	*graphics;

	graphics = malloc(sizeof(t_graphics));
	if (!graphics)
		return (NULL);
	graphics->mlx = NULL;
	graphics->mlx_win = NULL;
	graphics->wall_img = NULL;
	graphics->player_img = NULL;
	graphics->collectible_img = NULL;
	graphics->empty_img = NULL;
	graphics->exit_img = NULL;
	return (graphics);
}

t_game	*init_game(char **map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		safe_exit_with_error(NULL, map, "Error\nFailed to allocate memory for game");
	game->map = init_map(map);
	if (!game->map)
		safe_exit_with_error(game, map, "Error\nFailed to allocate memory for map");
	game->graphics = init_graphics();
	if (!game->graphics)
		safe_exit_with_error(game, NULL, "Error\nFailed to allocate memory for graphics");
	game->map->player = 0;
	return (game);
}
