#include "push_swap.h"

//Funcion para testing, acordarse de borrar
static void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		printf("Pos [%i]: %i\n", i, *(stack->items)[i]);
		i++;
	}
	printf("\n");
}

static int	*min_poss(t_stack *stack_a)
{
	int	*mins;
	int	i;

	mins = (int *)malloc(2 * sizeof(int));
	if (!mins)
		return (NULL);
	i = 2;
	mins[0] = 0;
	mins[1] = 1;
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

void	move_min(t_stack **stack_a, int pos, int *pos2)
{
	while (pos > 0)
	{
		if (pos <= (*stack_a)->size / 2)
		{
			rotate(stack_a);
			sorting("13");
			pos--;
			*pos2 -= 1;
			if (*pos2 < 0)
				*pos2 = (*stack_a)->size - 1;
		}
		else if (pos > (*stack_a)->size / 2)
		{
			reverse(stack_a);
			sorting("14");
			pos++;
			*pos2 += 1;
			if (pos >= (*stack_a)->size)
				pos = 0;
			if (*pos2 >= (*stack_a)->size)
				*pos2 = 0;
		}
	}
	*pos2 -= 1;
}

void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->size > 0)
	{
		if ((*stack_b)->size >= 2 && *(*stack_b)->items[0] < *(*stack_b)->items[1])
		{
			swap(stack_b);
			sorting("21");
			push(stack_a, stack_b);
			sorting("12");
		}
		push(stack_a, stack_b);
		sorting("12");
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	*mins;
	int	mins_pos;
	int	diff;

	mins_pos = 2;
	while ((*stack_a)->size > 2)
	{
		if (mins_pos == 2)
		{
			mins = min_poss(*stack_a);
			mins_pos = 0;
			diff = 0;
		}
		if (!mins)
			return ;
		move_min(stack_a, mins[mins_pos++], &mins[1]);
		push(stack_b, stack_a);
		sorting("22");
	}
	if ((*stack_a)->size == 2 && *(*stack_a)->items[0] > *(*stack_a)->items[1])
	{
		swap(stack_a);
		sorting("11");
	}
	return (free(mins), move_to_a(stack_a, stack_b));
}
