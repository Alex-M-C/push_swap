/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:19:01 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:19:06 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Checks for an alphabetic character.
//@returns 1 if is alphabetic, 0 if not
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
