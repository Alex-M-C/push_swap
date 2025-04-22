/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:56:14 by aleconst          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:16 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_cost(t_stack *stack, int to_move)
{
	int	moves;

	moves = 0;
	while (to_move > 0)
	{
		if (to_move <= stack->size / 2)
		{
			to_move--;
		}
		else
		{
			to_move++;
			if (to_move == stack->size)
				to_move = 0;
		}
		moves++;
	}
	return (moves);
}

int	calculate_cost(t_stack **a, t_stack **b, int target, int associated)
{
	int	pos_target;
	int	pos_assoc;
	int	overlap;

	pos_target = get_pos(*b, target);
	pos_assoc = get_pos(*a, associated);
	overlap = 0;
	if (pos_assoc <= (*a)->size / 2 && pos_target <= (*b)->size / 2)
	{
		if (pos_assoc < pos_target)
			overlap = pos_assoc;
		else
			overlap = pos_target;
	}
	else if (pos_assoc > (*a)->size / 2 && pos_target > (*b)->size / 2)
	{
		if (((*a)->size - pos_assoc) < ((*b)->size) - pos_target)
			overlap = (*a)->size - pos_assoc;
		else
			overlap = (*b)->size - pos_target;
	}
	return (move_cost(*b, pos_target) + move_cost(*a, pos_assoc) - overlap);
}

static void	better_move(t_stack **a, t_stack **b, int *max_b)
{
	int	final_positions[2];
	int	final_cost;
	int	target;
	int	cost;
	int	i;

	i = -1;
	final_cost = -1;
	while (++i < (*a)->size)
	{
		target = find_target(b, *(*a)->items[i], *max_b);
		cost = calculate_cost(a, b, target, *(*a)->items[i]);
		if (final_cost == -1 || cost < final_cost)
		{
			final_positions[0] = get_pos(*b, target);
			final_positions[1] = i;
			final_cost = cost;
		}
	}
	double_move_to_start(a, b, final_positions[1], final_positions[0]);
	push(b, a);
	sorting("22");
	*max_b = get_max(*b);
}

static void	retrieve_in_order(t_stack **a, t_stack **b)
{
	int	target;
	int	i;

	while ((*b)->size > 0)
	{
		i = -1;
		target = get_min(*a);
		while (++i < (*a)->size)
		{
			if (*(*a)->items[i] > *(*b)->items[0]
				&& (*(*a)->items[i] < target || target <= *(*b)->items[0]))
				target = *(*a)->items[i];
		}
		move_to_start(a, get_pos(*a, target), 0);
		push(a, b);
		sorting("12");
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	max_b;

	if ((*a)->size > 3)
	{
		if ((*a)->size > 4)
		{
			push(b, a);
			sorting("22");
		}
		push(b, a);
		sorting("22");
	}
	else if ((*a)->size < 3)
		return (swap(a), sorting("11"));
	max_b = get_max(*b);
	while ((*a)->size > 3)
		better_move(a, b, &max_b);
	sort3(a);
	if ((*a)->size == 3 && (*b)->size < 1)
		return ;
	retrieve_in_order(a, b);
	move_to_start(a, get_pos(*a, get_min(*a)), 0);
}
