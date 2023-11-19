/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:24:22 by naadou            #+#    #+#             */
/*   Updated: 2023/11/19 13:18:00 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_len(unsigned long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

unsigned int	ft_u_putnbr_fd(unsigned int n, int fd)
{
	char			c;
	unsigned int	len;
	unsigned int	store;
	int				i;

	i = 1;
	store = n;
	len = ft_len(n);
	while (len > 1)
	{
		i = (i * 9) + i;
		len --;
	}
	len = ft_len(n);
	while (len)
	{
		c = ((n / i) % 10) + 48;
		if (ft_putchar_fd(c, fd) == -1)
			return (-1);
		i = i / 10;
		len --;
	}
	return (ft_len(store));
}
