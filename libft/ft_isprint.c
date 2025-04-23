/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:19:38 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:19:44 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Checks for a printable character.
//@returns 1 if is printable, 0 if not
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= 126)
		return (1);
	else
		return (0);
}
