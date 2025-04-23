/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:17:54 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:17:57 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*
Erases data in the first N bytes of S by
replacing them with a NULL byte ('\0').
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_byte;

	s_byte = (unsigned char *)s;
	while (n > 0)
	{
		*s_byte = '\0';
		n--;
		s_byte++;
	}
}
