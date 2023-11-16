/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:24:22 by naadou            #+#    #+#             */
/*   Updated: 2023/11/16 15:24:07 by naadou           ###   ########.fr       */
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

	len = n;
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + 48;
	ft_putchar_fd(c, fd);
	return (ft_len(len));
}
