/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsamir <hsamir@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 03:41:20 by hsamir            #+#    #+#             */
/*   Updated: 2025/03/22 12:38:17 by hsamir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/so_long.h"

int enqueue (t_queue *queue, t_node new_node)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	*new = new_node;
	if (queue->head == NULL)
	{
		queue->head = new;
		queue->tail = new;
	}
	else
	{
		queue->tail->next = new;
		queue->tail = new;
	}
	return (1);
}

void	dequeue (t_queue *queue)
{
	t_node	*tmp;

	if (queue->head == NULL)
		return ;
	tmp = queue->head;
	queue->head = queue->head->next;
	if (queue->head == NULL)
		queue->tail = NULL;
	free(tmp);
}
