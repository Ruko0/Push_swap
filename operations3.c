/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	pa(t_stack **a, t_stack **b, int *a_sz, int *b_sz)
{
	stack_push(b, a, b_sz, a_sz);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int *a_sz, int *b_sz)
{
	stack_push(a, b, a_sz, b_sz);
	write(1, "pb\n", 3);
}
