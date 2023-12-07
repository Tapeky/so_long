/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:47:36 by tsadouk           #+#    #+#             */
/*   Updated: 2023/12/07 16:00:48 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_queue	*create_queue(int capacity)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->capacity = capacity;
	queue->front = 0;
	queue->rear = 0;
	queue->array = (t_queue_node *)malloc(sizeof(t_queue_node) * capacity);
	if (!queue->array)
	{
		free(queue);
		return (NULL);
	}
	return (queue);
}

bool	is_empty(t_queue *queue)
{
	return (queue->front == queue->rear);
}

void	enqueue(t_queue *queue, t_queue_node node)
{
	if (is_empty)
	queue->rear++;
}
