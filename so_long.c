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

int	main(int argc, char** argv)
{
	char	**map_array;

	if (argc != 2)
		return (print_error("Error"));
	map_array = load_map_array(argv[1]);
	if (!map_array || !validate_map(map_array))
		return (print_error("Error"));
	print_array(map_array);
}
