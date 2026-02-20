#include "Push_swap.h"

void stack_swap(t_stack *n)
{
	if (n->size == 1)
		return;
	int tmp = n->number;
	n->number = n->next->number;
	n->next->number = tmp;
}

void sa(t_stack *n)
{
	stack_swap(n);
	printf("sa\n");
}

void sb(t_stack *n)
{
	stack_swap(n);
	printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	printf("ss\n");
}

void detach_node(t_stack **stack, t_stack *n, bool free)
{
	t_stack *tmp = *stack;
	while(tmp)
	{
		if (tmp->number == n->number)
		tmp= tmp->next;
	}
}

void stack_rotate(t_stack *n)
{
	t_stack *tmp1;
	t_stack *tmp2;

	  
}
void ra(t_stack *n)
{
	stack_rotate(n);
	printf("ra\n");
}

void rb(t_stack *n)
{
	stack_rotate(n);
	printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_swap(b);
	printf("rr\n");
}
