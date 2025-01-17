/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/13 13:58:22 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 06:55:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>


void	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_context *context;
	char **map_array;
	int is_valid;

	is_valid = 1;
	if (argc != 2)
		return (print_error("Error\nInvalid number of arguments"));
	map_array = load_map_array(argv[1]);
	if (!map_array)
		return (0);
	context = initialize_map_context(map_array);
	if (!context || !process_map_if_valid(context))
		is_valid = 0;
	if (is_valid && !is_map_fully_accessible(context, context->player_col,
			context->player_row))
	{
		print_error("Error\nMap is not fully accessible");
		is_valid = 0;
	}
	// if (is_valid)
	// 	print_array(context->map);
	free_context(context);
}
