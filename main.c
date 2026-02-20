#include "Push_swap.h"

/*
In case of error, it must display "Error" followed by an ’\n’ on the standard error.
Errors include, for example: some arguments not being integers, some arguments
exceeding the integer limits, and/or the presence of duplicates.
*/

void print_matrix(char ** mtx)
{
	int i = 0;
	while (mtx[i])
		printf("%s\n", mtx[i++]);
}

void print_stack(t_stack *A)
{
	t_stack *tmp = A;
	while(tmp)
	{
		printf("%d\n", tmp->number);
		tmp = tmp->next;
	}
}

void free_matrix(char ** matrix)
{
	int i = 0;
	while(matrix[i])
		free(matrix[i++]);
	free(matrix);
}

// allocation handling !!
int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	//join all argvs with space padding
	char *new = NULL;
	new = extract_string(argv);
	if (!new)
		return ft_putendl_fd("Error1\n", 2), 1;
	//split with spaces
	char **matrix = ft_split(new, ' ');
	if (!matrix || !matrix[0])
		return ft_putendl_fd("Error2\n", 2), 1;
	// //none digits
	free(new);
	if (!input_validator(matrix))
		return ft_putendl_fd("Error3\n", 2), 1;
	// //stack population and (overflow handle)
	t_stack *A;
	if (!populate_stack(&A, matrix))
		return ft_putendl_fd("Error4\n", 2), 1;
	// (duplicates)
	free_matrix(matrix);
	if (!stack_dup_check(A))
		return ft_putendl_fd("Error5\n", 2), 1;
	set_prev(A);
	// printf("before\n");
	// print_stack(A);
	
	// printf("after\n");
	// print_stack(A);

}
