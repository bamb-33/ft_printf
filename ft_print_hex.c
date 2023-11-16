/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:47:08 by naadou            #+#    #+#             */
/*   Updated: 2023/11/16 12:01:06 by naadou           ###   ########.fr       */
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

static void	hex_print(unsigned int n, char *hex)
{
	char	c;

	if (n >= 16)
		hex_print(n / 16, hex);
	c = hex[n % 16];
	ft_putchar_fd(c, 1);
}

int	ft_print_hex(unsigned int n, int c)
{
	char	*hex;
	int		len;

	len = n;
	if (c == 120)
		hex = "0123456789abcdef";
	if (c == 88)
		hex = "0123456789ABCDEF";
	hex_print(n, hex);
	return (ft_len(len));
}
