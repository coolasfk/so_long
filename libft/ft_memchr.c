/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:21:29 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/19 16:42:28 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;
	unsigned char	cc;

	i = 0;
	if (n == 0 )
		return (NULL);
	ss = (unsigned char *)s;
	cc = (unsigned char)c;
	while ( i < n)
	{
		if (ss[i] == cc)
			return ((void *)ss + i);
		i++;
	}
	return (NULL);
}
/*
The ft_memchr function searches the first n bytes of the memory
area pointed to by s for the occurrence of the character c.
It returns a pointer to the first occurrence of c in the given memory area.
If the character is not found within the first n bytes,
the function returns NULL. This function is useful for searching
a block of memory for a specific character.
*/
