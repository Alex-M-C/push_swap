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

	pos = 0;
	while (pos < stack->size - 1)
	{
		if (*stack->items[pos] > *stack->items[pos + 1])
			return (1);
	}
	return (0);
}
