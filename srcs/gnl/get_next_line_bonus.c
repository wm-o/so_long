/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:55:16 by wmo               #+#    #+#             */
/*   Updated: 2022/12/20 11:55:21 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_node(int fd, t_gnl_list **head)
{
	t_gnl_list	*temp;
	t_gnl_list	*travel;

	travel = *head;
	if ((*head)->fd == fd)
	{
		free((*head)->data);
		temp = (*head)->next;
		free(*head);
		*head = temp;
		return (0);
	}
	while (travel)
	{
		if (travel->fd == fd)
			break ;
		temp = travel;
		travel = travel->next;
	}
	temp->next = travel->next;
	free(travel->data);
	free(travel);
	return (0);
}

t_gnl_list	*cur_node(int fd, t_gnl_list **head)
{
	t_gnl_list	*travel;

	travel = *head;
	while (travel)
	{
		if (travel->fd == fd)
			return (travel);
		travel = travel->next;
	}
	travel = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!travel)
		return (0);
	travel->fd = fd;
	travel->data = malloc(1);
	if (!travel)
	{
		free(travel);
		return (0);
	}
	travel->data[0] = 0;
	travel->next = *head;
	*head = travel;
	return (*head);
}

char	*read_line(int fd, t_gnl_list *node, char *buf, t_gnl_list **head)
{
	int		len;
	char	*temp;

	len = 2147483647;
	while (!ft_strchr(node->data, '\n') && node->data)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = 0;
		temp = node->data;
		node->data = ft_strjoin(node->data, buf);
		if (!node->data)
		{
			free_node(fd, head);
			return (0);
		}
		free(temp);
		if (len < BUFFER_SIZE)
			break ;
	}
	free(buf);
	if (len == -1 || (len == 0 && (node->data[0] == 0)))
		return (free_node(fd, head));
	return (node->data);
}

char	*divide_line(t_gnl_list *node)
{
	size_t	i;
	char	*left;
	char	*right;
	char	*line;

	i = 0;
	line = node->data;
	while (line[i] && line[i] != '\n')
		i++;
	left = ft_substr(node->data, 0, i + 1);
	if (!left)
		return (0);
	right = ft_substr((node->data), i + 1, ft_strlen(node->data) - i - 1);
	if (!right)
	{
		free(left);
		return (0);
	}
	free(line);
	node->data = right;
	return (left);
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*node;
	char				*buf;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	node = cur_node(fd, &head);
	if (!node)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free_node(fd, &head));
	if (!read_line(fd, node, buf, &head))
		return (0);
	line = divide_line(node);
	if (!line)
		return (free_node(fd, &head));
	return (line);
}
