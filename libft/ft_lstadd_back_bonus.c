/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:42:55 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/19 15:04:55 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

/*
adding a new node to the end of the list.
*/

/*
int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*d;
	char	a_c;
	char	b_c;
	char	c_c;
	char	d_c;

	a_c = 'a';
	b_c = 'b';
	c_c = 'c';
	d_c = 'd';
	a = ft_lstnew(&a_c);
	b = ft_lstnew(&b_c);
	c = ft_lstnew(&c_c);
	d = ft_lstnew(&d_c);
	a->next = b;
	b->next = c;
	c->next = NULL;
	ft_lstadd_back(&a, d);
}
*/
