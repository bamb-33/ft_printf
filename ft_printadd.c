/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:17:29 by naadou            #+#    #+#             */
/*   Updated: 2023/11/16 22:42:11 by marvin           ###   ########.fr       */
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

static void	hex_print(unsigned long int n, char *hex, int *i)
{
	char	c;

	if (n >= 16)
		hex_print(n / 16, hex, i);
	c = hex[n % 16];
	*i = ft_putchar_fd(c, 1);
	if (*i == -1)
		return ;
}

int	ft_printadd(void *p)
{
	unsigned long int	add;
	int					i;
	char				*hex;

	hex = "0123456789abcdef";
	add = (unsigned long int) p;
	i = ft_putstr_fd("0x", 1);
	if (i == -1)
		return (-1);
	hex_print(add, hex, &i);
	if (i == -1)
		return (-1);
	return (ft_len((unsigned long int) p) + 2);
}
