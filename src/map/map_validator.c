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
#include <stdlib.h>

int	process_map_if_valid(t_context* context)
{
	int	r;
	int	c;

	if (!is_map_large_enough(context))
		return (print_error("Error\nMap width or height is too small"));
	c = 0;
	while (context->map[c])
	{
		r = 0;
		while (context->map[c][r])
		{
			if (!validate_tile(context, r, c))
				return (0);
			update_map_elements(context, context->map[c][r]);
			if (context->map[c][r] == PLAYER)
				set_player_position(context, r, c);
			r++;
		}
		if (context->map_row_count != r)
			return (print_error("Error\nMap is not rectangular"));
		c++;
	}
	return (validate_required_elements(context));
}

void	dfs_map_search(char** map, int* elements, int c, int r)
{
	if (map[c][r] == WALL || *elements == 0)
		return ;
	(*elements) -= map[c][r] == COLLECTIBLE || map[c][r] == EXIT;
	map[c][r]= WALL;
	dfs_map_search(map, elements, c, r + 1);
	dfs_map_search(map, elements, c, r - 1);
	dfs_map_search(map, elements, c + 1, r);
	dfs_map_search(map, elements, c - 1, r);
}

int	is_map_elements_reachable(t_context* context)
{
	char	**map;
	int 	elements;

	elements = context->collectible + context->exit;
	map = duplicate_map(context);
	if (!map)
		return (print_error("Error\nFailed to duplicate map"));
	dfs_map_search(map, &elements, context->player_col, context->player_row);
	free_map(map);
	if (elements != 0)
		return (print_error("Error\nMap is not fully accessible"));
	return (1);
}
