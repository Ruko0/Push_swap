#include "Push_swap.h"

char *extract_string(char **argv)
{
	char *result = "";
	int i = 1;

	while (argv[i])
	{
		result = ft_strjoin(result, argv[i]);
		result = ft_strjoin(result, " ");
		i++;
	}
	return result;
}

bool check_comp(char *str)
{
	bool a = false;
	bool b = false;
	int i = 0;

	if (str[0] == '+' || str[0] == '-')
	{
		a = true;
		i++;
	}
	while (str[i])
	{
		b = true;
		if (!ft_isdigit(str[i]))
			return false;
		i++;
	}
	if ((a && b) || (b))
		return true;
	return false;
}

bool input_validator(char **matrix)
{
	int i = 0;
	while (matrix[i])
	{
		if (!check_comp(matrix[i]))
			return false;
		i++;
	}
	return true;
}
