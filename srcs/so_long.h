/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:05:55 by wmo               #+#    #+#             */
/*   Updated: 2023/02/23 10:39:36 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "gnl/get_next_line_bonus.h"
# include "fcntl.h"

# define ESC		53
# define UP			13
# define DOWN		1
# define LEFT		0
# define RIGHT		2

typedef struct s_ele
{
	int	player;
	int	item;
	int	exit;
}	t_ele;

typedef struct s_point
{
	int	y;
	int	x;
}	t_point;

typedef struct s_list
{
	t_point			data;
	struct s_list	*next;
}	t_list;

typedef struct s_queue
{
	t_list	*head;
	t_list	*tail;
	int		size;
}	t_queue;

typedef struct s_img
{	
	void	*p[4];
	void	*wall;
	void	*item[4];
	void	*goal;
	void	*road;
	void	*box;
}	t_img;

typedef struct s_game
{
	t_point		p;
	t_point		e;
	t_point		b;
	t_point		m;
	t_ele		ele;
	t_img		img;
	t_point		**save;
	int			is_valid;
	int			item;
	int			time;
	int			**v;
	int			p_status;
	char		**map;
	void		*mlx;
	void		*win;
	long long	cnt;
}	t_game;

void	init_game(t_game *g);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	open_error(t_game *g, int fd);
void	map_error(t_game *g);
void	visit_error(t_game *g, int row);
void	save_error(t_game *g, int row);
void	init_map(t_game *g, char **argv);
void	free_map(t_game *g);
void	free_visit(t_game *g, int row);
void	check_valid_map(t_game *g);
int		press_esc(t_game *g);
void	check_map_ele(t_game *g, int i, int j, int dir);
void	print_window(t_game *g, int dir);
void	play_game(t_game *g);
void	free_mlx(t_game *g);
void	game_clear(t_game *g);
void	ft_putnbr(long long n);
char	*ft_itoa(long long n);
void	dequeue(t_queue *q);
void	enqueue(t_queue *q, t_game *g, t_point data);
void	init_queue(t_queue *q);
void	check_ele_pos(t_game *g, int y, int x);
void	init_visited(t_game *g);
int		check_valid_pos(t_game *g, int y, int x);
void	game_over(t_game *g, t_queue *q);
void	enemy_patrol(t_game *g);
void	free_save(t_game *g, int row);
void	check_map_ele2(t_game *g);

#endif
