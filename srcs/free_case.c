/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:40:07 by wmo               #+#    #+#             */
/*   Updated: 2023/02/23 10:35:46 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	if (g->map)
	{
		while (g->map[i])
		{
			free(g->map[i]);
			g->map[i] = 0;
			i++;
		}
		free(g->map);
		g->map = 0;
	}
}

void	free_visit(t_game *g, int row)
{
	int	i;

	i = 0;
	if (g->v)
	{
		while (i < row)
		{
			free(g->v[i]);
			g->v[i] = 0;
			i++;
		}
		free(g->v);
		g->v = 0;
	}
}

void	free_mlx(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(g->mlx, g->img.p[i]);
		mlx_destroy_image(g->mlx, g->img.item[i]);
		i++;
	}
	mlx_destroy_image(g->mlx, g->img.goal);
	mlx_destroy_image(g->mlx, g->img.wall);
	mlx_destroy_image(g->mlx, g->img.road);
	mlx_destroy_image(g->mlx, g->img.box);
	mlx_destroy_window(g->mlx, g->win);
}

int	press_esc(t_game *g)
{
	free_mlx(g);
	free_map(g);
	exit(0);
	return (0);
}

void	game_clear(t_game *g)
{
	g->cnt++;
	ft_putnbr(g->cnt);
	write(1, "\n", 1);
	write(1, "clear\n", 6);
	free_mlx(g);
	free_map(g);
	exit(0);
}
