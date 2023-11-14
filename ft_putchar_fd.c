/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:42:55 by naadou            #+#    #+#             */
/*   Updated: 2023/11/14 15:44:32 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write (fd, &c, sizeof(char));
	return (1);
}
