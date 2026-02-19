/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:33:45 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/11 05:46:35 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	l = ft_strlen(needle);
	while (len >= l && *haystack)
	{
		if (!ft_strncmp(haystack, needle, l))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
