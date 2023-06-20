/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:55:43 by wmo               #+#    #+#             */
/*   Updated: 2022/12/20 11:56:08 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*p;
	int		i;

	i = 0;
	if (!s1)
		return (0);
	len = ft_strlen(s1) + 1;
	p = (char *)malloc(sizeof(char) * len);
	if (!p)
		return (0);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = s1[i];
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	size;
	char			*p;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (size < start || !len)
		return (ft_strdup(""));
	if (size <= len + start)
		len = size - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	i = 0;
	while (i < len && s[start])
		p[i++] = s[start++];
	p[i] = 0;
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	temp;

	temp = c;
	while (*s)
	{
		if (*s == temp)
			return ((char *)s);
		s++;
	}
	if (temp == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	l1;
	size_t	l2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!p)
		return (0);
	while (i < l1)
	{
		p[i] = s1[i];
		i++;
	}
	while (j < l2)
		p[i++] = s2[j++];
	p[i] = 0;
	return (p);
}
