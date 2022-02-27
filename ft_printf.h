/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:01:21 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 21:07:05 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef STD_FD
#  define STD_FD 1
# endif

int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
size_t	ft_nbrlen(long long n, int is_signed, int base);

int		ft_putchar(int fd, int c);
int		ft_putstr(int fd, const char *str);
int		ft_putnbr(int fd, long long n, int is_signed, char *base);
int		ft_putptr(int fd, unsigned long n);

int		ft_printf(const char *format, ...);

#endif
