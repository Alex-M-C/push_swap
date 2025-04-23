/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:18:11 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:18:15 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Allocates memory for an array of NMEMB elements of SIZE bytes each.
@return A pointer to the allocated memory.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	if (nmemb != 0 && size != 0 && total_size / size != nmemb)
		return ((void *)0);
	ptr = malloc(total_size);
	if (!ptr)
		return ((void *)0);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
