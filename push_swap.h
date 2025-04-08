
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int		**items;
	int		size;
}	t_stack;

t_stack	*init_stack(int *items, int size);

t_stack	*init_stack_empty(int size);

int		*has_duplicates(int argc, char **argv, int real_argc);

int		number_count(int argc, char **argv);

void	sort(t_stack **stack_a, t_stack **stack_b);

void	sorting(char *mode);

void	clear_stack(t_stack *stack);

void	clear_parsed(char **parsed_args);

void	stack_grow(t_stack **stack, int num);

void	stack_reduce(t_stack **stack);

int		check_format_error(const char *str);

int		is_out_of_range(const char *str);

int		is_sorted(t_stack *stack);

int		is_min(t_stack *stack);

void	swap(t_stack **stack);

void	push(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **stack);

void	reverse(t_stack **stack);

#endif
