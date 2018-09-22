/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:22:54 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 16:09:32 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_coor(t_fdf *win)
{
	t_dots	*new;
	int		tmp1;
	int		tmp2;
	double	k;

	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	new = win->dots;
	tmp1 = new->lenght_line;
	tmp2 = new->count_line;
	k = new->k;
	while (new)
	{
		new->new_x = (HEIGHT / 2) + (tmp1 / 2 - new->x3) * k + win->x;
		new->new_y = (WIDTH / 2) + (tmp2 / 2 - new->y3) * k + win->y;
		new = new->next;
	}
}

void	povorot(t_fdf *win)
{
	t_dots	*p;
	t_fdf	*l;

	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	p = win->dots;
	l = win;
	find_x0_y0(l);
	while (p)
	{
		p->x1 = p->x;
		p->y1 = p->y0 + (p->y - p->y0) * cos(l->a) + (p->z0 - p->z) *
		sin(l->a);
		p->z1 = p->z0 + (p->y - p->y0) * sin(l->a) + (p->z - p->z0) *
		cos(l->a);
		p->x2 = p->x0 + (p->x1 - p->x0) * cos(l->b) + (p->z1 - p->z0) *
		sin(l->b);
		p->y2 = p->y1;
		p->z2 = p->z0 + (p->x0 - p->x1) * sin(l->b) + (p->z1 - p->z0) *
		cos(l->b);
		p->x3 = p->x0 + (p->x2 - p->x0) * cos(l->c) + (p->y0 - p->y2) *
		sin(l->c);
		p->y3 = p->y0 + (p->x2 - p->x0) * sin(l->c) + (p->y2 - p->y0) *
		cos(l->c);
		p = p->next;
	}
}

void	find_x0_y0(t_fdf *win)
{
	t_dots	*p;
	double	lenght1;
	double	count1;

	p = win->dots;
	lenght1 = p->lenght_line;
	count1 = p->count_line;
	while (p)
	{
		p->x0 = lenght1 / 2;
		p->y0 = count1 / 2;
		p->z0 = (p->z) / 2;
		p = p->next;
	}
}

void	create_k(t_dots *dots)
{
	t_dots	*new;
	int		tmp1;
	int		tmp2;

	new = dots;
	tmp1 = new->lenght_line;
	tmp2 = new->count_line;
	while (new)
	{
		new->k = fmin((HEIGHT / 2) / tmp1, (HEIGHT / 2) / tmp2);
		new = new->next;
	}
}

void	move_x_y(t_fdf *win)
{
	t_fdf	*ptr;

	ptr = win;
	ptr->x = 0;
	ptr->y = 0;
	ptr->a = 0.4;
	ptr->b = 0.4;
	ptr->c = 3.2;
}
