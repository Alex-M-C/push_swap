/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:21:07 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:21:09 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//Writes the character C into the specified FD(file descriptor).
void	ft_putchar_fd(char c, int fd)
{
	char	*c_ptr;

	if (fd < 0)
		return ;
	c_ptr = &c;
	write(fd, c_ptr, 1);
}
