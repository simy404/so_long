/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:48:52 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/21 20:14:18 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../minilibx/mlx.h"

void	render_map(t_game *game)
{
	int		row;
	int		col;
	void	*img;

	col = 0;
	while (game->map->map[col])
	{
		row = 0;
		while (game->map->map[col][row])
		{
			img = get_image_by_tile(game->graphics, game->map->map[col][row]);
			mlx_put_image_to_window(game->graphics->mlx,
				game->graphics->mlx_win, img, row * TILE_SIZE, col * TILE_SIZE);
			row++;
		}
		col++;
	}
}

int	create_images(t_graphics *graphics)
{
	graphics->wall_img = load_image(graphics, "./assets/Wall2.xpm");
	if (!graphics->wall_img)
		return (print_error("Error\nFailed to load wall image"));
	graphics->player_img = load_image(graphics, "./assets/Player2.xpm");
	if (!graphics->player_img)
		return (print_error("Error\nFailed to load player image"));
	graphics->collectible_img = load_image(graphics,
			"./assets/Collectible.xpm");
	if (!graphics->collectible_img)
		return (print_error("Error\nFailed to load collectible image"));
	graphics->empty_img = load_image(graphics, "./assets/Empty.xpm");
	if (!graphics->empty_img)
		return (print_error("Error\nFailed to load empty image"));
	graphics->exit_img = load_image(graphics, "./assets/Exit.xpm");
	if (!graphics->exit_img)
		return (print_error("Error\nFailed to load exit image"));
	return (1);
}

int	create_window(t_game *game)
{
	game->graphics->mlx = mlx_init();
	if (!game->graphics->mlx)
		return (print_error("Error\nFailed to initialize mlx"));
	game->graphics->mlx_win = mlx_new_window(game->graphics->mlx,
			game->map->map_row_count * TILE_SIZE, game->map->map_col_count
			* TILE_SIZE, "so_long");
	if (!game->graphics->mlx_win)
		return (print_error("Error\nFailed to create window"));
	return (1);
}

int	initialize_graphics(t_game *game)
{
	if (!create_window(game) || !create_images(game->graphics))
		return (0);
	render_map(game);
	render_player(game);
	return (1);
}
