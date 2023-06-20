/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmo <wmo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:36:30 by wmo               #+#    #+#             */
/*   Updated: 2023/02/21 09:42:45 by wmo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	a;
	unsigned char	b;

	while (n--)
	{
		a = *s1;
		b = *s2;
		if (a == 0 && b == 0)
			return (0);
		if (a != b)
			return (a - b);
		s1++;
		s2++;
	}
	return (0);
}

void	rec(long long n)
{
	char	t;

	if (n == 0)
		return ;
	rec(n / 10);
	t = n % 10 + 48;
	write(1, &t, 1);
}

void	ft_putnbr(long long n)
{
	long long	temp;

	temp = n;
	if (n < 0)
		temp = -temp;
	if (n == 0)
		write(1, "0\n", 2);
	rec(temp);
	return ;
}

static int	check_n(long long n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long long n)
{
	long long	temp;
	char		*p;
	int			len;

	temp = n;
	len = check_n(temp);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	p[len] = 0;
	if (n == 0)
		p[0] = 48;
	if (temp < 0)
		temp = -temp;
	while (temp)
	{
		p[--len] = (temp % 10) + 48;
		temp /= 10;
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}
