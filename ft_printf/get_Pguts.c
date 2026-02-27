/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_Pguts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:20:26 by otkibou           #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_pguts(int *i, const char *str, int *counter, va_list v_list)
{
	(*i)++;
	if (str[*i] == 'i' || str[*i] == 'd')
		*counter += pf_putnbr_fd(va_arg(v_list, int), 1);
	else if (str[*i] == 's')
		*counter += pf_putstr_fd(va_arg(v_list, char *), 1);
	else if (str[*i] == 'c')
		*counter += pf_putchar_fd(va_arg(v_list, int), 1);
	else if (str[*i] == 'u')
		*counter += pf_put_u_nbr_fd((unsigned int)va_arg(v_list, unsigned int),
				1);
	else if (str[*i] == 'p')
		*counter += p_print(va_arg(v_list, void *));
	else if (str[*i] == 'x')
		*counter += base_16(va_arg(v_list, unsigned int), "0123456789abcdef");
	else if (str[*i] == 'X')
		*counter += base_16(va_arg(v_list, unsigned int), "0123456789ABCDEF");
	else if (str[*i] == '%')
		*counter += pf_putchar_fd('%', 1);
}
