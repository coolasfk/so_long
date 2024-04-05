/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:57:02 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/04/05 21:29:10 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	end_game(t_v *v)
{
	mlx_destroy_image(v->mx, v->im[0]);
	mlx_destroy_image(v->mx, v->im[1]);
	mlx_destroy_image(v->mx, v->im[2]);
	mlx_destroy_image(v->mx, v->im[3]);
	if (v->wn)
		mlx_destroy_window(v->mx, v->wn);
	exit(0);
	return (0);
}

void	handle_error(t_v *v, char *str)
{
	if (str == NULL)
	{
		ft_printf("%s\n", "Your map does not exists.");
		exit(0);
	}
	ft_printf("%s\n", str);
	end_game(v);
}

void	check_map_case1(t_v *v)
{
	int	i;

	i = 0;
	if (((int)ft_strlen(v->line) != v->tc_x / v->w + 1))
		handle_error(v, "the map is not square");
	if ((v->line[ft_strlen(v->line) - 2] != '1') || v->line[0] != '1')
	{
		ft_printf("%s\n", "The map is not surrounded by obstacles, bye!");
		exit(0);
	}
	while (i < (int)ft_strlen(v->line) - 1)
	{
		if (v->line[i] != '0' && v->line[i] != '1' && v->line[i] != 'E'
			&& v->line[i] != 'P' && v->line[i] != 'C')
		{
			ft_printf("%s\n", "The map has an unindentified object, bye!");
			exit(0);
		}
		i++;
	}
}

void	check_first_row(t_v *v)
{
	v->map_check = 1;
	v->i = 0;
	while (v->i < (int)ft_strlen(v->line))
	{
		if (v->line[v->i] != '1' && v->line[v->i] != '\n')
			handle_error(v, "the map is not surrounded by obstacles");
		v->i++;
	}
}
