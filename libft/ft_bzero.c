/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:32:08 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/12/21 11:19:29 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = '\0';
}

/*
DESCRIPTION
The	bzero(void) function shall place n zero-valued bytes in the area pointed to by s.

RETURN VALUE
The	bzero(void) function shall not return a value.

ERRORS
No errors are defined.
*/
