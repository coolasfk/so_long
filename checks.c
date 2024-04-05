/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:44:24 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/04/05 21:17:37 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	check_if_collected(t_v *v)
{
	v->prev = NULL;
	v->ptr = v->head;
	while (v->ptr != NULL)
	{
		if (v->ptr->arr[0] == v->p_x && v->ptr->arr[1] == v->p_y)
		{
			v->collected += 1;
			if (v->prev == NULL)
				v->head = v->ptr->next;
			else
				v->prev->next = v->ptr->next;
			free(v->ptr);
			return ;
		}
		v->prev = v->ptr;
		v->ptr = v->ptr->next;
	}
}

int	ch(int x, int y, t_v *v)
{
	t_clist	*ptr;

	ptr = v->head;
	while (ptr != NULL)
	{
		if (ptr->arr[0] == x && ptr->arr[1] == y)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	is_map_possible(t_v *v, int i, int j)
{
	if (i < 0 || j < 0 || i >= v->tc_x / v->w || j > v->tc_y
		|| v->map[i][j] == '1' || v->map_v[i][j] == '1')
		return (0);
	if (v->map[i][j] == 'C' || v->map[i][j] == 'E')
		v->c_check++;
	v->map_v[i][j] = '1';
	is_map_possible(v, i + 1, j);
	is_map_possible(v, i - 1, j);
	is_map_possible(v, i, j + 1);
	is_map_possible(v, i, j - 1);
	return (v->c_check);
}

void	check_map_extension(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (i < 4)
	{
		ft_printf("%s\n", "Yo, your map doesn't have the right .ber extention");
		exit(0);
	}
	if (s[i - 1] != 'r' || s[i - 2] != 'e'
		|| s[i - 3] != 'b' || s[i - 4] != '.')
	{
		ft_printf("%s\n", "Yo, your map doesn't have the right .ber extention");
		exit(0);
	}
	return ;
}

void	check_map(t_v *v)
{
	if (v->map_check == 0)
		check_first_row(v);
	v->i = 0;
	if (v->line[ft_strlen(v->line) - 1] == '\n')
		check_map_case1(v);
	else if (v->line[ft_strlen(v->line) - 1] != '\n')
	{
		if (((int)ft_strlen(v->line) != v->tc_x / v->w))
			handle_error(v, "the map is not square");
		while (v->i < (int)ft_strlen(v->line))
		{
			if (v->line[v->i] != '1')
				handle_error(v, "the map is not surrounded by obstacles");
			if (v->line[v->i] != '0' && v->line[v->i] != '1'
				&& v->line[v->i] != 'E' && v->line[v->i] != 'P')
				handle_error(v, "The map has an unindentified object, bye!");
			v->i++;
		}
	}
}
