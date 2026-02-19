/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:18:19 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/06 16:30:43 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	x;

	len = ft_strlen(s);
	x = (char)c;
	while ((len + 1) > 0)
	{
		if (s[len] == x)
		{
			return ((char *)&s[len]);
		}
		len--;
	}
	return (NULL);
}
