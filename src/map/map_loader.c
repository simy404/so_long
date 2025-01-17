/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:22:48 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 01:54:55 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char*	read_map_file(char* file_path)
{
	int		fd;
	char	*file_content;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return(NULL);
	file_content = read_file_from_fd(fd);
	close(fd);
	return (file_content);
}

char	**load_map_array(char* file_path)
{
	char	*file_content;
	char	**map_array;

	if (!is_valid_file_extension(file_path))
		return (print_error_null_array("Error\nInvalid file extension"));
	file_content = read_map_file(file_path);
	if (!file_content)
		return (print_error_null_array("Error\nInvalid file"));
	if (file_content[0] != '\n' && !has_sequential_newline(file_content))
		map_array = ft_split(file_content, '\n');
	else
		print_error("Error\nContains sequential or just newline");
	free(file_content);
	return (map_array);
}
