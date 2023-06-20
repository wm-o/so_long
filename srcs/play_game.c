/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:49:55 by wmo               #+#    #+#             */
/*   Updated: 2023/02/22 19:31:36 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_game *g, int key)
{
	if (key == UP)
		if (g->p.y - 1 > 0 && g->map[g->p.y - 1][g->p.x] != '1')
			return (1);
	if (key == DOWN)
		if (g->p.y + 1 < g->m.y && g->map[g->p.y + 1][g->p.x] != '1')
			return (1);
	if (key == LEFT)
		if (g->p.x - 1 > 0 && g->map[g->p.y][g->p.x - 1] != '1')
			return (1);
	if (key == RIGHT)
		if (g->p.x + 1 < g->m.x && g->map[g->p.y][g->p.x + 1] != '1')
			return (1);
	if (key == ESC)
		press_esc(g);
	return (0);
}

void	move(t_game *g, int y, int x, t_point p)
{
	if (g->map[y][x] == 'E' && g->item < 1)
		game_clear(g);
	if (g->map[y][x] == 'X')
		game_over(g, 0);
	else if (g->map[y][x] == 'E')
		return ;
	if (g->map[y][x] == 'C')
		g->item--;
	g->map[y][x] = 'P';
	g->map[p.y][p.x] = '0';
	g->p.y = y;
	g->p.x = x;
	g->cnt++;
	ft_putnbr(g->cnt);
	write(1, "\n", 1);
}

int	key_press(int key, t_game *g)
{
	t_point	p;

	p.y = g->p.y;
	p.x = g->p.x;
	if (key != UP && key != DOWN && key != LEFT && key != RIGHT && key != ESC)
		return (0);
	if (key == UP && check_player(g, key))
		move(g, g->p.y - 1, g->p.x, p);
	if (key == DOWN && check_player(g, key))
		move(g, g->p.y + 1, g->p.x, p);
	if (key == LEFT && check_player(g, key))
		move(g, g->p.y, g->p.x - 1, p);
	if (key == RIGHT && check_player(g, key))
		move(g, g->p.y, g->p.x + 1, p);
	if (key == ESC)
		press_esc(g);
	print_window(g, key);
	return (0);
}

int	go(t_game *g)
{
	mlx_hook(g->win, 2, 0, &key_press, g);
	mlx_hook(g->win, 17, 0, &press_esc, g);
	g->time++;
	if (g->time == 2147483647)
		g->time = 0;
	if (g->time % 100 == 0)
		enemy_patrol(g);
	print_window(g, g->p_status);
	return (0);
}

void	play_game(t_game *g)
{
	g->time = 0;
	mlx_loop_hook(g->mlx, &go, g);
	mlx_loop(g->mlx);
}
