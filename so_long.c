/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:58:22 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 06:55:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"
#include "minilibx/mlx.h"

#include <stdio.h>
void print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
void free_map(char** map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
		free(map_array[i++]);
	free(map_array);
	map_array = NULL;
}
int	main(int argc, char** argv)
{
	char	**map_array;
	int		is_valid;

	is_valid = 1;
	if (argc != 2)
		return (print_error("Error"));
	map_array = load_map_array(argv[1]);
	if (!map_array || !is_map_valid(map_array))
		is_valid = 0;
	if (is_valid)
		print_array(map_array);
	else
		return (print_error("Error"));
	free_map(map_array);
}
