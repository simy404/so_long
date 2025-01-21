/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:34:04 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/21 17:34:04 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "minilibx/mlx.h"
#include <X11/X.h>
#include <stdlib.h>


int	exit_my(t_game *game)
{
	safe_exit_with_error(game, NULL, NULL);
	return 1;
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**map_array;

	if (argc != 2)
		return (print_error("Error\nInvalid number of arguments"));
	map_array = load_map_array(argv[1]);
	if (!map_array)
		return (0);
	game = init_game(map_array);
	if (!process_map_if_valid(game->map) || !is_map_elements_reachable(game))
		safe_exit_with_error(game, NULL, NULL);
	if (!initialize_graphics(game))
		safe_exit_with_error(game, NULL, NULL);
	mlx_hook(game->graphics->mlx_win, KeyPress, KeyPressMask, key_input_handler,
		game);
	mlx_hook(game->graphics->mlx_win, 17, 1 << 17L, exit_my, game);
	mlx_loop(game->graphics->mlx);
}
