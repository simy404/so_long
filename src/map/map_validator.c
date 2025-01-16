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
#include <stdio.h>
#include <stdlib.h>

int	validate_required_elements(t_context* context)
{
	if (context->player != 1)
		return (print_error("Error\nMap must have one player"));
	if (context->exit != 1)
		return (print_error("Error\nMap must have one exit"));
	if (context->collectible < 1)
		return (print_error("Error\nMap must have at least one collectible"));
	return (1);
}

int	is_tile_valid(t_context* context, int r, int c)
{
	if (!is_valid_tile(context->map[c][r]))
		return (print_error("Error\nInvalid character in map"));
	if (is_border_tile(r, c, context) && context->map[c][r] != WALL)
		return (print_error("Error\nMap is not surrounded by walls"));
	return (1);
}

void set_player_position(t_context* context, int r, int c)
{
	context->player_col = c;
	context->player_row = r;
}
int	process_map_if_valid(t_context* context)
{
	int	r;
	int	c;

	if (!is_map_large_enough(context))
		return (print_error("Error\nMap is too small"));
	c = 0;
	while (context->map[c])
	{
		r = 0;
		while (context->map[c][r])
		{
			if (!is_tile_valid(context, r, c))
				return (0);
			update_map_elements(context, context->map[c][r]);
			if (context->map[c][r] == PLAYER)
				set_player_position(context, r, c);
			r++;
		}
		if (context->map_rows != r)
			return (print_error("Error\nMap is not rectangular"));
		c++;
	}
	return (validate_required_elements(context));
}
void explore_and_mark_tiles(char** map, int* collectible, int* exit, int c, int r)
{
	if (map[c][r] == COLLECTIBLE)
		(*collectible)--;
	else if (map[c][r] == EXIT)
		(*exit)--;
	map[c][r]= WALL;
	if (map[c][r + 1] != WALL)
		explore_and_mark_tiles(map, collectible, exit, c, r + 1);
	if (map[c][r - 1] != WALL)
		explore_and_mark_tiles(map, collectible, exit, c, r - 1);
	if (map[c + 1][r] != WALL)
		explore_and_mark_tiles(map, collectible, exit, c + 1, r);
	if (map[c - 1][r] != WALL)
		explore_and_mark_tiles(map, collectible, exit, c - 1, r);
}
void free_map_copy(char **map)
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
char **map_copy(t_context* context)
{
	char	**map;
	int		i;

	map = malloc((context->map_rows + 1)*  sizeof(char*));
	if (!map)
		return (NULL);
	i = 0;
	while (context->map[i])
	{
		map[i] = ft_strdup(context->map[i]);
		if (!map[i])
		{
			free_map_copy(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}
int	is_map_fully_accessible(t_context* context, int c, int r)
{
	char	**map;
	int 	collectible;
	int 	exit;

	collectible = context->collectible;
	exit = context->exit;
	map = map_copy(context);
	explore_and_mark_tiles(map, &collectible, &exit, c, r);
	free_map_copy(map);
	printf("collectible: %d, exit: %d\n", collectible, exit);
	if (collectible != 0 || exit != 0)
		return (0);
	return (1);
}
