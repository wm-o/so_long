/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:09:18 by wmo               #+#    #+#             */
/*   Updated: 2023/02/22 19:55:49 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_game *g)
{
	int	w;
	int	h;

	g->img.p[0] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/left.xpm", &w, &h);
	g->img.p[1] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/down.xpm", &w, &h);
	g->img.p[2] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/right.xpm", &w, &h);
	g->img.p[3] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/up.xpm", &w, &h);
	g->img.goal = mlx_xpm_file_to_image(g->mlx, \
			"./textures/goal.xpm", &w, &h);
	g->img.item[0] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/item.xpm", &w, &h);
	g->img.wall = mlx_xpm_file_to_image(g->mlx, \
			"./textures/wall.xpm", &w, &h);
	g->img.road = mlx_xpm_file_to_image(g->mlx, \
			"./textures/road.xpm", &w, &h);
}

void	init_img2(t_game *g)
{
	int	w;
	int	h;

	g->img.item[1] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/item2.xpm", &w, &h);
	g->img.item[2] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/item3.xpm", &w, &h);
	g->img.item[3] = mlx_xpm_file_to_image(g->mlx, \
			"./textures/item4.xpm", &w, &h);
	g->img.box = mlx_xpm_file_to_image(g->mlx, \
			"./textures/box.xpm", &w, &h);
}

void	check_valid_img(t_game *g)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!g->img.p[i] || !g->img.item[i])
			map_error(g);
		i++;
	}
	if (!g->img.box || !g->img.goal || !g->img.road || !g->img.wall)
		map_error(g);
}

void	init_game(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->m.x * 64, \
			g->m.y * 64, "so_long");
	init_img(g);
	init_img2(g);
	check_valid_img(g);
}
