/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:49 by aleconst          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:50 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int		**items;
	int		size;
}	t_stack;

t_stack	*init_stack(int *items, int size);

t_stack	*init_stack_empty(int size);

int		*has_duplicates(int argc, char **argv, int real_argc);

int		number_count(int argc, char **argv);

void	turk_sort(t_stack **a, t_stack **b);

void	sorting(char *mode);

void	sort3(t_stack **a);

int		get_max(t_stack *stack);

int		get_min(t_stack *stack);

int		get_pos(t_stack *stack, int to_find);

void	move_to_start(t_stack **stack, int pos, int ab);

void	double_move_to_start(t_stack **a, t_stack **b, int pos_a, int pos_b);

int		find_target(t_stack **b, int associated, int max_b);

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
