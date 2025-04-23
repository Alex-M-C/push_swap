/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:24 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:23:26 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
Appends the SRC string to the DEST string.
@attention Both strings must be NULL-terminated and must not overlap
@returns The total length of the string it tried to create or the length
needed if the DEST size is not enough to concatenate SRC
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	counter;
	size_t	dest_end;

	counter = 0;
	dest_end = ft_strlen(dest);
	if (size <= dest_end)
	{
		return (size + ft_strlen(src));
	}
	while (src[counter] != '\0' && (dest_end + counter) < size - 1)
	{
		dest[dest_end + counter] = src[counter];
		counter++;
	}
	dest[dest_end + counter] = '\0';
	return (dest_end + ft_strlen(src));
}
