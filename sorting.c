#include "push_swap.h"

static int	*min_poss(t_stack *stack_a)
{
	int	*mins;
	int	i;

	mins = (int *)malloc(2 * sizeof(int));
	if (!mins)
		return (NULL);
	i = 1;
	mins[0] = 0;
	mins[1] = 0;
	while (i < stack_a->size)
	{
		if (*stack_a->items[i] < *stack_a->items[mins[0]])
			mins[0] = i;
		if (*stack_a->items[i] < *stack_a->items[mins[1]]
			&& *stack_a->items[mins[0]] != *stack_a->items[i])
			mins[1] = i;
		i++;
	}
	return (mins);
}

void	move_min(t_stack **stack_a, int pos)
{
	while (pos > 0)
	{
		if (pos <= (*stack_a)->size / 2)
		{
			rotate(stack_a);
			sorting("13");
			pos--;
		}
		else if (pos > (*stack_a)->size / 2)
		{
			reverse(stack_a);
			sorting("14");
			pos++;
			if (pos >= (*stack_a)->size)
				pos = 0;
		}
	}
}

void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->size > 0)
	{
		reverse(stack_b); //In the optimezed version remove this line
		if (*(*stack_b)->items[0] > *(*stack_b)->items[1])
			swap(stack_b);
		push(stack_a, stack_b);
		push(stack_a, stack_b);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	*mins;
	int	i;

	i = 0;
	while ((*stack_a)->size > 1)
	{
		mins = min_poss(*stack_a);
		if (!mins)
			return ;
		move_min(stack_a, mins[0]);		//In the optimezed version swap this move_min with the below one
		push(stack_b, stack_a);
		move_min(stack_a, mins[1] - 1);	//In the optimezed version swap this move_min with the above one
		push(stack_b, stack_a);
		if ((*stack_b)->size > 2) //In the optimezed version remove this entire if
		{
			rotate(stack_b);
		}
	}
	move_to_a(stack_a, stack_b);
}
