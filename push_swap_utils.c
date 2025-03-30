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
	free(stack->items);
	free(stack);
}
