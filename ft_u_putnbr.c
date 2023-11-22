/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:24:22 by naadou            #+#    #+#             */
/*   Updated: 2023/11/22 14:07:40 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long n)
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

unsigned long	ft_u_putnbr_fd(unsigned long n, int fd)
{
	char	*str;
	int		i;
	int		j;

	str = (char *) malloc ((ft_len(n) + 1) * sizeof(char));
	if (!str)
		return (-1);
	j = ft_len(n);
	i = ft_len(n);
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
	i = ft_putstr_fd(str, fd);
	free (str);
	return (i);
}
