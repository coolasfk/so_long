/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:38:06 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/19 10:07:16 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_index(char map_char, t_v *v)
{
	if (map_char == '0' || map_char == 'P')
		return (2);
	if (map_char == '1')
		return (1);
	if (map_char == 'C')
		return (3);
	if (map_char == 'E')
	{
		if (v->i_drw == 0)
			v->e_c++;
		return (0);
	}
	return (-1);
}

void	draw_map(t_v *v)
{
	int	z;
	int	i;
	int	j;

	i = 0;
	z = 0;
	j = 0;
	draw_map_first_loop(v, i, j, z);
	if (v->c_check != v->c_count + 1)
		handle_error(v, "Unreachable collectables or exit!");
	if (v->p_c != 1)
		handle_error(v, "Yo, wrong number of players! Change the map!");
	if (v->e_c > 1)
		handle_error(v, "Too many exits, so you exit. Bye!");
	if (v->e_c == 0)
		handle_error(v, "No exit, just give up!");
	if (v->c_count == 0 && v->i_drw == 0)
		handle_error(v, "Go home, nothing to collect!");
	v->i_drw = 1;
	if (v->i_drw)
		mlx_put_image_to_window(v->mx, v->wn, v->plr, v->p_x, v->p_y);
	count_steps(v);
}

void	draw_map_first_loop(t_v *v, int i, int j, int z)
{
	while (v->map[i])
	{
		j = 0;
		while (v->map[i][j] != '\0')
		{
			v->map_v[i][j] = '0';
			z = get_index(v->map[i][j], v);
			draw_row(v, i, j, z);
			if (v->map[i][j] == 'C' && v->i_drw == 0)
			{
				v->c_count += 1;
				built_list(j * v->w, i * v->h, v);
			}
			if (v->map[i][j] == 'P' && v->i_drw == 0)
			{
				is_map_possible(v, i, j);
				v->p_c++;
				v->p_x = j * v->w;
				v->p_y = i * v->h;
			}
			j++;
		}
		i++;
	}
}

void	draw_row(t_v *v, int i, int j, int z)
{
	if (v->map[i][j] == 'C' && v->i_drw == 1 && !ch(j * v->w, i * v->h, v))
		mlx_put_image_to_window(v->mx, v->wn, v->im[2], j * v->w, i * v->h);
	else if (v->map[i][j] == '1' && v->i_drw == 1 && v->p_x == j * v->w
		&& v->p_y == i * v->h)
	{
		dont_move(v);
		mlx_put_image_to_window(v->mx, v->wn, v->plr, v->p_x, v->p_y);
		mlx_put_image_to_window(v->mx, v->wn, v->im[1], j * v->w, i * v->h);
	}
	else if (v->map[i][j] == 'E' && v->i_drw == 1 && v->p_x == j * v->w
		&& v->p_y == i * v->h)
	{
		if (v->collected != v->c_count)
		{
			dont_move(v);
			mlx_put_image_to_window(v->mx, v->wn, v->plr, v->p_x, v->p_y);
			mlx_put_image_to_window(v->mx, v->wn, v->im[0], j * v->w, i * v->h);
		}
		else
			end_game(v);
	}
	else
		mlx_put_image_to_window(v->mx, v->wn, v->im[z], j * v->w, i * v->h);
}

void	read_map(t_v *v, char *path)
{
	static char	*map_content;

	v->fd = open(path, O_RDONLY);
	if (v->fd < 0 || v->fd > 4095)
		handle_error(v, NULL);
	while (1)
	{
		v->line = get_next_line(v->fd);
		if (!v->line)
			break ;
		if (v->tc_x == 0)
			v->tc_x = (int)ft_strlen(v->line) * v->w - v->w;
		check_map(v);
		v->tc_y += v->h;
		v->temp = ft_strjoin(map_content, v->line);
		free(v->line);
		free(map_content);
		map_content = v->temp;
	}
	close(v->fd);
	v->map = ft_split((const char *)map_content, '\n');
	v->map_v = ft_split((const char *)map_content, '\n');
	free(map_content);
	v->wn = mlx_new_window(v->mx, v->tc_x, v->tc_y, "So_Long");
	draw_map(v);
}
