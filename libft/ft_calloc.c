/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:31:58 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/10 04:36:17 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*hada;

	total = count * size;
	if (size != 0 && (total / size != count))
		return (NULL);
	hada = malloc(count * size);
	if (!hada)
		return (NULL);
	ft_bzero(hada, count * size);
	return (hada);
}
