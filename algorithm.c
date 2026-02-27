/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:39 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

bool	stack_is_sorted(t_stack *stk)
{
	while (stk && stk->next)
	{
		if (stk->number > stk->next->number)
			return (false);
		stk = stk->next;
	}
	return (true);
}

void	sort_three(t_stack **stk)
{
	t_stack	*max;

	max = find_largest(*stk);
	if (*stk == max)
		ra(stk);
	else if ((*stk)->next == max)
		rra(stk);
	if ((*stk)->number > (*stk)->next->number)
		sa(*stk);
}

void	fix_sorted_stack(t_stack **stk)
{
	t_stack	*min;

	min = find_smallest(*stk);
	while (*stk != min)
	{
		if (min->calcule->abv_median)
			ra(stk);
		else
			rra(stk);
	}
}

static void	big_sort(t_stack **a, t_stack **b, int *a_sz, int *b_sz)
{
	pb(a, b, a_sz, b_sz);
	if (*a_sz > 3)
		pb(a, b, a_sz, b_sz);
	while (*a_sz > 3)
	{
		initialize_nodes_a(*a, *b, *a_sz, *b_sz);
		move_a_to_b(a, b, a_sz, b_sz);
	}
	sort_three(a);
	while (*b_sz > 0)
	{
		initialize_nodes_b(*a, *b, *a_sz, *b_sz);
		move_b_to_a(a, b, a_sz, b_sz);
	}
	update_index(*a);
	median_cmp(*a, *a_sz);
	fix_sorted_stack(a);
}

void	sort_stack(t_stack **a, int *a_sz)
{
	t_stack	*b;
	int		b_sz;

	b = NULL;
	b_sz = 0;
	if (*a_sz <= 1 || stack_is_sorted(*a))
		return ;
	if (*a_sz == 2)
	{
		sa(*a);
		return ;
	}
	if (*a_sz == 3)
	{
		sort_three(a);
		return ;
	}
	big_sort(a, &b, a_sz, &b_sz);
}
