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
#include <X11/X.h>


void	print_array(char **array)
{
	int i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
// typedef struct s_mlx_struct
// {
// 	void* mlx;
// 	void* mlx_win;
// } t_mlx_struct;

// void key_press_handler(int keycode)
// {
// 	printf("%d\n", keycode);
// 	if (keycode == 65307)
// 		exit(1);
// }
void draw_image(t_context *content, void *mlx, void *mlx_win)
{
	int x = 0;
	int y = 0;
	int w = -1;
	void* image = mlx_xpm_file_to_image(mlx, "assets/Wood.xpm", &w, &w);
			mlx_put_image_to_window(mlx, mlx_win, image, x*TILE_SIZE, y*TILE_SIZE);

	while(content->map[y])
	{
		x = 0;
		while (content->map[x])
		{
			x++;
		}
		mlx_put_image_to_window(mlx, mlx_win, image, (x + 1)*TILE_SIZE, y*TILE_SIZE);

		y++;
	}
}
int	main(int argc, char **argv)
{
	t_context	*context;
	char 		**map_array;
	void		*mlx;
	void		*mlx_win;
	int			is_valid;

	if (argc != 2)
		return (print_error("Error\nInvalid number of arguments"));
	is_valid = 1;
	map_array = load_map_array(argv[1]);
	if (!map_array)
		return (0);
	context = init_map_context(map_array);
	if (!context)
		return (print_error("Error\nFailed to initialize map context"));
	if (!process_map_if_valid(context) || !is_map_elements_reachable(context))
		is_valid = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, TILE_SIZE * (context->map_row_count), TILE_SIZE * (context->map_row_count), "so_long");
	draw_image(context, mlx, mlx_win);
	mlx_loop(mlx);
	free_context(context);
}
