/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static t_stack	*find_cheapest(t_stack *stk)
{
	while (stk)
	{
		if (stk->calcule->cheapest)
			return (stk);
		stk = stk->next;
	}
	return (NULL);
}

static void	align_both(t_stack **a, t_stack **b, t_stack *node)
{
	while (node != *a && node->calcule->target != *b)
	{
		if (node->calcule->abv_median
			&& node->calcule->target->calcule->abv_median)
			rr(a, b);
		else if (!node->calcule->abv_median
			&& !node->calcule->target->calcule->abv_median)
			rrr(a, b);
		else
			break ;
	}
}

void	move_a_to_b(t_stack **a, t_stack **b, int *a_sz, int *b_sz)
{
	t_stack	*node;

	node = find_cheapest(*a);
	align_both(a, b, node);
	while (node != *a)
	{
		if (node->calcule->abv_median)
			ra(a);
		else
			rra(a);
	}
	while (node->calcule->target != *b)
	{
		if (node->calcule->target->calcule->abv_median)
			rb(b);
		else
			rrb(b);
	}
	pb(a, b, a_sz, b_sz);
}

void	move_b_to_a(t_stack **a, t_stack **b, int *a_sz, int *b_sz)
{
	t_stack	*node;

	node = (*b)->calcule->target;
	while (node != *a)
	{
		if (node->calcule->abv_median)
			ra(a);
		else
			rra(a);
	}
	pa(a, b, a_sz, b_sz);
}

void	free_stack(t_stack *stk)
{
	t_stack	*tmp;

	while (stk)
	{
		tmp = stk;
		stk = stk->next;
		if (tmp->calcule)
			free(tmp->calcule);
		free(tmp);
	}
}
