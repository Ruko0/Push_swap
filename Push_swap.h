#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
// #include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_num
{
	long	nb;
	int 	i;
	int		s;
	bool 	valid;
}t_num;

typedef struct s_stack
{
	int number;
	int size;
	struct s_stack *prev;
	struct s_stack *next;
}t_stack;

char *extract_string(char ** argv);
bool input_validator(char **argv);
bool populate_stack(t_stack **A, char **matrix);
bool stack_dup_check(t_stack *A);
void set_prev(t_stack *A);


//operations

void sb(t_stack *n);
void sa(t_stack *n);
void ss(t_stack *a, t_stack *b);

#endif