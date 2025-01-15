/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:06:15 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/15 15:48:53 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_map_dims	get_map_dimensions(char** map)
{
	t_map_dims	map_dims;

	map_dims.rows = ft_strlen(map[0]);
	map_dims.cols = 0;

	while(map[map_dims.cols])
		map_dims.cols++;
	return map_dims;
}

int is_valid_char(char c)
{
	return (c == EMPTY || c == WALL || c == PLAYER || c == EXIT || c == COLLECTIBLE);
}
