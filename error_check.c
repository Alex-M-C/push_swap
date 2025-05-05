/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:54:35 by aleconst          #+#    #+#             */
/*   Updated: 2025/04/22 12:54:40 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_out_of_range(const char *str)
{
	int			len;
	int			is_negative;
	int			i;
	const char	*limit;

	len = ft_strlen(str);
	is_negative = 0;
	if (str[0] == '-')
		is_negative = 1;
	limit = "2147483647";
	if (is_negative)
		limit = "2147483648";
	if (len > 11 || (len > 10 && !is_negative))
		return (1);
	if (len < 10 + is_negative)
		return (0);
	i = is_negative - 1;
	while (str[++i])
	{
		if (str[i] > limit[i - is_negative])
			return (1);
		if (str[i] < limit[i - is_negative])
			return (0);
	}
	return (0);
}

int	check_format_error(const char *str)
{
	int	is_valid;

	is_valid = 1;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 0 && *str != ' ')
		{
			is_valid = 1;
			break ;
		}
		str++;
		is_valid = 0;
	}
	return (is_valid);
}

static int	add_to_numbers(int **numbers, char **parsed_args, int num_count)
{
	int	i;
	int	j;
	int	actual_num;

	i = -1;
	while (parsed_args[++i])
	{
		if (is_out_of_range(parsed_args[i]) == 1
			|| check_format_error(parsed_args[i]) == 1)
			return (-1);
		actual_num = ft_atoi(parsed_args[i]);
		j = 0;
		while (j < num_count)
		{
			if ((*numbers)[j++] == actual_num)
				return (-1);
		}
		(*numbers)[num_count++] = actual_num;
	}
	return (num_count);
}

int	*has_duplicates(int argc, char **argv, int real_argc)
{
	char	**parsed_args;
	int		*numbers;
	int		num_count;
	int		i;

	numbers = (int *)malloc(real_argc * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	num_count = 0;
	while (++i < argc)
	{
		parsed_args = ft_split(argv[i], ' ');
		if (!parsed_args)
			return (NULL);
		num_count = add_to_numbers(&numbers, parsed_args, num_count);
		clear_parsed(parsed_args);
		if (num_count == -1)
		{
			free(numbers);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return (numbers);
}
