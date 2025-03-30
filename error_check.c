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
		if (ft_isdigit(*str) == 0)
		{
			is_valid = 1;
			break ;
		}
		str++;
		is_valid = 0;
	}
	return (is_valid);
}
