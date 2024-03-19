/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps_dont_move.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:06:22 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/19 10:11:52 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_steps(t_v *v)
{
	if (v->steps_code == 1)
	{
		v->steps_code = 0;
	}
	else
	{
		v->steps += 1;
		ft_printf("Number of moves: %d\n", v->steps);
	}
}

void	dont_move(t_v *v)
{
	v->steps_code = 1;
	v->p_x = v->last_x;
	v->p_y = v->last_y;
}
