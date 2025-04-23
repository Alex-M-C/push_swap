/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:24:49 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:24:52 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
@returns A pointer to the last occurrence of the character C in the string S
or NULL if no occurrence is found.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*match;

	match = (void *)0;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			match = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		match = (char *)s;
	return (match);
}
