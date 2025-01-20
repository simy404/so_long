/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:56:16 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/20 00:56:16 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>

int	main(int argc, char **argv)
{
	t_game		*game;
	char 		**map_array;

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
	mlx_key_hook(game->graphics->mlx_win, movement, game);
	mlx_loop(game->graphics->mlx);
}
