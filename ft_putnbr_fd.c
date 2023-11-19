/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:57:56 by naadou            #+#    #+#             */
/*   Updated: 2023/11/19 20:53:50 by naadou           ###   ########.fr       */
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

static char	*f(char *str, int n, int j)
{
	int	i;

	j += ft_len(n);
	str[j] = 0;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		i = (n % 10) + 48;
		str[j - 1] = i;
		n /= 10;
		j--;
	}
	return (str);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		str = (char *) malloc ((ft_len(n) + 2) * sizeof(char));
		if (!str)
			return (-1);
		str[0] = '-';
		n *= -1;
		j++;
	}
	else
		str = (char *) malloc ((ft_len(n) + 1) * sizeof(char));
	if (!str)
		return (-1);
	str = f(str, n, j);
	i = ft_putstr_fd(str, fd);
	free (str);
	return (i);
}