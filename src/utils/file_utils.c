/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:25:15 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/13 23:27:43 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*str_append(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, s1_len);
	ft_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	return (str);
}

char	*read_file_from_fd(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		read_bytes;
	char	*str;

	str = NULL;
	read_bytes = BUFFER_SIZE;
	while (read_bytes == BUFFER_SIZE)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes == -1)
		{
			free(str);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		temp = str;
		str = str_append(str, buffer);
		free(temp);
		if (!str)
			return (NULL);
	}
	return (str);
}

int	is_valid_file_extension(char *file_path)
{
	int	i;

	i = ft_strlen(file_path);
	if (i > 4 && file_path[i - 1] == 'r' && file_path[i - 2] == 'e'
		&& file_path[i - 3] == 'b' && file_path[i - 4] == '.')
		return (1);
	return (0);
}

