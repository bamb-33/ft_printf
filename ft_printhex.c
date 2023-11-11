/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:17:29 by naadou            #+#    #+#             */
/*   Updated: 2023/11/11 17:56:28 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/naadou/Desktop/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

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

void	ft_printhex(void *p)
{
	int				i;
	int				j;
	unsigned long	add;
	char			*str;
	char			hex[17];

	add = (unsigned long) p;
	str = (char *) malloc ((ft_len(add) + 1) * sizeof(char));
	i = 0;
	j = 48;
	while (i < 16)
	{
		if (j == 58)
			j = 97;
		hex[i] = j;
		i++;
		j++;
	}
	hex[i] = 0;
	j = ft_len(add);
	str[j] = 0;
	while (add)
	{
		i = add % 16;
		str[j - 1] = hex[i];
		add /= 16;
		j--;
	}
	j--;
	str[j] = 'x';
	j--;
	str[j] = 48;
	ft_putendl_fd(str, 1);
}