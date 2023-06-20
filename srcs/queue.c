/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:58:43 by wmo               #+#    #+#             */
/*   Updated: 2023/02/21 10:56:08 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_queue(t_queue *q)
{
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

t_list	*init_node(t_game *g, t_point data, t_list *next)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		free_map(g);
		free_mlx(g);
		exit(1);
	}
	node->next = next;
	node->data = data;
	return (node);
}

void	enqueue(t_queue *q, t_game *g, t_point data)
{
	t_list	*node;

	node = init_node(g, data, 0);
	if (q->size == 0)
	{
		q->head = node;
		q->tail = node;
		q->size++;
		return ;
	}
	q->tail->next = node;
	q->tail = node;
	q->size++;
	return ;
}

void	dequeue(t_queue *q)
{
	t_list	*temp;

	if (!q->size)
		return ;
	if (q->size == 1)
	{
		free(q->head);
		q->head = 0;
		q->size--;
		return ;
	}
	temp = q->head;
	q->head = q->head->next;
	free(temp);
	temp = 0;
	q->size--;
	return ;
}
