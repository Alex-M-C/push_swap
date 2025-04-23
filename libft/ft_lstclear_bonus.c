/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:52:52 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/14 11:52:54 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
Erases an frees the node poited to by *LST and does the same for each node from
the list LST using the function DEL and free(3). At the end, the pointer to the
list must be NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp_node;

	if (!*lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		temp_node = node->next;
		ft_lstdelone(node, del);
		node = temp_node;
	}
	*lst = (void *)0;
}
