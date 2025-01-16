/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:06:15 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/16 16:49:36 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/libft.h"
#include <stdlib.h>

int	get_map_column(char** map)
{
	int cols = 0;

	while(map[cols])
		cols++;
	return cols;
}

int	is_valid_char(char c)
{
	return (c == EMPTY || c == WALL || c == PLAYER || c == EXIT || c == COLLECTIBLE);
}

t_context*	initialize_map_context(char** map)
{
	t_context	*context;

	context = malloc(sizeof(t_context));
	if (!context)
		return (NULL);
	context->map = map;
	context->player = 0;
	context->exit = 0;
	context->collectible = 0;
	context->map_rows = ft_strlen(map[0]);
	context->map_cols = get_map_column(map);
	return (context);
}
