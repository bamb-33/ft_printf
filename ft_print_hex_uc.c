/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:56:06 by naadou            #+#    #+#             */
/*   Updated: 2023/11/11 20:21:48 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/naadou/Desktop/libft/libft.h"
#include "libftprintf.h"

static size_t	ft_len(int n)
{
	size_t	i;

	i = 0;
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
			j = 65;
		str[i] = j;
		i++;
		j++;
	}
	str[i] = 0;
}

void	ft_print_hex_uc(int n)
{
	char	*str;
	char	hex[17];
	int		i;
	int		j;

	hexstring(hex);
	str = (char *) malloc ((ft_len(n) + 1) * sizeof(char));
	j = ft_len(n);
	str[j] = 0;
	while (n)
	{
		i = n % 16;
		str[j - 1] = hex[i];
		n /= 16;
		j--;
	}
	ft_putstr_fd(str, 1);
}
