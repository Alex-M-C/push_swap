/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:55:38 by aleconst          #+#    #+#             */
/*   Updated: 2025/04/22 12:55:40 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Movements:
	-Swap a:		11
	-Swap b:		21
	-Swap a,b:		03
	-Push a:		12
	-Push b:		22
	-Rotate a:		13
	-Rotate b:		23
	-Rotate a,b:	04
	-Reverse a:		14
	-Reverse b:		24
	-Reverse a,b:	40
*/
void	sorting(char *mode)
{
	if (mode[1] == '1')
		printf("s");
	else if (mode[1] == '2')
		printf("p");
	else if (mode[1] == '3')
		printf("r");
	else if (mode[1] == '4')
		printf("rr");
	if (mode[0] == '1')
		printf("a");
	else if (mode[0] == '2')
		printf("b");
	else if (mode[0] == '3')
		printf("ss");
	else if (mode[0] == '4')
		printf("rrr");
	printf("\n");
}

void	swap(t_stack **stack)
{
	if (!stack || (*stack)->size < 2)
		return ;
	if (!(*stack)->items[0] || !(*stack)->items[1])
		return ;
	*(*stack)->items[0] = *(*stack)->items[0] ^ *(*stack)->items[1];
	*(*stack)->items[1] = *(*stack)->items[0] ^ *(*stack)->items[1];
	*(*stack)->items[0] = *(*stack)->items[0] ^ *(*stack)->items[1];
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_b)
		|| !(*stack_b)->items || !(*stack_b)->items[0])
		return ;
	if (!(*stack_a) || !(*stack_a)->items)
		return ;
	stack_grow(stack_a, *(*stack_b)->items[0]);
	stack_reduce(stack_b);
	if ((*stack_a)->items[0])
		reverse(stack_a);
}

void	rotate(t_stack **stack)
{
	int	pos;
	int	first_num;

	if (!stack || (*stack)->size < 2)
		return ;
	pos = 0;
	first_num = *(*stack)->items[0];
	while (++pos < (*stack)->size)
	{
		*(*stack)->items[pos - 1] = *(*stack)->items[pos];
	}
	*(*stack)->items[pos - 1] = first_num;
}

void	reverse(t_stack **stack)
{
	int	pos;
	int	last_num;

	if (!stack || (*stack)->size < 2)
		return ;
	pos = (*stack)->size;
	last_num = *(*stack)->items[pos - 1];
	while (--pos > 0)
	{
		*(*stack)->items[pos] = *(*stack)->items[pos - 1];
	}
	*(*stack)->items[pos] = last_num;
}
