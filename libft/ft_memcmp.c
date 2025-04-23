/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:14 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:20:17 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
Compares the first N bytes of S1 and S2.
@returns The difference between the first distinct byte of S1 and S2
or 0 if they are equal within the N range.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_byte;
	unsigned char	*s2_byte;
	size_t			counter;

	s1_byte = (unsigned char *)s1;
	s2_byte = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (s1_byte[counter] != s2_byte[counter])
		{
			return (s1_byte[counter] - s2_byte[counter]);
		}
		counter++;
	}
	return (0);
}
