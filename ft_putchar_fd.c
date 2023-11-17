/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:42:55 by naadou            #+#    #+#             */
/*   Updated: 2023/11/16 22:15:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	i;
	
	if (fd < 0)
		return (0);
	i = write (fd, &c, sizeof(char));
	if (i == -1)
		return (-1);
	return (1);
}
