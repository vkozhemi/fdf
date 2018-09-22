/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 19:34:01 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 14:20:10 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color1(int key, t_fdf *win)
{
	t_dots	*p;

	p = win->dots;
	if (key == 89)
	{
		while (p)
		{
			p->color = 0xFFFFFF;
			p = p->next;
		}
	}
	else if (key == 91)
	{
		while (p)
		{
			p->color = 0xFF0061;
			p = p->next;
		}
	}
}

void	color2(int key, t_fdf *win)
{
	t_dots	*p;

	p = win->dots;
	if (key == 92)
	{
		while (p)
		{
			p->color = 0x00BFFF;
			p = p->next;
		}
	}
}

void	weed(int key, t_fdf *win)
{
	t_dots	*p;

	p = win->dots;
	if (key == 75)
	{
		while (1)
		{
			p = win->dots;
			while (p)
			{
				p->color = 0x00BFFF;
				p = p->next;
			}
			p = win->dots;
			while (p)
			{
				p->color = 0xFF0061;
				p = p->next;
			}
			if (key == 89)
				break ;
		}
	}
}

void	z_min_max(int key, t_fdf *win)
{
	double	t_max;
	double	t_min;
	t_dots	*ptr;

	ptr = win->dots;
	t_min = ptr->z;
	t_max = ptr->z;
	while (ptr->next)
	{
		if (t_max < ptr->z)
			t_max = ptr->z;
		else if (t_min > ptr->z)
			t_min = ptr->z;
		ptr = ptr->next;
	}
	win->z_min = t_min;
	win->z_max = t_max;
	ptr = win->dots;
	grad(key, win);
}

void	grad(int key, t_fdf *win)
{
	t_dots	*p;
	t_fdf	*l;

	p = win->dots;
	l = win;
	if (key == 65)
	{
		while (p)
		{
			if (l->z_min)
				p->color = 16777215;
			else if (l->z_max)
				p->color = 16711680;
			p = p->next;
		}
	}
}
