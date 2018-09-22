/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:26:28 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 16:19:42 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	text_in_win(t_fdf *win)
{
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 1125, 0x33FFFF,
					"Position:        [X] - x, = - y, / - z");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 1100, 0x33FFFF,
					"Start position:  Enter");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 1075, 0x33FFFF,
					"Change color:    7 - white, 8 - red, 9 - blue");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 1050, 0x33FFFF,
					"Rotate:          1 - 4, 2 - 5, 3 - 6");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 1025, 0x33FFFF,
					"Change size:     + -");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 50, 1000, 0x33FFFF,
					"Move:            < ^ v >");
}

int		hadle_imput_key(int key, t_fdf *win)
{
	t_dots	*p;
	t_fdf	*l;

	l = win;
	p = win->dots;
	start_posit(key, win);
	xyz_posit(key, win);
	xyz_posit2(key, win);
	key_rotate(key, win);
	scale_move(key, win);
	povorot(win);
	color1(key, win);
	color2(key, win);
	z_min_max(key, win);
	change_coor(win);
	line(win, p);
	text_in_win(win);
	return (0);
}

void	scale_move(int key, t_fdf *win)
{
	t_dots	*p;

	p = win->dots;
	if (key == 78 && p->k > 4)
		p->k = p->k - 4;
	else if (key == 69)
		p->k = p->k + 4;
	else if (key == 123)
		win->x -= 7;
	else if (key == 126)
		win->y -= 7;
	else if (key == 125)
		win->y += 7;
	else if (key == 124)
		win->x += 7;
}

void	key_rotate(int key, t_fdf *win)
{
	t_fdf	*l;

	l = win;
	if (key == 53)
		exit(1);
	else if (key == 86)
		l->a = l->a + 0.1;
	else if (key == 83)
		l->a = l->a - 0.1;
	else if (key == 84)
		l->b = l->b + 0.1;
	else if (key == 87)
		l->b = l->b - 0.1;
	else if (key == 88)
		l->c = l->c + 0.1;
	else if (key == 85)
		l->c = l->c - 0.1;
}
