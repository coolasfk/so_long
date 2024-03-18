/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:18:02 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/19 15:04:55 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
"This function adds a new node at the beginning of the list.
It takes a double pointer to the first node of the list (t_list **lst)
and a single pointer to the new node (t_list *new).
The new node is inserted at the beginning of the list,
becoming the new first node."


*/
