/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:06:15 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/22 08:32:05 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/libft.h"
#include <stdlib.h>

int	get_map_col_count(char **map)
{
	int	cols;

	cols = 0;
	while (map[cols])
		cols++;
	return (cols);
}

void	update_map_elements(t_map *map, char tile)
{
	if (tile == PLAYER)
		map->player++;
	else if (tile == EXIT)
		map->exit++;
	else if (tile == COLLECTIBLE)
		map->collectible++;
}

int	is_collectible(t_game *game)
{
	return (game->map->map[game->map->player_col][game->map->player_row]
		== COLLECTIBLE);
}

void	set_player_position(t_map *map, int r, int c)
{
	map->player_col = c;
	map->player_row = r;
}

char	**duplicate_map(t_map *map)
{
	char	**map_arr;
	int		i;

	map_arr = malloc((map->map_col_count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (map->map[i])
	{
		map_arr[i] = ft_strdup(map->map[i]);
		if (!map_arr[i])
		{
			free_map_arr(map_arr);
			return (NULL);
		}
		i++;
	}
	map_arr[i] = NULL;
	return (map_arr);
}
