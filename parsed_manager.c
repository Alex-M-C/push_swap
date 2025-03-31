#include "push_swap.h"

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

int	number_count(int argc, char **argv)
{
	int	count;
	int	is_counting;
	int	i;
	int	j;

	count = 0;
	i = 0;
	is_counting = 1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != ' ')
				exit(1);
			if (ft_isdigit(argv[i][j]) == 1 && is_counting)
			{
				count++;
				is_counting = 0;
			}
			if (argv[i][j] == ' ')
				is_counting = 1;
		}
	}
	return (count);
}
