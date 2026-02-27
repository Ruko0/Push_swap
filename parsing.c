/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:39 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static char	*join_free(char *s1, char *s2)
{
	char	*out;

	out = ft_strjoin(s1, s2);
	free(s1);
	return (out);
}

char	*extract_string(char **argv)
{
	char	*result;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 1;
	while (argv[i] && result)
	{
		result = join_free(result, argv[i]);
		if (result && argv[i + 1])
			result = join_free(result, " ");
		i++;
	}
	return (result);
}

bool	check_comp(char *str)
{
	int		i;
	bool	has_digit;

	i = 0;
	has_digit = false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		has_digit = true;
		i++;
	}
	return (has_digit);
}

bool	input_validator(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (!check_comp(matrix[i]))
			return (false);
		i++;
	}
	return (true);
}
