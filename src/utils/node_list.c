/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:41:20 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/21 08:27:35 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/so_long.h"

t_node	*get_last_node(t_node *node)
{
	t_node	*last_node;

	last_node = node;
	while (last_node->next)
		last_node = last_node->next;
	return (last_node);
}


void append_node(t_node **node, t_node new_node)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	*new = new_node;
	if (*node == NULL)
		*node = new;
	else
		get_last_node(*node)->next = new;

}
void pop_node(t_node **node)
{
	t_node	*tmp;

	if (!*node)
		return ;
	tmp = *node;
	*node = (*node)->next;
	free(tmp);
}

void insert_node(t_node **node, t_node new_node)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	*new = new_node;
	new->next = *node;
	*node = new;
}
