/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

t_num	valid_extract(char *str)
{
	t_num	result;

	result.nb = 0;
	result.i = 0;
	result.s = 1;
	result.valid = true;
	if (str[result.i] == '+' || str[result.i] == '-')
	{
		if (str[result.i] == '-')
			result.s = -1;
		result.i++;
	}
	while (str[result.i])
	{
		result.nb = result.nb * 10 + (str[result.i] - '0');
		result.i++;
	}
	result.nb *= result.s;
	if (result.nb > INT_MAX || result.nb < INT_MIN)
		result.valid = false;
	return (result);
}

bool	populate_stack(t_stack **a, char **matrix)
{
	int		i;
	t_num	val;
	t_stack	*node;

	i = 0;
	while (matrix[i])
	{
		val = valid_extract(matrix[i]);
		if (!val.valid)
			return (false);
		node = ft_stack_new((int)val.nb);
		if (!node)
			return (false);
		ft_stack_add_back(a, node);
		i++;
	}
	return (true);
}

bool	stack_dup_check(t_stack *a)
{
	t_stack	*cmp;

	while (a)
	{
		cmp = a->next;
		while (cmp)
		{
			if (a->number == cmp->number)
				return (true);
			cmp = cmp->next;
		}
		a = a->next;
	}
	return (false);
}

t_stack	*find_largest(t_stack *stk)
{
	t_stack	*max;

	max = stk;
	while (stk)
	{
		if (stk->number > max->number)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

t_stack	*find_smallest(t_stack *stk)
{
	t_stack	*min;

	min = stk;
	while (stk)
	{
		if (stk->number < min->number)
			min = stk;
		stk = stk->next;
	}
	return (min);
}
