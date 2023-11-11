/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:00:59 by naadou            #+#    #+#             */
/*   Updated: 2023/11/11 20:00:54 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "/Users/naadou/Desktop/libft/libft.h"
# include <stdarg.h> 
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

void	ft_print_hex_uc(int n);
void	ft_print_hex_lc(int n);
void	*ft_printadd(void *p);

#endif