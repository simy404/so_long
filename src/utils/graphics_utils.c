/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:18:22 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/21 14:53:15 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../minilibx/mlx.h"
#include <stdlib.h>

void	*get_image_by_tile(t_graphics *graphics, char tile)
{
	if (tile == WALL)
		return (graphics->wall_img);
	else if (tile == EMPTY || tile == PLAYER)
		return (graphics->empty_img);
	else if (tile == COLLECTIBLE)
		return (graphics->collectible_img);
	else if (tile == EXIT)
		return (graphics->exit_img);
	return (NULL);
}

void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->graphics->mlx, game->graphics->mlx_win,
		game->graphics->player_img, game->map->player_row * TILE_SIZE,
		game->map->player_col * TILE_SIZE);
}

void	*load_image(t_graphics *graphics, char *path)
{
	int		h;
	int		w;
	void	*img;

	img = mlx_xpm_file_to_image(graphics->mlx, path, &w, &h);
	if (!img)
		return (NULL);
	return (img);
}
