/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:55:20 by marvin            #+#    #+#             */
/*   Updated: 2023/11/22 09:39:50 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_error(int i, va_list args)
{
	if (i == -1)
	{
		va_end(args);
		return (-1);
	}
	return (1);
}

static int	print(const char *s, va_list args, int *i)
{
	int	len;

	len = 0;
	if (ft_strncmp(s, "%c", 2) == 0)
		len = ft_putchar_fd(va_arg(args, int), 1);
	else if (ft_strncmp(s, "%s", 2) == 0)
		len = ft_putstr_fd(va_arg(args, char *), 1);
	else if (ft_strncmp(s, "%p", 2) == 0)
		len = ft_printadd(va_arg(args, void *));
	else if (ft_strncmp(s, "%d", 2) == 0 || ft_strncmp(s, "%i", 2) == 0)
		len = ft_putnbr_fd(va_arg(args, int), 1);
	else if (ft_strncmp(s, "%u", 2) == 0)
		len = ft_u_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (ft_strncmp(s, "%x", 2) == 0 || ft_strncmp(s, "%X", 2) == 0)
		len = ft_print_hex(va_arg(args, int), s[1]);
	else if (ft_strncmp(s, "%%", 2) == 0)
		len = ft_putchar_fd('%', 1);
	else if (s[1])
		len = ft_putchar_fd(s[1], 1);
	if (len == -1)
		*i = -1;
	return (len - 2);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, s);
	while (s[i])
	{
		if (!s[i + 1] && s[i] == '%')
			return (i + j);
		if (s[i] == '%')
			j += print(&s[i], args, &i);
		else
		{
			if (ft_putchar_fd(s[i++], 1) == -1)
				return (-1);
			continue ;
		}
		if (read_error(i, args) == -1)
			return (-1);
		i += 2;
	}
	va_end(args);
	return (i + j);
}

	int main()
	{
		// int a = 10;
		//ft_printf("%d\n", "hello");
		printf("%d", ft_printf("%"));
		// printf("%d", printf("%"));
		//printf("%d\n", printf(NULL));
		//ft_printf("%p\n", "");
	}
