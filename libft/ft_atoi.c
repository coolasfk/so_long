/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:13:41 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/12/21 10:38:29 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	minus;
	int	num;

	num = 0;
	minus = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			minus *= -1;
		s++;
	}
	while (ft_isdigit(*s))
		num = (num * 10) + (*s++ - 48);
	return (num * minus);
}

/*
Converts a string to an integer. Returns the converted integer value.
*/
