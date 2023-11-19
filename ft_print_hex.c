/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:54:29 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 13:22:25 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	hex_print(unsigned int n, char *hex, int *i)
{
	char	c;

	if (n >= 16)
		hex_print(n / 16, hex, i);
	c = hex[n % 16];
	*i = ft_putchar_fd(c, 1);
	if (*i == -1)
		return ;
}

int	ft_print_hex(unsigned int n, int c)
{
	char	*hex;
	int		len;
	int		i;
	int		store;

	len = n;
	if (c == 120)
		hex = "0123456789abcdef";
	if (c == 88)
		hex = "0123456789ABCDEF";
	i = 6;
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
