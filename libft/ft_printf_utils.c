/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:01:52 by aleconst          #+#    #+#             */
/*   Updated: 2025/03/17 16:01:54 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchar(char c)
{
	char	*c_ptr;

	c_ptr = &c;
	return (write(1, c_ptr, 1));
}

ssize_t	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

ssize_t	ft_putnbr(int n)
{
	char	c;
	ssize_t	count;
	ssize_t	temp;

	count = 0;
	if (n == -(__INT32_MAX__) - 1)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		count++;
	}
	if (n > 9)
	{
		temp = ft_putnbr(n / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

ssize_t	ft_putlong_base(unsigned long num, char *base)
{
	ssize_t	size;
	ssize_t	temp;
	size_t	base_len;

	size = 0;
	temp = 0;
	if (!base)
		return (0);
	base_len = ft_strlen(base);
	if (num >= base_len)
		temp = ft_putlong_base(num / base_len, base);
	if (temp != -1)
		size = temp;
	else
		return (-1);
	temp = ft_putchar(base[num % base_len]);
	if (temp == -1)
		return (-1);
	return (size + temp);
}

ssize_t	ft_printmem(void *ptr)
{
	ssize_t	temp;

	if (!ptr)
		return (ft_putstr("(nil)"));
	if (write(1, "0x", 2) == -1)
		return (-1);
	temp = ft_putlong_base((unsigned long)ptr, "0123456789abcdef");
	if (temp == -1)
		return (-1);
	else
		return (temp + 2);
}
