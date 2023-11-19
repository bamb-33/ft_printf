/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:17:29 by naadou            #+#    #+#             */
/*   Updated: 2023/11/19 20:34:31 by naadou           ###   ########.fr       */
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

static char	*f(char *str, unsigned long n, char *hex)
{
	int	i;
	int	j;

	j = ft_len(n) + 2;
	str[j] = 0;
	if (n == 0)
		str[2] = '0';
	while (n)
	{
		i = n % 16;
		str[j - 1] = hex[i];
		n /= 16;
		j--;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

int	ft_printadd(void *p)
{
	char				*str;
	char				*hex;
	unsigned long int	n;
	int					i;

	hex = "0123456789abcdef";
	n = (unsigned long int) p;
	str = (char *) malloc ((ft_len(n) + 3) * sizeof(char));
	if (!str)
		return (-1);
	str = f(str, n, hex);
	i = ft_putstr_fd(str, 1);
	free (str);
	return (i);
}
