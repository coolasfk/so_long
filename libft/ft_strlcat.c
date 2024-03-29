/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:25:07 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/21 16:55:41 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s2_len = ft_strlen((char *)s2);
	if (n == 0)
		return (s2_len + n);
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[i] && n - 1 > s1_len + i)
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[s1_len + i] = '\0';
	if (n > s1_len)
		return (s2_len + s1_len);
	return (s2_len + n);
}
