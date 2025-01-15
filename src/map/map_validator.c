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
#include "stdio.h"

int	is_map_valid(char **map)
{
	t_map_dims	map_dims;

	map_dims = get_map_dimensions(map);
	if (!is_map_rectangle(map, map_dims) || !is_map_large_enough(map_dims) ||
	!contains_only_valid_chars(map, map_dims) || !is_map_surrounded_by_walls(map, map_dims))
		return (0);
	return (1);
}

int	is_map_rectangle(char **map, t_map_dims dims)
{
	int	i;

	i = 1;
	while (map[i])
		if (dims.rows != ft_strlen(map[i++]))
			return (0);
	return (1);
}

int	is_map_large_enough(t_map_dims dims)
{
	return (!(dims.cols < 3 || dims.rows < 3));
}

int	contains_only_valid_chars(char **map,  t_map_dims dims)
{
	int	r;
	int	c;

	c = 0;
	while (c < dims.cols)
	{
		r = 0;
		while(r < dims.rows)
			if (!is_valid_char(map[c][r++]))
				return (0);
		c++;
	}
	return (1);
}

int	is_map_surrounded_by_walls(char **map, t_map_dims dims)
{
	int	i;

	i = 0;
	while (i < dims.rows)
	{
		if (map[0][i] != WALL || map[dims.cols -1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < dims.rows)
	{
		if (map[i][0] != WALL || map[i][dims.rows - 1] != WALL)
				return (0);
		i++;
	}
	return (1);
}
