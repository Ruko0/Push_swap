/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:20:12 by otkibou           #+#    #+#             */
/*   Updated: 2026/02/26 19:22:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbr_fd(int n, int fd)
{
	int			bomba9la;
	int long	nb;

	bomba9la = c_int(n);
	nb = n;
	if (nb < 0)
	{
		pf_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		pf_putnbr_fd(nb / 10, fd);
	}
	pf_putchar_fd(nb % 10 + '0', fd);
	return (bomba9la);
}
