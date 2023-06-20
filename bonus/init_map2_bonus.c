/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:43:39 by wmo               #+#    #+#             */
/*   Updated: 2023/02/22 19:24:45 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_ele_pos(t_game *g, int y, int x)
{
	if (g->map[y][x] == 'E')
	{
		g->e.y = y;
		g->e.x = x;
	}
	if (g->map[y][x] == 'P')
	{
		g->p.y = y;
		g->p.x = x;
	}
	if (g->map[y][x] == 'X')
	{
		g->b.y = y;
		g->b.x = x;
	}
}

int	check_word(char c)
{
	if (c == 'C' || c == 'E' || c == '0' || c == '1' || c == 'P')
		return (1);
	if (c == 'X')
		return (1);
	return (0);
}

void	check_map_ele2(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->m.y)
	{
		j = 0;
		while (j < g->m.x)
		{
			if (!check_word(g->map[i][j]))
				map_error(g);
			j++;
		}
		i++;
	}
}
