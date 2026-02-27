/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	stack_rotate(a);
	stack_rotate(b);
	write(1, "rr\n", 3);
}

void	rra(t_stack **n)
{
	stack_rev_rotate(n);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **n)
{
	stack_rev_rotate(n);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	stack_rev_rotate(a);
	stack_rev_rotate(b);
	write(1, "rrr\n", 4);
}

void	stack_push(t_stack **src, t_stack **dst, int *src_sz, int *dst_sz)
{
	t_stack	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	node->prev = NULL;
	*dst = node;
	(*src_sz)--;
	(*dst_sz)++;
}
