/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:14:30 by eprzybyl          #+#    #+#             */
/*   Updated: 2023/12/21 11:39:13 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int num)
{
	return ((num >= 'A' && num <= 'Z') || (num >= 'a' && num <= 'z'));
}

/*
tests an integer value to determine whether it is an alphabetic
(uppercase or lowercase) character.
RETURN VALUE.
isalnum returns 0 if the character is not alphabetic (false),
or a nonzero value (true) if it is alphabetic.
*/
