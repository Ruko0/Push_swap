#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
// #include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_stack
{
	int number;
	//
	struct s_stack *next;
}t_stack;

char *extract_string(char ** argv);
bool input_validator(char **argv);

#endif