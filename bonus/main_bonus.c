/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:05:35 by wmo               #+#    #+#             */
/*   Updated: 2023/02/23 10:48:51 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_st(t_game *g)
{
	g->p.y = 0;
	g->p.x = 0;
	g->e.y = 0;
	g->e.x = 0;
	g->m.y = 0;
	g->m.x = 0;
	g->map = 0;
	g->mlx = 0;
	g->win = 0;
	g->p_status = UP;
	g->ele.exit = 0;
	g->ele.item = 0;
	g->ele.player = 0;
	g->is_valid = 0;
	g->v = 0;
	g->cnt = 0;
	g->time = 0;
	g->save = 0;
}

void	check_arg(int argc, char **argv)
{
	int		i;
	char	*temp;

	temp = ".ber";
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		write(2, "check your arg\n", 15);
		exit(1);
	}
	i = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][i - 4], temp, 4))
	{
		write(2, "Error\n", 6);
		write(2, "check your file name\n", 21);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_st(&game);
	check_arg(argc, argv);
	init_map(&game, argv);
	init_game(&game);
	play_game(&game);
	return (0);
}
