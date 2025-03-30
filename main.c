
#include "push_swap.h"
#include <stdio.h>

int	*has_duplicates(int size, char **argv)
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
}

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

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = init_stack_empty((*stack_a)->size);
	if (!stack_b)
		return ;
	push(&stack_b, stack_a);
	swap(stack_a);
	print_stack(stack_b);
}

int	main(int argc, char **argv)
{
	int		i;
	int		*numbers;
	t_stack	*stack_a;

	if (argc < 2)
		exit(1);
	else if (argc < 3)
		return (printf("Error\n"), 1);
	i = 0;
	numbers = NULL;
	while (++i < argc)
	{
		if (check_format_error(argv[i]) == 1 || is_out_of_range(argv[i]) == 1)
			return (printf("Error\n"), 1);
	}
	numbers = has_duplicates(argc - 1, argv);
	if (!numbers)
		return (printf("Error\n"), 1);
	stack_a = init_stack(numbers, argc - 1);
	if (!stack_a)
		return (printf("Error\n"), free(numbers), 1);
	sort(&stack_a);
	print_stack(stack_a);
	return (clear_stack(stack_a), free(numbers), 0);
}
