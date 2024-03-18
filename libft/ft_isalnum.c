/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:57:40 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/11/18 13:52:30 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int num)
{
	return ((num >= 48 && num <= 57) || (num >= 'A' && num <= 'Z')
		|| (num >= 'a' && num <= 'z'));
}

/*
isalnum tests an integer value to determine whether it is an alphabetic
(uppercase or lowercase) or numeric character.
RETURN VALUE.
isalnum returns 0 if the character is not alphanumeric,
or a nonzero value if it is alphanumeric.
*/
