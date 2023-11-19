/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:57:56 by naadou            #+#    #+#             */
/*   Updated: 2023/11/19 13:15:22 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static int	ft_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		len;
	int		i;
	int		store;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n -= -1;
	}
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

	// len = n;
	// if (n == -2147483648)
	// 	write(fd, "-2147483648", 11);
	// else if (n < 0)
	// {
	// 	write (fd, "-", 1);
	// 	n *= -1;
	// 	ft_putnbr_fd(n, fd);
	// }
	// else
	// {
	// 	if (n > 9)
	// 		ft_putnbr_fd(n / 10, fd);
	// 	c = (n % 10) + 48;
	// 	i = ft_putchar_fd(c, fd);
	// 	if (i == -1)
	// 		return (-1);
	// }