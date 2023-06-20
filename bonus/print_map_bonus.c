/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:34:47 by wmo               #+#    #+#             */
/*   Updated: 2023/02/22 19:15:00 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map_ele(t_game *g, int i, int j, int dir)
{
	void	*temp;
	void	*temp2;

	temp = g->img.p[dir % 10];
	temp2 = g->img.item[g->time % 4];
	g->p_status = dir;
	if (g->map[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, j * 64, i * 64);
	if (g->map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->img.road, j * 64, i * 64);
	if (g->map[i][j] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, temp, j * 64, i * 64);
	if (g->map[i][j] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.goal, j * 64, i * 64);
	if (g->map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, temp2, j * 64, i * 64);
	if (g->map[i][j] == 'X')
		mlx_put_image_to_window(g->mlx, g->win, g->img.box, j * 64, i * 64);
}

void	print_window(t_game *g, int dir)
{
	int		i;
	int		j;
	char	*num;

	i = 0;
	j = 0;
	while (i < g->m.y)
	{
		j = 0;
		while (j < g->m.x)
		{
			check_map_ele(g, i, j, dir);
			j++;
		}
		i++;
	}
	num = ft_itoa(g->cnt);
	if (!num)
	{
		free_map(g);
		free_mlx(g);
		exit(1);
	}
	mlx_string_put(g->mlx, g->win, 32, 32, 0xFF0000, num);
	free(num);
}
