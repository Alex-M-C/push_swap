/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:23:10 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:23:11 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Allocates memory with malloc(3) for creating a string
resulting in the concatenation of S1 and S2, ensuring 
that the new string will be NULL-terminated ('\0').
@returns The created string or NULL if malloc(3) fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		count;
	int		s1_len;

	s1_len = ft_strlen(s1);
	newstr = (char *)malloc((s1_len + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return ((void *)0);
	count = 0;
	while (count < s1_len)
	{
		newstr[count] = (char)s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		newstr[count + s1_len] = (char)s2[count];
		count++;
	}
	newstr[count + s1_len] = '\0';
	return (newstr);
}
