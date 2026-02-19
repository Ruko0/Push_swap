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

// allocation handling !!
int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	//join all argvs with space padding
	char *new = NULL;
	new = extract_string(argv);
	if (!new)
		return ft_putendl_fd("Error\n", 2), 1;
	//split with spaces
	char **matrix = ft_split(new, ' ');
	if (!matrix || !matrix[0])
		return ft_putendl_fd("Error\n", 2), 1;
	// print_matrix(matrix);
	// //none digits
	if (!input_validator(matrix))
		return ft_putendl_fd("Error3\n", 2), 1;
	printf("all good\n");
	// //stack population
	t_stack *A = NULL;
	// (duplicates, overflow)
	// //or error throw
}
