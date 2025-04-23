/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:22:37 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:22:39 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Creates a duplicate of S usign malloc(3) to allocate its memory.
@attention The created string can be freed with free(3).
@returns A pointer to the new string.
*/
char	*ft_strdup(const char *s)
{
	int		count;
	char	*s_dup;

	count = 0;
	s_dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!s_dup)
		return ((void *)0);
	while (s[count] != '\0')
	{
		s_dup[count] = s[count];
		count++;
	}
	s_dup[count] = '\0';
	return (s_dup);
}
