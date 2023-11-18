/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:56:13 by marvin            #+#    #+#             */
/*   Updated: 2023/11/18 21:56:19 by marvin           ###   ########.fr       */
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
	write (fd, &c, sizeof(char));
	return (1);
}
