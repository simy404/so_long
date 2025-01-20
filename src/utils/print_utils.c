/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:38:55 by hsamir            #+#    #+#             */
/*   Updated: 2025/01/13 21:39:27 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	print_error(char *error)
{
	ft_putendl_fd(error, 2);
	return (0);
}

void	*print_error_null(char *error)
{
	ft_putendl_fd(error, 2);
	return (NULL);
}
