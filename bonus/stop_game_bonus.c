/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:09:35 by wmo               #+#    #+#             */
/*   Updated: 2023/02/23 10:30:17 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_game *g, t_queue *q)
{
	write(1, "game over\n", 10);
	if (q)
	{
		while (q->size)
			dequeue(q);
	}
	free_map(g);
	free_mlx(g);
	exit(0);
}

int	check_valid_pos2(t_game *g, int y, int x)
{
	if (y < 1 || x < 1 || y > g->m.y - 1 || x > g->m.x - 1)
		return (0);
	if (g->v[y][x] || g->map[y][x] == '1' || g->map[y][x] == 'X')
		return (0);
	return (1);
}
