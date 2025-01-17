/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:06:15 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/17 22:58:04 by hsamir           ###   ########.fr       */
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

t_context	*init_map_context(char **map)
{
	t_context	*context;

	context = malloc(sizeof(t_context));
	if (!context)
		return (NULL);
	context->map = map;
	context->player = 0;
	context->exit = 0;
	context->collectible = 0;
	context->map_row_count = ft_strlen(map[0]);
	context->map_col_count = get_map_col_count(map);
	context->player_col = -1;
	context->player_row = -1;
	return (context);
}

void	update_map_elements(t_context *map_context, char tile)
{
	if (tile == PLAYER)
		map_context->player++;
	else if (tile == EXIT)
		map_context->exit++;
	else if (tile == COLLECTIBLE)
		map_context->collectible++;
}
void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	free_context(t_context *context)
{
	free_map(context->map);
	free(context);
	return (0);
}

void	set_player_position(t_context *context, int r, int c)
{
	context->player_col = c;
	context->player_row = r;
}

char	**duplicate_map(t_context *context)
{
	char	**map;
	int		i;

	map = malloc((context->map_col_count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (context->map[i])
	{
		map[i] = ft_strdup(context->map[i]);
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}
