/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:40:20 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/03/18 15:09:37 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef WIDTH
#  define WIDTH 500
# endif

# ifndef HEIGHT
#  define HEIGHT 500
# endif

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct ct_clist
{
	int				arr[2];
	struct ct_clist	*next;
}					t_clist;

typedef struct s_v
{
	void			*mx;
	void			*wn;
	void			*plr;
	void			*im[5];
	char			**map;
	char			**map_v;
	int				plr_height;
	int				plr_width;
	int				x;
	int				y;
	int				h;
	int				w;
	int				p_x;
	int				p_y;
	int				i_drw;
	int				c_count;
	t_clist			*head;
	t_clist			*ptr;
	t_clist			*prev;
	t_clist			*node;
	int				last_x;
	int				last_y;
	int				collected;
	int				steps;
	int				error;
	int				tc_x;
	int				tc_y;
	int				flag;
	char			*temp;
	char			*line;
	int				fd;
	int				p_c;
	int				e_c;
	int				c_check;

}					t_v;

void				draw_circle(t_v *v, int x, int y, int radius);
void				draw_map(t_v *v);
void				load_images(t_v *v);
int					key_hook(int keycode, t_v *v);
int					main(int argc, char *argv[]);
void				built_list(int x, int y, t_v *v);
t_clist				*get_collectibles_list(t_v *v);
void				check_if_collected(t_v *v);
int					ch(int x, int y, t_v *v);
int					end_game(t_v *v);
void				what_error(t_v *v);

void				handle_error(t_v *v, char *str);
void				read_map(t_v *v, char *path);
void				check_map(t_v *v);
void				draw_row(t_v *v, int i, int j, int z);
void				draw_map_first_loop(t_v *v, int i, int j, int z);
void				check_map_extension(char *s);
void				initialize_v(t_v *v);
int					is_map_possible(t_v *v, int i, int j);
void				check_map_case1(t_v *v);

#endif /* SO_LONG_H */
