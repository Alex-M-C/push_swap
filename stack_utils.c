/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:30 by aleconst          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:32 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_empty(int size)
{
	t_stack	*stack;

	if (size <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->items = malloc(size * sizeof(int *));
	if (!stack->items)
		return (clear_stack(stack), NULL);
	stack->size = 0;
	while (--size >= 0)
	{
		stack->items[size] = NULL;
	}
	return (stack);
}

t_stack	*init_stack(int *items, int size)
{
	t_stack	*stack;
	int		i;

	if (!items || size <= 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->items = malloc(size * sizeof(int *));
	if (!stack->items)
		return (clear_stack(stack), NULL);
	stack->size = size;
	while (--size >= 0)
	{
		stack->items[size] = malloc(sizeof(int));
		if (!stack->items[size])
			return (clear_stack(stack), NULL);
	}
	i = 0;
	while (i < stack->size)
	{
		*(stack->items)[i] = items[i];
		i++;
	}
	return (stack);
}

/*
Adds 1 to the STACK's SIZE and places NUM in the new space created
*/
void	stack_grow(t_stack **stack, int num)
{
	if (!stack)
		return ;
	(*stack)->items[(*stack)->size] = malloc(sizeof(int));
	if (!(*stack)->items[(*stack)->size])
		return ;
	(*stack)->size++;
	*(*stack)->items[(*stack)->size - 1] = num;
}

/*
Reduce the STACK's SIZE by 1. The number in the first place is freed
*/
void	stack_reduce(t_stack **stack)
{
	int	pos;

	if (!stack || (*stack)->size == 0)
		return ;
	pos = 0;
	while (++pos < (*stack)->size)
		*(*stack)->items[pos - 1] = *(*stack)->items[pos];
	free((*stack)->items[pos - 1]);
	(*stack)->items[pos - 1] = NULL;
	(*stack)->size--;
}
