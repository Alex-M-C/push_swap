/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:03 by aleconst          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:06 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_move_to_start(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	while (pos_a > 0 || pos_b > 0)
	{
		if (pos_a <= (*a)->size / 2 && pos_b <= (*b)->size / 2
			&& pos_a > 0 && pos_b > 0)
		{
			rotate(a);
			rotate(b);
			sorting("04");
			pos_a--;
			pos_b--;
		}
		else if (pos_a > (*a)->size / 2 && pos_b > (*b)->size / 2
			&& pos_a > 0 && pos_b > 0)
		{
			reverse(a);
			reverse(b);
			sorting("40");
			if (++pos_a == (*a)->size)
				pos_a = 0;
			if (++pos_b == (*b)->size)
				pos_b = 0;
		}
		else
			return (move_to_start(a, pos_a, 0), move_to_start(b, pos_b, 1));
	}
}

void	move_to_start(t_stack **stack, int pos, int ab)
{
	while (pos > 0)
	{
		if (pos <= (*stack)->size / 2)
		{
			rotate(stack);
			if (ab == 0)
				sorting("13");
			else
				sorting("23");
			pos--;
		}
		else
		{
			reverse(stack);
			if (ab == 0)
				sorting("14");
			else
				sorting("24");
			pos++;
			if (pos == (*stack)->size)
				pos = 0;
		}
	}
}

int	get_pos(t_stack *stack, int to_find)
{
	int	pos;

	pos = 0;
	while (pos < stack->size)
	{
		if (to_find == *stack->items[pos])
		{
			return (pos);
		}
		pos++;
	}
	return (-1);
}

int	get_min(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->size < 1)
		return (-1);
	i = 0;
	min = *stack->items[0];
	while (++i < stack->size)
	{
		if (*stack->items[i] < min)
		{
			min = *stack->items[i];
		}
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	if (stack->size < 1)
		return (-1);
	i = 0;
	max = *stack->items[0];
	while (++i < stack->size)
	{
		if (max < *stack->items[i])
		{
			max = *stack->items[i];
		}
	}
	return (max);
}
