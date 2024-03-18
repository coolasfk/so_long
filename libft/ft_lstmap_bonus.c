/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:59:44 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/19 15:04:55 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	void	*content;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			if (del && content)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

/*
lstmap checks if lst or f are empty. if they are - it stops.
lstmap allocated memory for it and creates a copy of the list.
checks if the operation was successful.
it performs a function on each node which
is passed to the function as an argument.
it manipulates each node.
if this encounters the error, lstmap deletes the newly created copy of the list.
it frees allocated memory for the new list.
if the operation was successful, it returns the pointer to the head of the new list.
*/
