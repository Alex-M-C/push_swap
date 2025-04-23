/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:22:54 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:23:02 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
To each character in the string S, the function F is applied giving as
parameters the index of each character within S and the address of 
the character itself, which can be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		count;

	if (!f)
		return ;
	count = 0;
	while (s[count] != '\0')
	{
		f(count, &s[count]);
		count++;
	}
}
