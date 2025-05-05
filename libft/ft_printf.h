/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:02:14 by aleconst          #+#    #+#             */
/*   Updated: 2025/03/17 16:02:17 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(char const *mod, ...);

ssize_t	ft_putnbr(int nbr);

ssize_t	ft_putlong_base(unsigned long num, char *base);

ssize_t	ft_printmem(void *ptr);

ssize_t	ft_putchar(char c);

ssize_t	ft_putstr(char *s);

#endif
