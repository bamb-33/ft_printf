/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:10 by naadou            #+#    #+#             */
/*   Updated: 2023/11/11 13:13:59 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "~/Desktop/libft/libft.h"
#include <stdarg.h> 

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (ft_strncmp(s[i], "%c", 2) == 0)
			ft_putchar_fd(va_arg(args, char), 1);
		else if (ft_strncmp(s[i], "%s", 2) == 0)
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (ft_strncmp(s[i], "%p", 2) == 0)
			ft_printhex(va_arg(args, void *));
	}
}