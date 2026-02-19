/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:20:00 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/18 16:20:01 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	get_Pguts(int *i, const char *str, int *counter, va_list v_list);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_put_u_nbr_fd(unsigned int nb, int fd);
int		base_16(unsigned long n, char *base);
int		c_hex(unsigned long n);
int		c_int(int n);
int		c_Uint(unsigned int n);
int		P_print(void *b);

#endif