/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:17:29 by naadou            #+#    #+#             */
/*   Updated: 2023/11/11 20:21:52 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/naadou/Desktop/libft/libft.h"
#include "libftprintf.h"

static size_t	ft_len(unsigned long n)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i + 2);
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

void	ft_printadd(void *p)
{
	int				i;
	int				j;
	unsigned long	add;
	char			*str;
	char			hex[17];

	add = (unsigned long) p;
	str = (char *) malloc ((ft_len(add) + 1) * sizeof(char));
	hexstring(hex);
	j = ft_len(add);
	str[j] = 0;
	while (add)
	{
		i = add % 16;
		str[j - 1] = hex[i];
		add /= 16;
		j--;
	}
	str[j -1] = 'x';
	j--;
	str[j - 1] = 48;
	ft_putstr_fd(str, 1);
}