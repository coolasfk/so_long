/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:50:07 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/12/21 15:27:29 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count(long num, int i, int n)
{
	if (num == 0)
		return (1);
	if (num > 0 && num <= 9)
	{
		if (n < 0)
			return (i + 2);
		else
			return (i + 1);
	}
	return (count(num / 10, i + 1, n));
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*temp;
	int			i;

	num = n;
	if (n < 0)
		num *= -1;
	i = count(num, 0, n);
	temp = (char *)malloc(i * sizeof(char) + 1);
	if (!temp)
		return (NULL);
	temp[i--] = '\0';
	while (num > 0)
	{
		temp[i--] = num % 10 + 48;
		num /= 10;
	}
	if (n == 0)
		temp[0] = num + 48;
	if (n < 0)
		temp[0] = '-';
	return (temp);
}
/*
int	main(int argc, char *argv[])
{
	(void)argc;
	printf("result: %s", ft_itoa(atoi(argv[1])));
}
*/
/*
The	itoa(void) function coverts the integer n into a character string.
The string is placed in the buffer passed,
which must be large enough to hold the output.
String pointer (same as buffer) will be returned.
When passed a non-valid radix argument,
function will return NULL and set errno to EINVAL.
*/
