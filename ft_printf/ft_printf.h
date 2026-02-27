/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:20:00 by otkibou           #+#    #+#             */
/*   Updated: 2026/02/26 19:55:39 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	get_pguts(int *i, const char *str, int *counter, va_list v_list);
int		ft_printf(const char *str, ...);
int		pf_putchar_fd(char c, int fd);
int		pf_putstr_fd(char *s, int fd);
int		pf_putnbr_fd(int n, int fd);
int		pf_put_u_nbr_fd(unsigned int nb, int fd);
int		base_16(unsigned long n, char *base);
int		c_hex(unsigned long n);
int		c_int(int n);
int		c_uint(unsigned int n);
int		p_print(void *b);

#endif