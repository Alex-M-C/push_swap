/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:26:52 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 12:26:54 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Creates a new node, setting its content to 
CONTENT and setting the next node to NULL
@returns The new node or NULL if malloc(3) fails;
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return ((void *)0);
	new_list->content = content;
	new_list->next = (void *)0;
	return (new_list);
}
