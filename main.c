
#include "push_swap.h"
#include <stdio.h>

/* int	*has_duplicates(int size, char **argv)
{
	int	*numbers;
	int	actual_num;
	int	i;
	int	j;

	numbers = (int *)malloc(size * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	while (++i <= size)
	{
		actual_num = ft_atoi(argv[i]);
		j = 0;
		while (j + 1 < i)
		{
			if (numbers[j++] == actual_num)
				return (free(numbers), NULL);
		}
		numbers[i - 1] = actual_num;
	}
	return (numbers);
} */

//Funcion para testing, acordarse de borrar
void	print_stack(t_stack *stack)
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

/* static void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->size >= 3)
	{
		if (*(*stack_a)->items[0] < *(*stack_a)->items[2] && *(*stack_a)->items[0] < *(*stack_a)->items[1])
			push(stack_b, stack_a);
		else if (*(*stack_a)->items[0] > *(*stack_a)->items[2] && *(*stack_a)->items[0] < *(*stack_a)->items[1])
			rotate(stack_a);
		else if (*(*stack_a)->items[0] > *(*stack_a)->items[2] && *(*stack_a)->items[0] > *(*stack_a)->items[1])
			reverse(stack_a);
		else if (*(*stack_a)->items[0] < *(*stack_a)->items[2])
			swap(stack_a);
	}
	else if (*(*stack_a)->items[0] > *(*stack_a)->items[1])
		swap(stack_a);
	if (is_sorted(*stack_a) == 1)
		sort(stack_a, stack_b);
} */

int	main(int argc, char **argv)
{
	int		*numbers;
	int		real_argc;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(1);
	real_argc = number_count(argc, argv);
	if (real_argc <= 1)
		exit(1);
	numbers = has_duplicates(argc, argv, real_argc);
	if (!numbers)
		return (printf("Error\n"), 1);
	stack_a = init_stack(numbers, real_argc);
	if (!stack_a)
		return (printf("Error\n"), free(numbers), 1);
	stack_b = init_stack_empty(stack_a->size);
	if (!stack_b)
		return (printf("Error\n"), free(numbers), 1);
	//sort(&stack_a, &stack_b);
	print_stack(stack_a);
	return (clear_stack(stack_a), clear_stack(stack_b), free(numbers), 0);
}
