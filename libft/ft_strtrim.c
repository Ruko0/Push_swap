/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:33:52 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/11 05:31:04 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcul(const char *set, const char *s1, size_t suf)
{
	int	counter;

	counter = 0;
	while (suf != 0)
	{
		if (!ft_strchr(set, s1[suf - 1]))
			break ;
		counter++;
		suf--;
	}
	return (counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		pref;
	size_t	suf;
	int		counter;
	char	*new;

	pref = 0;
	suf = ft_strlen(s1);
	counter = 0;
	while (s1[pref])
	{
		if (!ft_strchr(set, s1[pref]))
			break ;
		pref++;
	}
	counter = calcul(set, s1, suf);
	new = ft_substr(s1, pref, ft_strlen(s1) - (counter + pref));
	return (new);
}
