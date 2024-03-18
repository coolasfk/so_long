/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:13:39 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/20 12:25:25 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c, int count)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
			i++;
		}
	}
	return (count);
}

char	**make_split(char const *s, char c, char **split, int count)
{
	int	i;
	int	start;
	int	nr;
	int	index;

	i = 0;
	start = 0;
	nr = 0;
	index = 0;
	while (s[i] != '\0' && nr < count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			start++;
			i++;
		}
		split[nr] = (char *)malloc(start * sizeof(char) + 1);
		if (!split[nr])
			return (NULL);
		index = i - start;
		split[nr][start] = '\0';
		start -= 1;
		while (start >= 0)
		{
			split[nr][start] = s[index + start];
			start--;
		}
		start += 1;

		nr++;
	}
	split[nr] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;

	count = 0;

	count = word_count(s, c, count);
	split = (char **)malloc((count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = make_split(s, c, split, count);
	return (split);
}
/*

The function allocates memory for this array and each substring,
and it ends the array with a NULL pointer to indicate the end of the array.
This is important for iterating through the array without accessing out-of-bounds memory.
It's also the caller's responsibility to free the memory allocated for the array
and its contents when they are no longer needed to avoid memory leaks.
If the function encounters any issues (like memory allocation failures),
it typically returns NULL.
*/
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	// printf("S: %s", *ft_split(argv[1], *argv[2]));
	printf("ft_split %s", *ft_split(argv[1], *argv[2]));
}
*/
