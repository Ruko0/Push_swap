/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:39 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_num
{
	long	nb;
	int		i;
	int		s;
	bool	valid;
}	t_num;

typedef struct s_cost
{
	int				cost;
	int				cheapest;
	int				abv_median;
	struct s_stack	*target;
}	t_cost;

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_cost	*calcule;
}	t_stack;

/* parsing.c */
char	*extract_string(char **argv);
bool	check_comp(char *str);
bool	input_validator(char **matrix);

/* stack_operations.c */
void	ft_stack_add_back(t_stack **lst, t_stack *new_node);
t_stack	*ft_stack_new(int n);
int		ft_stack_size(t_stack *lst);
void	update_index(t_stack *stack);
void	set_prev(t_stack *a);

/* stack_utils.c */
t_num	valid_extract(char *str);
bool	populate_stack(t_stack **a, char **matrix);
bool	stack_dup_check(t_stack *a);
t_stack	*find_largest(t_stack *stk);
t_stack	*find_smallest(t_stack *stk);

/* stack_init.c */
void	stack_swap(t_stack *n);
void	stack_rotate(t_stack **n);
void	stack_rev_rotate(t_stack **n);

/* operations.c */
void	sa(t_stack *n);
void	sb(t_stack *n);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack **n);
void	rb(t_stack **n);

/* operations2.c */
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **n);
void	rrb(t_stack **n);
void	rrr(t_stack **a, t_stack **b);
void	stack_push(t_stack **src, t_stack **dst, int *src_sz, int *dst_sz);

/* operations3.c */
void	pa(t_stack **a, t_stack **b, int *a_sz, int *b_sz);
void	pb(t_stack **a, t_stack **b, int *a_sz, int *b_sz);

/* algorithm.c */
bool	stack_is_sorted(t_stack *stk);
void	sort_three(t_stack **stk);
void	fix_sorted_stack(t_stack **stk);
void	sort_stack(t_stack **a, int *a_sz);

/* target_node.c */
void	median_cmp(t_stack *stk, int sz);
void	choose_target_a(t_stack *a, t_stack *b);
void	choose_target_b(t_stack *a, t_stack *b);

/* target_init.c */
void	initialize_nodes_a(t_stack *a, t_stack *b, int a_sz, int b_sz);
void	initialize_nodes_b(t_stack *a, t_stack *b, int a_sz, int b_sz);

/* moves.c */
void	move_a_to_b(t_stack **a, t_stack **b, int *a_sz, int *b_sz);
void	move_b_to_a(t_stack **a, t_stack **b, int *a_sz, int *b_sz);
void	free_stack(t_stack *stk);

/* main.c */
void	free_matrix(char **matrix);

#endif
