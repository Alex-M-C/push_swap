
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int		**items;
	int		top;
	int		size;
}	t_stack;

t_stack	*init_stack(int *items, int size);

t_stack	*init_stack_empty(int size);

int		*arg_type(int argc, char **argv, int real_argc);

int		*has_duplicates(int size, char **argv);

int		number_count(int argc, char **argv);

void	clear_stack(t_stack *stack);

void	stack_grow(t_stack **stack, int num);

void	stack_reduce(t_stack **stack);

int		check_format_error(const char *str);

int		is_out_of_range(const char *str);

int		is_sorted(t_stack *stack);

void	swap(t_stack **stack);

void	push(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **stack);

void	reverse(t_stack **stack);

#endif
