/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:33 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:23:36 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
Copies the string pointed to by SRC, including the terminating 
NULL byte ('\0'), to DEST. The copy is truncated if DEST length is
lower than SRC length, this can be checked by seeing the return value. 
@attention The strings may not overlap.
@returns The length of SRC
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	if (!dest || !src)
		return (ft_strlen(src));
	count = 0;
	if (size > 0)
	{
		while (count < size - 1 && src[count] != '\0')
		{
			dest[count] = src[count];
			count++;
		}
		dest[count] = '\0';
	}
	return (ft_strlen(src));
}
