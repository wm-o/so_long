/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:03 by wmo               #+#    #+#             */
/*   Updated: 2023/02/22 19:24:27 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_row(t_game *g, char **argv)
{
	char	*temp;
	int		row;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		open_error(g, fd);
	temp = get_next_line(fd);
	if (!temp)
		open_error(g, fd);
	row = 1;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		row++;
	}
	free(temp);
	close(fd);
	g->m.y = row - 1;
}

void	get_map(t_game *g, char **argv)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		open_error(g, fd);
	g->map = (char **)malloc(sizeof(char *) * (g->m.y + 1));
	if (!g->map)
		open_error(g, fd);
	g->map[g->m.y] = 0;
	g->map[i] = get_next_line(fd);
	g->m.x = ft_strlen(g->map[i]) - 1;
	i++;
	while (i < g->m.y)
	{
		g->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	check_map_error(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->m.y)
	{
		if (g->map[i][0] != 49)
			map_error(g);
		if (g->map[i][g->m.x - 1] != 49)
			map_error(g);
		if ((g->m.x + 1) != (int)ft_strlen(g->map[i]))
			map_error(g);
		i++;
	}
	i = 0;
	while (i < g->m.x)
	{
		if (g->map[0][i] != 49)
			map_error(g);
		if (g->map[g->m.y - 1][i] != 49)
			map_error(g);
		i++;
	}
}

void	check_element(t_game *g)
{
	t_point	p;

	p.y = 0;
	while (p.y < g->m.y)
	{
		p.x = 0;
		while (p.x < g->m.x)
		{
			if (g->map[p.y][p.x] == 'P')
			{
				g->ele.player++;
				g->p.y = p.y;
				g->p.x = p.x;
			}
			if (g->map[p.y][p.x] == 'E')
				g->ele.exit++;
			if (g->map[p.y][p.x] == 'C')
				g->ele.item++;
			p.x++;
		}
		p.y++;
	}
	if (g->ele.player != 1 || g->ele.exit != 1 || g->ele.item < 1)
		map_error(g);
}

void	init_map(t_game *g, char **argv)
{
	get_row(g, argv);
	if (g->m.y < 3)
		map_error(g);
	get_map(g, argv);
	check_map_error(g);
	if (g->m.x < 3)
		map_error(g);
	check_element(g);
	g->item = g->ele.item;
	check_valid_map(g);
	check_map_ele2(g);
}
