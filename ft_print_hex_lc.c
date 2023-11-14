/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:47:08 by naadou            #+#    #+#             */
/*   Updated: 2023/11/14 18:28:28 by naadou           ###   ########.fr       */
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

static void	hexstring(char *str)
{
	int	i;
	int	j;

	j = 48;
	i = 0;
	while (i < 16)
	{
		if (j == 58)
			j = 97;
		str[i] = j;
		i++;
		j++;
	}
	str[i] = 0;
}

static void	hex_print(unsigned int n, char *hex)
{
	char	c;

	if (n >= 16)
		hex_print(n / 16, hex);
	c = hex[n % 16];
	ft_putchar_fd(c, 1);
}

int	ft_print_hex_lc(unsigned int n)
{
	char	hex[17];
	int		len;

	len = n;
	hexstring(hex);
	hex_print(n, hex);
	return (ft_len(len));
}
