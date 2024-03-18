/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:12:45 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/07 16:02:56 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	new = (char *)malloc((i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[c])
	{
		new[c] = f(c, s[c]);
		c++;
	}
	new[c] = '\0';
	return (new);
}
/*
char	to_uppercase(unsigned int i, char c) {

	if(i == 0)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = 'b';
		//return (c - 32);
		}
	} else {
		c = 'd';
	}
	return (c);
}

int	main(void)
{
	char	*str;

	str = "AAbbA";
	printf("result: %s", ft_strmapi(str, to_uppercase));
}
*/
