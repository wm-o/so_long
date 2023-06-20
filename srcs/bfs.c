/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:16:26 by wmo               #+#    #+#             */
/*   Updated: 2023/02/22 09:07:16 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_save_point(t_game *g)
{
	int		i;
	int		j;
	t_point	p;

	i = 0;
	p.y = -1;
	p.x = -1;
	g->save = (t_point **)malloc(sizeof(t_point *) * g->m.y);
	if (!g->v)
		save_error(g, 0);
	while (i < g->m.y)
	{
		j = 0;
		g->save[i] = (t_point *)malloc(sizeof(t_point) * g->m.x);
		if (!g->v[i])
			save_error(g, i);
		while (j < g->m.x)
		{
			g->save[i][j] = p;
			j++;
		}
		i++;
	}	
}

void	move_enemy(t_game *g, t_queue *q, int y, int x)
{
	if (y == g->p.y && x == g->p.x)
		game_over(g, q);
	if (g->map[y][x] == 'E' || g->map[y][x] == 'C')
		return ;
	g->map[y][x] = 'X';
	g->map[g->b.y][g->b.x] = '0';
	g->b.y = y;
	g->b.x = x;
}

void	bfs_op(t_game *g, t_queue *q, t_point *temp, t_point *new)
{
	const int	dy[4] = {0, 1, -1, 0};
	const int	dx[4] = {1, 0, 0, -1};
	int			i;

	i = 0;
	while (i < 4)
	{
		new->y = temp->y + dy[i];
		new->x = temp->x + dx[i];
		if (check_valid_pos(g, new->y, new->x))
		{
			g->v[new->y][new->x] = 1;
			g->save[new->y][new->x] = *temp;
			enqueue(q, g, *new);
		}
		i++;
	}
}

void	bfs(t_game *g, t_queue *q)
{
	t_point		temp;
	t_point		new;

	while (q->size)
	{
		temp = q->head->data;
		if (temp.y == g->b.y && temp.x == g->b.x)
		{
			new = g->save[temp.y][temp.x];
			move_enemy(g, q, new.y, new.x);
			return ;
		}
		bfs_op(g, q, &temp, &new);
		dequeue(q);
	}
}

void	enemy_patrol(t_game *g)
{
	t_queue	q;
	t_point	p;

	p.y = g->p.y;
	p.x = g->p.x;
	init_visited(g);
	init_save_point(g);
	init_queue(&q);
	enqueue(&q, g, p);
	bfs(g, &q);
	g->v[p.y][p.x] = 1;
	free_save(g, g->m.y);
	free_visit(g, g->m.y);
	while (q.size)
		dequeue(&q);
}
