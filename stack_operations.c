#include "Push_swap.h"

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*tp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tp = *lst;
	while (tp->next != NULL)
	{
		tp = tp->next;
	}
	tp->next = new;
}

t_stack	*ft_stack_new(int n)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = n;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_num valid_extract(char *str)
{
	t_num no;
	no.i = 0;
	no.nb = 0;
	no.s = 1;
	while ((str[no.i] >= 9 && str[no.i] <= 13) || str[no.i] == 32)
		no.i++;
	if (str[no.i] == '-' || str[no.i] == '+')
	{
		if (str[no.i] == '-')
			no.s = -1;
		(no.i)++;
	}
	while (str[no.i] >= '0' && str[no.i] <= '9')
	{
		no.nb = no.nb * 10 + (str[no.i] - '0');
		if ((no.s == 1  && no.nb > INT32_MAX)|| (no.s == -1  && no.nb > 2147483648))
			return (no.valid = false, no);
		(no.i)++;
	}
	no.nb = no.nb * no.s;
	return (no.valid = true, no);
}

void reset_num(t_num num)
{
	num.i = 0;
	num.nb = 0;
	num.s = 0;
	num.valid = false;
}

int	ft_stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

bool populate_stack(t_stack **A, char **matrix)
{
	int i = 0;
	t_num num;
	while (matrix[i])
	{
		num = valid_extract(matrix[i]);
		if (num.valid)
			ft_stack_add_back(A, ft_stack_new((int)num.nb));
		else
			return false;
		reset_num(num);
		i++;
	}
	(*A)->size = ft_stack_size(*A);
	return true;
}

bool stack_dup_check(t_stack *A)
{
	t_stack *tmp1 = A;
	t_stack *tmp2;
	while(tmp1)
	{
		tmp2 = tmp1->next;
		while(tmp2)
		{
			if (tmp1->number == tmp2->number)
				return false;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return true;
}

void set_prev(t_stack *A)
{
	t_stack *tmp1 = A;
	t_stack *tmp2;

	while (tmp1)
	{
		tmp2 = tmp1->next;
		if (tmp2)
			tmp2->prev = tmp1;
		tmp1 = tmp1->next;
	}
}
// [0,1,2,3,4,5,6,7]
// cmp[0] -> [end]
// cmp[next] -> cmp[]