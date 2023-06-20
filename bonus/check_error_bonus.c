/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:10:05 by wmo               #+#    #+#             */
/*   Updated: 2023/02/22 19:13:56 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	visit_error(t_game *g, int row)
{
	free_map(g);
	free_visit(g, row);
	write(2, "Error\n", 6);
	write(2, "check your heap memory\n", 23);
	exit(1);
}

void	free_save(t_game *g, int row)
{
	int	i;

	i = 0;
	if (g->save)
	{
		while (i < row)
		{
			free(g->save[i]);
			g->save[i] = 0;
			i++;
		}
		free(g->save);
		g->save = 0;
	}
}

void	save_error(t_game *g, int row)
{
	free_save(g, row);
	write(2, "Error\n", 6);
	write(2, "check your heap memory\n", 23);
	exit(1);
}

void	open_error(t_game *g, int fd)
{
	close(fd);
	write(2, "Error\n", 6);
	write(2, "check your map file\n", 20);
	g = 0;
	exit(1);
}

void	map_error(t_game *g)
{
	free_map(g);
	write(2, "Error\n", 6);
	write(2, "Map Error\n", 10);
	exit(1);
}
