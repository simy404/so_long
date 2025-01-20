/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:22:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 06:58:31 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/so_long.h"

int	process_map_if_valid(t_map *map)
{
	int	r;
	int	c;
	if (!is_map_large_enough(map))
		return (print_error("Error\nMap width or height is too small"));
	c = 0;
	while (map->map[c])
	{
		r = 0;
		while (map->map[c][r])
		{
			if (!validate_tile(map, r, c))
				return (0);
			update_map_elements(map, map->map[c][r]);
			if (map->map[c][r] == PLAYER)
				set_player_position(map, r, c);
			r++;
		}
		if (map->map_row_count != r)
			return (print_error("Error\nMap is not rectangular"));
		c++;
	}
	return (validate_required_elements(map));
}

void	dfs_map_search(char **map, int *elements, int c, int r)
{
	if (map[c][r] == WALL || *elements == 0)
		return ;
	*elements -= map[c][r] == COLLECTIBLE || map[c][r] == EXIT;
	map[c][r] = WALL;
	dfs_map_search(map, elements, c, r + 1);
	dfs_map_search(map, elements, c, r - 1);
	dfs_map_search(map, elements, c + 1, r);
	dfs_map_search(map, elements, c - 1, r);
}

int	is_map_elements_reachable(t_game *game)
{
	char	**map_arr;
	int		elements;

	elements = game->map->collectible + game->map->exit;
	map_arr = duplicate_map(game->map);
	if (!map_arr)
		safe_exit_with_error(game, NULL, "Error\nMemory allocation failed");
	dfs_map_search(map_arr, &elements, game->map->player_col, game->map->player_row);
	free_map_arr(map_arr);
	if (elements != 0)
		return (print_error("Error\nMap elements are not reachable"));
	return (1);
}
