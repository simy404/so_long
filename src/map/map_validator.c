/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:56:38 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/21 14:56:38 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdlib.h>

int process_map_if_valid(t_map *map)
{
	int r;
	int c;

	if (!is_map_large_enough(map))
		return (print_error("Error\nMap width or height is too small"));
	c = 0;
	while (map->map[c])
	{
		r = 0;
		while (map->map[c][r])
		{
			if (!validate_tile(map, r, c))
				return (0);
			update_map_elements(map, map->map[c][r]);
			if (map->map[c][r] == PLAYER)
				set_player_position(map, r, c);
			r++;
		}
		if (map->map_row_count != r)
			return (print_error("Error\nMap is not rectangular"));
		c++;
	}
	return (validate_required_elements(map));
}
#pragma region dfs_map_search

void dfs_map_search(char **map, int *elements, int c, int r)
{
	if (map[c][r] == WALL || *elements == 0)
		return;
	*(elements) -= ((map[c][r] == COLLECTIBLE) || (map[c][r] == EXIT));
	map[c][r] = WALL;
	dfs_map_search(map, elements, c, r + 1);
	dfs_map_search(map, elements, c, r - 1);
	dfs_map_search(map, elements, c + 1, r);
	dfs_map_search(map, elements, c - 1, r);
}
#pragma endregion

#pragma region  bfs_map_search
int	add_valid_neighbor(t_queue *queue, char **visited, const int(*direction)[2])
{
	int i;
	int col;
	int row;

	i = 0;
	while (i < 4)
	{
		col = queue->head->col + direction[i][0];
		row = queue->head->row + direction[i][1];
		if (visited[col][row] != WALL)
		{
			if (!enqueue(queue, (t_node){col, row, visited[col][row], NULL}))
				return (0);
			visited[col][row] = WALL;
		}
		i++;
	}
	return (1);
}

int	bfs_map_search(int *elements, char **visited, int p_col, int p_row)
{
	t_queue queue;

	queue = (t_queue){0};
	if (!enqueue(&queue, (t_node){p_col, p_row, visited[p_col][p_row], NULL}))
		return (0);
	visited[queue.head->col][queue.tail->row] = WALL;
	while (queue.head != NULL && *elements != 0)
	{
		if (queue.head->val == COLLECTIBLE || queue.head->val == EXIT)
			(*elements)--;
		if (!add_valid_neighbor(&queue, visited, (const int [4][2]){{1, 0}, {-1, 0}, {0, 1}, {0, -1}}))
		{
			free_queue(&queue);
			return (0);
		}
		dequeue(&queue);
	}
	free_queue(&queue);
	return (1);
}
#pragma endregion

int is_map_elements_reachable(t_game *game)
{
	char **map_arr;
	int elements;

	elements = game->map->collectible + game->map->exit;
	map_arr = duplicate_map(game->map);
	if (!map_arr)
		safe_exit_with_error(game, NULL, "Error\nMemory allocation failed");
	/* DFS search
	dfs_map_search(map_arr, &elements, game->map->player_col,
		game->map->player_row);
	*/
	/* BFS search */
	if (!bfs_map_search(&elements, map_arr, game->map->player_col,
		game->map->player_row))
		return (free_map_arr(map_arr), print_error("Error\nMemory allocation failed"));
	free_map_arr(map_arr);
	if (elements != 0)
		return (print_error("Error\nMap elements are not reachable"));
	return (1);
}
