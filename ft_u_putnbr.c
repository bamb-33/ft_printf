/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:24:22 by naadou            #+#    #+#             */
/*   Updated: 2023/11/11 20:26:53 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/naadou/Desktop/libft/libft.h"
#include "libftprintf.h"

void	ft_u_putnbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + 48;
	ft_putchar_fd(c, fd);
}