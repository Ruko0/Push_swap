/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:39 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	sa(t_stack *n)
{
	stack_swap(n);
	write(1, "sa\n", 3);
}

void	sb(t_stack *n)
{
	stack_swap(n);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	write(1, "ss\n", 3);
}

void	ra(t_stack **n)
{
	stack_rotate(n);
	write(1, "ra\n", 3);
}

void	rb(t_stack **n)
{
	stack_rotate(n);
	write(1, "rb\n", 3);
}
