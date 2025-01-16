/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:43:31 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/17 00:17:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_border_tile(int r, int c, t_context* context)
{
    return (r == 0 || r == context->map_rows - 1 || c == 0 || c == context->map_cols - 1);
}

int	is_map_large_enough(t_context* context)
{
	return (!(context->map_cols < 3 || context->map_rows < 3));
}

int	is_valid_tile(char c)
{
	return (c == EMPTY || c == WALL || c == PLAYER || c == EXIT || c == COLLECTIBLE);
}
