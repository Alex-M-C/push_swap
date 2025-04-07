#include "push_swap.h"

void	clear_stack(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (i < stack->size)
	{
		if (stack->items[i])
			free(stack->items[i++]);
	}
	if (stack->items)
		free(stack->items);
	free(stack);
}

void	clear_parsed(char **parsed_args)
{
	int	k;

	if (!parsed_args)
		return ;
	k = -1;
	while (parsed_args[++k])
		if (parsed_args[k])
			free(parsed_args[k]);
	free(parsed_args);
}

int	is_sorted(t_stack *stack)
{
	int	pos;

	pos = -1;
	while (++pos < stack->size - 1)
	{
		if (*stack->items[pos] > *stack->items[pos + 1])
			return (1);
	}
	return (0);
}

int	is_min(t_stack *stack)
{
	int	pos;

	pos = -1;
	while (++pos < stack->size - 1)
	{
		if (*stack->items[0] > *stack->items[pos])
			return (1);
	}
	return (0);
}

int	number_count(int argc, char **argv)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (ft_isdigit(argv[i][j]) == 1)
			{
				count++;
				while (argv[i][j] && ft_isdigit(argv[i][j]) == 1)
					j++;
			}
			else
				j++;
		}
	}
	return (count);
}
