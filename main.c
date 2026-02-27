/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amn <amn@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 00:00:00 by amn               #+#    #+#             */
/*   Updated: 2026/02/26 19:55:40 by amn              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static void	error_exit(t_stack *a, char **matrix)
{
	if (a)
		free_stack(a);
	if (matrix)
		free_matrix(matrix);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static int	build_stack(t_stack **a, char **matrix)
{
	int	size;

	if (!input_validator(matrix))
		error_exit(NULL, matrix);
	if (!populate_stack(a, matrix))
		error_exit(*a, matrix);
	if (stack_dup_check(*a))
		error_exit(*a, matrix);
	size = ft_stack_size(*a);
	free_matrix(matrix);
	return (size);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**matrix;
	t_stack	*a;
	int		a_sz;

	if (argc < 2)
		return (0);
	str = extract_string(argv);
	if (!str)
		return (1);
	matrix = ft_split(str, ' ');
	free(str);
	if (!matrix || !matrix[0])
	{
		if (matrix)
			free_matrix(matrix);
		return (0);
	}
	a = NULL;
	a_sz = build_stack(&a, matrix);
	sort_stack(&a, &a_sz);
	free_stack(a);
	return (0);
}
