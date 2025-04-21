#include "push_swap.h"

int	find_target(t_stack **b, int associated, int max_b)
{
	int	is_first;
	int	target;
	int	i;

	is_first = 1;
	target = max_b;
	i = -1;
	while (++i < (*b)->size)
	{
		if (*(*b)->items[i] < associated
			&& (is_first == 1 || target < *(*b)->items[i]))
		{
			target = *(*b)->items[i];
			is_first = 0;
		}
	}
	return (target);
}

void	sort3(t_stack **a)
{
	if (*(*a)->items[0] > *(*a)->items[1] && *(*a)->items[1] > *(*a)->items[2])
	{
		return (swap(a), sorting("11"), reverse(a), sorting("14"));
	}
	else if (*(*a)->items[0] < *(*a)->items[1] && *(*a)->items[1]
		> *(*a)->items[2] && *(*a)->items[0] < *(*a)->items[2])
	{
		return (swap(a), sorting("11"), rotate(a), sorting("13"));
	}
	else if (*(*a)->items[0] < *(*a)->items[1] && *(*a)->items[1]
		> *(*a)->items[2] && *(*a)->items[0] > *(*a)->items[2])
	{
		return (reverse(a), sorting("14"));
	}
	else if (*(*a)->items[0] > *(*a)->items[1] && *(*a)->items[1]
		< *(*a)->items[2] && *(*a)->items[0] < *(*a)->items[2])
	{
		return (swap(a), sorting("11"));
	}
	else if (*(*a)->items[0] > *(*a)->items[1] && *(*a)->items[1]
		< *(*a)->items[2] && *(*a)->items[0] > *(*a)->items[2])
	{
		return (rotate(a), sorting("13"));
	}
}
