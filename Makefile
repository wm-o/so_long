# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 13:03:42 by wmo               #+#    #+#              #
#    Updated: 2023/02/23 10:20:12 by wmo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/main.c \
		./srcs/init_game.c \
		./srcs/check_error.c \
		./srcs/init_map.c \
		./srcs/init_map2.c \
		./srcs/so_long_utils.c \
		./srcs/free_case.c \
		./srcs/dfs.c \
		./srcs/play_game.c \
		./srcs/print_map.c \
		./srcs/queue.c \
		./srcs/stop_game.c \
		./srcs/bfs.c \
		./srcs/gnl/get_next_line_bonus.c \
		./srcs/gnl/get_next_line_utils_bonus.c \

SRCS_B =	./bonus/main_bonus.c \
			./bonus/init_game_bonus.c \
			./bonus/check_error_bonus.c \
			./bonus/init_map_bonus.c \
			./bonus/init_map2_bonus.c \
			./bonus/so_long_utils_bonus.c \
			./bonus/free_case_bonus.c \
			./bonus/dfs_bonus.c \
			./bonus/play_game_bonus.c \
			./bonus/print_map_bonus.c \
			./bonus/queue_bonus.c \
			./bonus/stop_game_bonus.c \
			./bonus/bfs_bonus.c \
			./bonus/gnl/get_next_line_bonus.c \
			./bonus/gnl/get_next_line_utils_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

RM = rm -f

ifdef WITH_BONUS
	OBJ_ALL = $(OBJS_B)
else
	OBJ_ALL = $(OBJS)
endif

all : $(NAME)

bonus : 
		make WITH_BONUS=1 all

$(NAME) :   $(OBJ_ALL)
			$(CC) $(CFLAGS) $(MLX) -o so_long $(OBJ_ALL)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		$(RM) $(OBJS) $(OBJS_B)

fclean :    clean
			$(RM) $(NAME)

re :        fclean all

.PHONY : all clean fclean re bonus
