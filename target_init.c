/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

static int	compute_cost(t_stack *node, int src_sz, int dst_sz)
{
	int	cost_a;
	int	cost_b;

	if (node->calcule->abv_median)
		cost_a = node->index;
	else
		cost_a = src_sz - node->index;
	if (node->calcule->target->calcule->abv_median)
		cost_b = node->calcule->target->index;
	else
		cost_b = dst_sz - node->calcule->target->index;
	if (node->calcule->abv_median
		== node->calcule->target->calcule->abv_median)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

static void	calc_costs(t_stack *src, int src_sz, int dst_sz)
{
	t_stack	*cheapest;

	cheapest = src;
	while (src)
	{
		src->calcule->cost = compute_cost(src, src_sz, dst_sz);
		src->calcule->cheapest = 0;
		if (src->calcule->cost < cheapest->calcule->cost)
			cheapest = src;
		src = src->next;
	}
	cheapest->calcule->cheapest = 1;
}

void	initialize_nodes_a(t_stack *a, t_stack *b, int a_sz, int b_sz)
{
	update_index(a);
	update_index(b);
	median_cmp(a, a_sz);
	median_cmp(b, b_sz);
	set_prev(a);
	set_prev(b);
	choose_target_a(a, b);
	calc_costs(a, a_sz, b_sz);
}

void	initialize_nodes_b(t_stack *a, t_stack *b, int a_sz, int b_sz)
{
	update_index(a);
	update_index(b);
	median_cmp(a, a_sz);
	median_cmp(b, b_sz);
	set_prev(a);
	set_prev(b);
	choose_target_b(a, b);
	calc_costs(b, b_sz, a_sz);
}
