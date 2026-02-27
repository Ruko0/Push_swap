/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:39 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	ft_stack_add_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*tmp;

	if (!lst || !new_node)
		return ;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
}

t_stack	*ft_stack_new(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = n;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	node->calcule = malloc(sizeof(t_cost));
	if (!node->calcule)
	{
		free(node);
		return (NULL);
	}
	node->calcule->cost = 0;
	node->calcule->cheapest = 0;
	node->calcule->abv_median = 0;
	node->calcule->target = NULL;
	return (node);
}

int	ft_stack_size(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	update_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		i++;
		stack = stack->next;
	}
}

void	set_prev(t_stack *a)
{
	t_stack	*prev_node;

	prev_node = NULL;
	while (a)
	{
		a->prev = prev_node;
		prev_node = a;
		a = a->next;
	}
}
