/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:23:04 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 16:23:07 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	start_posit(int key, t_fdf *win)
{
	t_fdf	*l;
	t_dots	*p;

	p = win->dots;
	l = win;
	if (key == 76)
	{
		l->a = 0.4;
		l->b = 0.4;
		l->c = 3.2;
		l->x = 0;
		l->y = 0;
		create_k(p);
	}
}

void	xyz_posit(int key, t_fdf *win)
{
	t_fdf	*l;

	l = win;
	if (key == 71)
	{
		l->a = 0;
		l->b = 0;
		l->c = 0;
		l->x = 0;
		l->y = 0;
	}
	else if (key == 81)
	{
		l->a = 0;
		l->b = 1.5708;
		l->c = 0;
		l->x = 0;
		l->y = 0;
	}
}

void	xyz_posit2(int key, t_fdf *win)
{
	t_fdf	*l;

	l = win;
	if (key == 75)
	{
		l->a = 1.5708;
		l->b = 0;
		l->c = 0;
		l->x = 0;
		l->y = 0;
	}
}

void	create_window(t_dots *dots)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_fdf	*win;

	win = (t_fdf *)malloc(sizeof(t_fdf));
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "vkozhemi");
	win->mlx_ptr = mlx_ptr;
	win->win_ptr = win_ptr;
	win->dots = dots;
	move_x_y(win);
	create_k(dots);
	povorot(win);
	change_coor(win);
	line(win, dots);
	text_in_win(win);
	mlx_hook(win->win_ptr, 2, 5, hadle_imput_key, win);
	mlx_loop(win->mlx_ptr);
}
