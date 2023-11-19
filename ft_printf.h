/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:00:59 by naadou            #+#    #+#             */
/*   Updated: 2023/11/19 11:59:31 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

int				ft_print_hex(unsigned int n, int c);
int				ft_printadd(void *p);
int				ft_printf(const char *s, ...);
int				ft_putchar_fd(char c, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned int	ft_u_putnbr_fd(unsigned int n, int fd);

#endif