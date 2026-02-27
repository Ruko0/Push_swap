/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:19:42 by otkibou           #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	v_list;
	int		i;
	int		counter;

	va_start(v_list, str);
	i = 0;
	counter = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (str[i])
	{
		if (str[i] != '%')
			counter += pf_putchar_fd(str[i], 1);
		else
			get_pguts(&i, str, &counter, v_list);
		i++;
	}
	va_end(v_list);
	return (counter);
}
