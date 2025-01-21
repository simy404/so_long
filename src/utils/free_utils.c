/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:28:53 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/21 14:55:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../minilibx/mlx.h"
#include <stdlib.h>

void	free_map_arr(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(t_map *map)
{
	if (map->map)
		free_map_arr(map->map);
	free(map);
}

int	free_graphics(t_graphics *graphics)
{
	if (graphics->wall_img)
		mlx_destroy_image(graphics->mlx, graphics->wall_img);
	if (graphics->player_img)
		mlx_destroy_image(graphics->mlx, graphics->player_img);
	if (graphics->collectible_img)
		mlx_destroy_image(graphics->mlx, graphics->collectible_img);
	if (graphics->exit_img)
		mlx_destroy_image(graphics->mlx, graphics->exit_img);
	if (graphics->empty_img)
		mlx_destroy_image(graphics->mlx, graphics->empty_img);
	if (graphics->mlx_win)
		mlx_destroy_window(graphics->mlx, graphics->mlx_win);
	if (graphics->mlx)
	{
		mlx_destroy_display(graphics->mlx);
		free(graphics->mlx);
	}
	free(graphics);
	return (0);
}

int	safe_exit_with_error(t_game *game, char **map, char *error)
{
	if (map)
		free_map_arr(map);
	if (game)
	{
		if (game->graphics)
			free_graphics(game->graphics);
		if (game->map)
			free_map(game->map);
		free(game);
	}
	if (error)
		print_error(error);
	exit(1);
}
