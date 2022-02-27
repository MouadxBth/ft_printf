/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 19:01:21 by mbouthai          #+#    #+#             */
/*   Updated: 2022/02/27 23:19:52 by mbouthai         ###   ########.fr       */
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

typedef struct s_format {
	va_list	args;
	size_t	left_justify;
	size_t	minimum_width;
	size_t	zero_padding;
	size_t	precision;
} t_format;

int		ft_isdigit(int c);
int		ft_is_conversion(int c);

size_t	ft_strlen(const char *str);
size_t	ft_nbrlen(long long n, int is_signed, int base);

size_t	ft_repeat_print(int fd, int c, int n);

int		ft_putchar(int fd, int c);
int		ft_putstr(int fd, const char *str);
int		ft_putnbr(int fd, long long n, int is_signed, char *base);
int		ft_putptr(int fd, unsigned long n);

int		ft_handle_char(int fd, t_format *format);

t_format	*ft_new_format(void);
t_format	*ft_bzero_format(t_format *format);

int		ft_printf(const char *format, ...);

#endif
