/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	stack_swap(t_stack *n)
{
	int	tmp;

	if (!n || !n->next)
		return ;
	tmp = n->number;
	n->number = n->next->number;
	n->next->number = tmp;
}

void	stack_rotate(t_stack **n)
{
	t_stack	*first;
	t_stack	*last;

	if (!n || !*n || !(*n)->next)
		return ;
	first = *n;
	last = *n;
	while (last->next)
		last = last->next;
	*n = first->next;
	(*n)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	stack_rev_rotate(t_stack **n)
{
	t_stack	*last;

	if (!n || !*n || !(*n)->next)
		return ;
	last = *n;
	while (last->next)
		last = last->next;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *n;
	(*n)->prev = last;
	*n = last;
}
