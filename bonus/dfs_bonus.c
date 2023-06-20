/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:16:45 by wmo               #+#    #+#             */
/*   Updated: 2023/02/23 10:31:30 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_valid_pos(t_game *g, int y, int x)
{
	if (y < 1 || x < 1 || y > g->m.y - 1 || x > g->m.x - 1)
		return (0);
	if (g->v[y][x] || g->map[y][x] == '1')
		return (0);
	return (1);
}

void	dfs(t_game *g, int y, int x)
{
	const int	dy[4] = {1, 0, 0, -1};
	const int	dx[4] = {0, 1, -1, 0};
	int			i;

	i = 0;
	if (g->map[y][x] == 'C')
		g->ele.item--;
	if (y == g->e.y && x == g->e.x)
	{
		g->is_valid = 1;
		return ;
	}
	g->v[y][x] = 1;
	while (i < 4)
	{
		if (check_valid_pos2(g, y + dy[i], x + dx[i]))
			dfs(g, y + dy[i], x + dx[i]);
		i++;
	}
}

void	check_pos(t_game *g)
{
	t_point	p;

	p.y = 0;
	while (p.y < g->m.y)
	{
		p.x = 0;
		while (p.x < g->m.x)
		{
			check_ele_pos(g, p.y, p.x);
			p.x++;
		}
		p.y++;
	}
}

void	init_visited(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	g->v = (int **)malloc(sizeof(int *) * g->m.y);
	if (!g->v)
		visit_error(g, 0);
	while (i < g->m.y)
	{
		j = 0;
		g->v[i] = (int *)malloc(sizeof(int) * g->m.x);
		if (!g->v[i])
			visit_error(g, i);
		while (j < g->m.x)
		{
			g->v[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	check_valid_map(t_game *g)
{
	check_pos(g);
	init_visited(g);
	dfs(g, g->p.y, g->p.x);
	free_visit(g, g->m.y);
	if (!g->is_valid || g->ele.item > 0)
		map_error(g);
}
