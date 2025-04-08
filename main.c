#include "push_swap.h"

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
	sort(&stack_a, &stack_b);
	print_stack(stack_a);
	return (clear_stack(stack_a), clear_stack(stack_b), free(numbers), 0);
}
