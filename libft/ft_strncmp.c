/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:24:24 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:24:26 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
Compares the first N bytes of the two strings S1 and S2
@returns The difference between the first distinct byte of S1 and S2
or 0 if they are equal within the N range.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	counter;
	unsigned char	*s1_uns;
	unsigned char	*s2_uns;

	counter = 0;
	s1_uns = (unsigned char *)s1;
	s2_uns = (unsigned char *)s2;
	while (counter < n && s1_uns[counter] != '\0' && s2_uns[counter] != '\0')
	{
		if (s1_uns[counter] != s2_uns[counter])
		{
			return (s1_uns[counter] - s2_uns[counter]);
		}
		counter++;
	}
	if (counter < n)
	{
		return (s1_uns[counter] - s2_uns[counter]);
	}
	return (0);
}
