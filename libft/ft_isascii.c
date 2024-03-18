/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:04:37 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/18 21:50:39 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int num)
{
	return (num >= 0 && num <= 127);
}

/*
DESCRIPTION
The isascii() function shall test whether c is a 7-bit US-ASCII character code.

The isascii() function is defined on all integer values.

RETURN VALUE
The isascii() function shall return non-zero if c is a 7-bit
US-ASCII character code between 0 and octal 0177 inclusive; otherwise, it shall return 0.


*/

