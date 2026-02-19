/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:33:57 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/10 06:10:09 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	size;
	char			*suby;
	unsigned int	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (l - start < len)
		len = l - start;
	i = 0;
	if (len > l)
		size = l + 1;
	else
		size = len + 1;
	suby = malloc(size);
	if (!suby)
		return (NULL);
	while (s[start] && i < len)
		suby[i++] = s[start++];
	suby[i] = '\0';
	return (suby);
}
