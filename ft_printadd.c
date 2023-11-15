/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:17:29 by naadou            #+#    #+#             */
/*   Updated: 2023/11/15 19:30:34 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	hex_print(unsigned long int n, char *hex)
{
	char	c;

	if (n >= 16)
		hex_print(n / 16, hex);
	c = hex[n % 16];
	ft_putchar_fd(c, 1);
}

int	ft_printadd(void *p)
{
	unsigned long int	add;
	char				*hex;

	hex = "0123456789abcdef";
	add = (unsigned long int) p;
	ft_putstr_fd("0x", 1);
	hex_print(add, hex);
	return (ft_len((unsigned long int) p) + 2);
}
