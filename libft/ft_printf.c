/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:01:38 by aleconst          #+#    #+#             */
/*   Updated: 2025/03/17 16:01:42 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_putnbr_hex(int nbr, char *basehex)
{
	unsigned int	unbr;
	char			*base;
	ssize_t			len;

	base = basehex;
	len = 0;
	if (nbr < 0)
		unbr = (unsigned int)nbr;
	else
		unbr = nbr;
	if (unbr >= 16)
		len = ft_putnbr_hex(unbr / 16, base);
	write(1, &base[unbr % 16], 1);
	return (len + 1);
}

static ssize_t	ft_putuint_base(unsigned int num, char *base)
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

static ssize_t	ft_format(ssize_t i, char const c, va_list args)
{
	ssize_t	n_printed;

	n_printed = 0;
	if (c == 'c')
		n_printed = ft_putchar(va_arg(args, int));
	else if (c == 's')
		n_printed = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		n_printed = ft_printmem(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		n_printed = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		n_printed = ft_putuint_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		n_printed = ft_putnbr_hex(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		n_printed = ft_putnbr_hex(va_arg(args, int), "0123456789ABCDEF");
	else if (c == '%')
		n_printed = ft_putchar('%');
	if (n_printed < 0)
		return (-1);
	else
		return (i + n_printed);
}

int	ft_printf(char const *mod, ...)
{
	va_list	args;
	size_t	i;
	ssize_t	n_char;

	va_start(args, mod);
	i = -1;
	n_char = 0;
	while (mod[++i] != '\0' && n_char >= 0)
	{
		if (mod[i] == '%')
			n_char = ft_format(n_char, mod[++i], args);
		else
		{
			if (write(1, &(mod[i]), 1) == -1)
				return (va_end(args), -1);
			n_char++;
		}
	}
	va_end(args);
	if (n_char == -1)
		return (-1);
	return (n_char);
}
