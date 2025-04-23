/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:18:40 by aleconst          #+#    #+#             */
/*   Updated: 2025/01/13 13:18:42 by aleconst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds the node NEW at the end of the node list LST
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	else if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
	{
		node = node->next;
	}
	node->next = new;
}
