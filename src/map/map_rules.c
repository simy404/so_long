/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:43:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/17 20:19:42 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_border_tile(int r, int c, t_context* context)
{
    return (r == 0 || r == context->map_row_count - 1 || c == 0 || c == context->map_col_count - 1);
}

int	is_map_large_enough(t_context* context)
{
	return (!(context->map_col_count < 3 || context->map_row_count < 3));
}

int	is_tile_type_valid(char c)
{
	return (c == EMPTY || c == WALL || c == PLAYER || c == EXIT || c == COLLECTIBLE);
}

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
int	validate_tile(t_context* context, int r, int c)
{
	if (!is_tile_type_valid(context->map[c][r]))
		return (print_error("Error\nInvalid character in map"));
	if (is_border_tile(r, c, context) && context->map[c][r] != WALL)
		return (print_error("Error\nMap is not surrounded by walls"));
	return (1);
}
