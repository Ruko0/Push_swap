/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:33:17 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/09 23:58:09 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	s_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	i = d_len;
	j = 0;
	if (d_len >= dstsize)
	{
		return (dstsize + s_len);
	}
	while (src[j] && j < dstsize - d_len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + s_len);
}
