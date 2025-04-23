/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:03 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:20:06 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
Scans the initial N bytes of the memory area 
pointed to by S for the first instance of C.
@return A pointer to the matching byte or
NULL if the character does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*s_byte;

	count = 0;
	s_byte = (unsigned char *)s;
	while (count < n)
	{
		if (*s_byte == (unsigned char)c)
		{
			return (s_byte);
		}
		s_byte++;
		count++;
	}
	return ((void *)0);
}
