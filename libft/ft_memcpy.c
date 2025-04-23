/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:20:29 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:20:32 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
Copies N bytes from memory area SRC to memory area DEST.
@attention The memory areas must not overlap.
Use ft_memmove(3) if the memory areas do overlap.
@returns A pointer to DEST.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int					count;
	unsigned char		*dest_byte;
	const unsigned char	*src_byte;

	if (!dest && !src)
		return (dest);
	count = 0;
	dest_byte = dest;
	src_byte = src;
	while (n > 0)
	{
		dest_byte[count] = src_byte[count];
		count++;
		n--;
	}
	return (dest_byte);
}
