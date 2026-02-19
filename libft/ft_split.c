/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otkibou <otkibou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:32:54 by otkibou           #+#    #+#             */
/*   Updated: 2025/11/10 06:06:08 by otkibou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mt(char **arr, int last_idx)
{
	while (last_idx >= 0)
	{
		free(arr[last_idx]);
		last_idx--;
	}
	free(arr);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static unsigned int	true_len(const char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**pp(char const *str, char c, char **tablo)
{
	int				i;
	int				j;
	unsigned int	next_word;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			next_word = true_len(&str[i], c);
			tablo[j++] = ft_substr(str, i, next_word);
			if (!tablo[j - 1])
			{
				return (mt(tablo, j - 1), NULL);
			}
			i += next_word;
		}
	}
	tablo[j] = NULL;
	return (tablo);
}

char	**ft_split(const char *s, char c)
{
	char	**tablo;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c) + 1;
	tablo = malloc(sizeof(char *) * words);
	if (!tablo)
		return (NULL);
	tablo = pp(s, c, tablo);
	return (tablo);
}
