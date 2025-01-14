/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:22:35 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/14 01:54:48 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	is_valid_file_extension(char *file_path)
{
	int	i;

	i = ft_strlen(file_path);
	if (i > 4 && file_path[i - 1] == 'r' && file_path[i - 2] == 'e'
		&& file_path[i - 3] == 'b' && file_path[i - 4] == '.')
		return (1);
	return (0);
}
