/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:40:24 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/19 10:02:06 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_v(t_v *v)
{
	v->w = 200;
	v->h = 200;
	v->mx = mlx_init();
	v->i_drw = 0;
	v->plr_width = 180;
	v->plr_height = 180;
	v->head = NULL;
	v->tc_x = 0;
	v->tc_y = 0;
	v->c_count = 0;
	v->p_c = 0;
	v->e_c = 0;
	v->c_check = 0;
	v->steps = -1;
	v->collected = 0;
	v->im[0] = NULL;
	v->im[1] = NULL;
	v->im[2] = NULL;
	v->im[3] = NULL;
	v->steps_code = -1;
}

int	key_hook(int keycode, t_v *v)
{
	v->last_x = v->p_x;
	v->last_y = v->p_y;
	if (keycode == 13)
		v->p_y -= v->h;
	if (keycode == 0)
		v->p_x -= v->w;
	if (keycode == 1)
		v->p_y += v->h;
	if (keycode == 2)
		v->p_x += v->w;
	if (keycode == 53)
		end_game(v);
	check_if_collected(v);
	mlx_clear_window(v->mx, v->wn);
	draw_map(v);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_v	v;

	if (argc != 2)
		return (1);
	check_map_extension(argv[1]);
	initialize_v(&v);
	load_images(&v);
	read_map(&v, argv[1]);
	mlx_hook(v.wn, 17, 0, end_game, &v);
	mlx_key_hook(v.wn, key_hook, &v);
	mlx_loop(v.mx);
}

void	built_list(int x, int y, t_v *v)
{
	t_clist	*next_node;
	t_clist	*ptr;

	if (v->head == NULL && x != 0 && y != 0 && v->i_drw == 0)
	{
		v->head = (t_clist *)malloc(sizeof(t_clist));
		if (!v->head)
			return ;
		v->head->arr[0] = x;
		v->head->arr[1] = y;
		v->head->next = NULL;
	}
	else if (x != 0 && y != 0 && v->i_drw == 0)
	{
		ptr = v->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		next_node = (t_clist *)malloc(sizeof(t_clist));
		if (!next_node)
			return ;
		next_node->arr[0] = x;
		next_node->arr[1] = y;
		next_node->next = NULL;
		ptr->next = next_node;
	}
}

void	load_images(t_v *v)
{
	v->im[0] = mlx_xpm_file_to_image(v->mx, "xpm/palm.xpm", &v->w, &v->h);
	v->im[1] = mlx_xpm_file_to_image(v->mx, "xpm/rocks.xpm", &v->w, &v->h);
	v->im[2] = mlx_xpm_file_to_image(v->mx, "xpm/water.xpm", &v->w, &v->h);
	v->im[3] = mlx_xpm_file_to_image(v->mx, "xpm/wave.xpm", &v->w, &v->h);
	v->plr = mlx_xpm_file_to_image(v->mx, "xpm/surfer.xpm", &v->p_x, &v->p_y);
}
