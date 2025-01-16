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

void	update_map_context(t_context* map_context, char tile)
{
	if (tile == PLAYER)
		map_context->player++;
	if (tile == EXIT)
		map_context->exit++;
	if (tile == COLLECTIBLE)
		map_context->collectible++;
}
int	validate_map_requirements(t_context* context)
{
	if (context->player != 1)
		return (print_error("Error\nMap must have one player"));
	if (context->exit != 1)
		return (print_error("Error\nMap must have one exit"));
	if (context->collectible < 1)
		return (print_error("Error\nMap must have at least one collectible"));
	return (1);
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
			if (!is_valid_char(context->map[c][r]))
				return (print_error("Error\nInvalid character in map"));
			if (is_border_tile(r, c, context) && context->map[c][r] != WALL)
				return (print_error("Error\nMap is not surrounded by walls"));
			update_map_context(context, context->map[c][r]);
			r++;
		}
		if (context->map_rows != r)
			return (print_error("Error\nMap is not rectangular"));
		c++;
	}
	return (validate_map_requirements(context));
}

