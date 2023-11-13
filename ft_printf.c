/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:23:10 by naadou            #+#    #+#             */
/*   Updated: 2023/11/13 12:51:30 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (ft_strncmp(&s[i], "%c", 2) == 0)
			ft_putchar_fd(va_arg(args, int), 1);
		else if (ft_strncmp(&s[i], "%s", 2) == 0)
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (ft_strncmp(&s[i], "%p", 2) == 0)
			ft_printadd(va_arg(args, void *));
		else if (ft_strncmp(&s[i], "%d", 2) == 0)
			ft_putnbr_fd(va_arg(args, int), 1);
		else if (ft_strncmp(&s[i], "%i", 2) == 0)
			ft_putnbr_fd(va_arg(args, int), 1);
		else if (ft_strncmp(&s[i], "%u", 2) == 0)
			ft_u_putnbr_fd(va_arg(args, unsigned int), 1);
		else if (ft_strncmp(&s[i], "%x", 2) == 0)
			ft_print_hex_lc(va_arg(args, int));
		else if (ft_strncmp(&s[i], "%X", 2) == 0)
			ft_print_hex_uc(va_arg(args, int));
		else if (ft_strncmp(&s[i], "%%", 2) == 0)
			ft_putchar_fd('%', 1);
		else
		{
			ft_putchar_fd(s[i], 1);
			i++;
			continue ;
		}
		i += 2;
	}
	va_end(args);
	return (0);
}

// int main()
// {
// 	int a = 10;
// 	ft_printf("it fucking worked let's go :%p", &a);
// }

//cc ft_printf.c ft_print_hex_lc.c ft_print_hex_uc.c ft_printadd.c ft_u_putnbr.c /Users/naadou/Desktop/libft/ft_putchar_fd.c /Users/naadou/Desktop/libft/ft_putnbr_fd.c /Users/naadou/Desktop/libft/ft_putstr_fd.c /Users/naadou/Desktop/libft/ft_strlen.c /Users/naadou/Desktop/libft/ft_strncmp.c