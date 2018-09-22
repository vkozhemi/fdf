/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_br.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:34:04 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 22:16:26 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	alg_br(t_fdf *win, t_dots *dots, t_dots *sosed)
{
	t_dots	*ptr;

	ptr = dots;
	ptr->dx = (sosed->new_x - ptr->new_x >= 0 ? 1 : -1);
	ptr->dy = (sosed->new_y - ptr->new_y >= 0 ? 1 : -1);
	ptr->lenght_x = fabs(sosed->new_x - ptr->new_x);
	ptr->lenght_y = fabs(sosed->new_y - ptr->new_y);
	ptr->lenght = fmax(ptr->lenght_x, ptr->lenght_y);
	if (ptr->lenght == 0)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, ptr->new_x, ptr->new_y,
						ptr->color);
	if (ptr->lenght_y <= ptr->lenght_x)
		alg_br_x(win, dots);
	else
		alg_br_y(win, dots);
}

void	alg_br_x(t_fdf *win, t_dots *dots)
{
	double	x;
	double	y;
	t_dots	*ptr;

	ptr = dots;
	x = ptr->new_x;
	y = ptr->new_y;
	ptr->d = -(ptr->lenght_x);
	ptr->lenght = (ptr->lenght) + 1;
	while (ptr->lenght--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, ptr->color);
		x = x + ptr->dx;
		ptr->d = ptr->d + (2 * (ptr->lenght_y));
		if (ptr->d > 0)
		{
			(ptr->d) = ptr->d - (2 * (ptr->lenght_x));
			y = y + (ptr->dy);
		}
	}
}

void	alg_br_y(t_fdf *win, t_dots *dots)
{
	double	x;
	double	y;
	t_dots	*ptr;

	ptr = dots;
	x = ptr->new_x;
	y = ptr->new_y;
	ptr->d = -(ptr->lenght_y);
	ptr->lenght = (ptr->lenght) + 1;
	while (ptr->lenght--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, ptr->color);
		y = y + ptr->dy;
		ptr->d = ptr->d + (2 * (ptr->lenght_x));
		if (ptr->d > 0)
		{
			(ptr->d) = ptr->d - (2 * (ptr->lenght_y));
			x = x + (ptr->dx);
		}
	}
}

void	line(t_fdf *win, t_dots *dots)
{
	t_dots	*ptr;

	ptr = dots;
	while (ptr->next)
	{
		if (ptr->right)
			alg_br(win, ptr, ptr->right);
		if (ptr->down)
			alg_br(win, ptr, ptr->down);
		ptr = ptr->next;
	}
}
