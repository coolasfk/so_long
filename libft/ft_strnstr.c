/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:51:40 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/01 13:58:02 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	if (!n)
		return (NULL);
	while (s1[i] && i < n)
	{
		c = 0;
		while (s1[i + c] == s2[c] && i + c < n && s1[i + c])
		{
			if (s2[c + 1] == '\0')
			{
				return ((char *)s1 + i);
			}
			c++;
		}
		i++;
	}
	return (NULL);
}
