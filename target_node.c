/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:39 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	median_cmp(t_stack *stk, int sz)
{
	int	median;
	int	i;

	median = sz / 2;
	i = 0;
	while (stk)
	{
		if (i <= median)
			stk->calcule->abv_median = 1;
		else
			stk->calcule->abv_median = 0;
		i++;
		stk = stk->next;
	}
}

void	choose_target_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	long	best;

	while (a)
	{
		best = LONG_MIN;
		tmp = b;
		while (tmp)
		{
			if (tmp->number < a->number && tmp->number > best)
			{
				best = tmp->number;
				a->calcule->target = tmp;
			}
			tmp = tmp->next;
		}
		if (best == LONG_MIN)
			a->calcule->target = find_largest(b);
		a = a->next;
	}
}

void	choose_target_b(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	long	best;

	while (b)
	{
		best = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->number > b->number && tmp->number < best)
			{
				best = tmp->number;
				b->calcule->target = tmp;
			}
			tmp = tmp->next;
		}
		if (best == LONG_MAX)
			b->calcule->target = find_smallest(a);
		b = b->next;
	}
}
