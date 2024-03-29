/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:48:37 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/21 16:55:57 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	strt;
	size_t	end;

	strt = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(" "));
	while (s1[strt])
	{
		if (ft_strchr(set, s1[strt]) == NULL)
			break ;
		strt++;
	}
	end = ft_strlen((char *)s1);
	while (end > strt)
	{
		if (ft_strchr(set, s1[end - 1]) == NULL)
			break ;
		end--;
	}
	new = ft_substr((char *)s1, strt, end - strt);
	return (new);
}
