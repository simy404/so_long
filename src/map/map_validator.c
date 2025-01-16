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

int	is_map_large_enough(t_context* context)
{
	return (!(context->map_cols < 3 || context->map_rows < 3));
}

int	is_border_tile(int r, int c, t_context* context)
{
    return (r == 0 || r == context->map_rows - 1 || c == 0 || c == context->map_cols - 1);
}
void	update_map_context(t_context* map_context, char tile)
{
	if (tile == PLAYER)
		map_context->player++;
	if (tile == EXIT)
		map_context->exit++;
	if (tile == COLLECTIBLE)
		map_context->collectible++;
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
			return (0);
		c++;
	}
	return (context->player == 1 && context->exit == 1 && context->collectible > 0);
}

