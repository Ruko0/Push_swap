/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   P_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:20:34 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/18 16:22:28 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_print(void *b)
{
	int				i;
	unsigned long	n;

	i = 0;
	n = (unsigned long)b;
	i += ft_putstr_fd("0x", 1);
	i += base_16(n, "0123456789abcdef");
	return (i);
}
