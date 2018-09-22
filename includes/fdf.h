/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:03:54 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 19:10:03 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 2000
# define WIDTH 1200

# include <stdio.h>
# include "../libft/libft.h"
# include <mlx.h>
# define BUFF_SIZE 1000
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_dots
{
	double			x;
	double			y;
	double			z;
	double			lenght_line;
	double			count_line;
	unsigned int	color;
	struct s_dots	*right;
	struct s_dots	*down;
	struct s_dots	*next;
	int				d;
	int				dx;
	int				dy;
	int				lenght_x;
	int				lenght_y;
	int				lenght;
	double			new_x;
	double			new_y;
	double			new_z;
	double			x1;
	double			y1;
	double			z1;
	double			x2;
	double			y2;
	double			z2;
	double			x3;
	double			y3;
	double			x0;
	double			y0;
	double			z0;
	double			k;
	double			move;
}				t_dots;

typedef struct	s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	double			x;
	double			y;
	struct s_fdf	*next;
	struct s_dots	*dots;
	double			a;
	double			b;
	double			c;
	double			z_min;
	double			z_max;
}				t_fdf;

void			read_file(char **argv, int lenght_line, int count_line);
void			create_struct(char *line, t_dots **ptr, int count_line,
							int lenght_line);
t_dots			*find_coord(int i, int j, char **str);
int				count_elements(const char *str, int j, int res);
int				find_down_link(t_dots **list);
int				find_next_link(t_dots *dots);
unsigned int	ft_atoi_base(char *s, int base);
void			alg_br(t_fdf *win, t_dots *dots, t_dots *sosed);
void			alg_br_x(t_fdf *win, t_dots *dots);
void			alg_br_y(t_fdf *win, t_dots *dots);
void			line(t_fdf *win, t_dots *dots);
void			create_window(t_dots *dots);
void			povorot(t_fdf *win);
void			text_in_win(t_fdf *win);
void			change_coor(t_fdf *win);
void			create_k(t_dots *dots);
int				hadle_imput_key(int key, t_fdf *win);
void			move_x_y(t_fdf *win);
int				ft_gnl(int fd, int *count_line, int *lenght_line, int temp);
void			find_x0_y0(t_fdf *win);
void			key_rotate(int key, t_fdf *win);
void			scale_move(int key, t_fdf *win);
void			color1(int key, t_fdf *win);
void			color2(int key, t_fdf *win);
void			start_posit(int key, t_fdf *win);
void			z_min_max(int key, t_fdf *win);
void			grad(int key, t_fdf *win);
void			xyz_posit(int key, t_fdf *win);
void			xyz_posit2(int key, t_fdf *win);
void			exit_error(int flag);

#endif
