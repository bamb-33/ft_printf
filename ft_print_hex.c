/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:54:29 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 20:52:19 by naadou           ###   ########.fr       */
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

static char	*f(char *str, unsigned int n, char *hex)
{
	int	i;
	int	j;

	j = ft_len(n);
	str[j] = 0;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		i = n % 16;
		str[j - 1] = hex[i];
		n /= 16;
		j--;
	}
	return (str);
}

int	ft_print_hex(unsigned int n, int c)
{
	char	*str;
	char	*hex;
	int		i;

	if (c == 88)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	str = (char *) malloc ((ft_len(n) + 1) * sizeof(char));
	if (!str)
		return (-1);
	str = f(str, n, hex);
	i = ft_putstr_fd(str, 1);
	free (str);
	return (i);
}
