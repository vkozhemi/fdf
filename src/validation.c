/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:55:03 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/13 22:32:25 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				find_down_link(t_dots **list)
{
	t_dots	*p;
	t_dots	*temp;

	p = *list;
	while (p && p->y == 0)
		p = p->next;
	temp = *list;
	while (p)
	{
		temp->down = p;
		p = p->next;
		temp = temp->next;
	}
	return (0);
}

int				find_next_link(t_dots *dots)
{
	t_dots	*p;

	p = dots;
	while (p->next)
	{
		if (p->y == p->next->y)
			p->right = p->next;
		p = p->next;
	}
	find_down_link(&dots);
	create_window(dots);
	return (0);
}

unsigned int	ft_atoi_base(char *s, int base)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || (s[i] > 8 && s[i] < 14))
		i++;
	while (s[i] && (ft_isdigit(s[i]) || (s[i] >= 'A' && s[i] <= 'F')))
	{
		result = (result * base) + (s[i] - (s[i] <= 57 ? 48 : 55));
		i++;
	}
	return (result);
}

t_dots			*find_coord(int i, int j, char **s)
{
	t_dots	*dots;
	char	*find_color;

	dots = (t_dots *)malloc(sizeof(t_dots));
	dots->x = i;
	dots->y = j;
	dots->z = ft_atoi(s[i]);
	if ((find_color = ft_strchr(s[i], ',')))
	{
		find_color = find_color + 3;
		dots->color = ft_atoi_base(find_color, 16);
	}
	else
		dots->color = 0xFFFFFF;
	dots->down = NULL;
	dots->right = NULL;
	dots->next = NULL;
	return (dots);
}

void			create_struct(char *line, t_dots **ptr, int count_line,
				int lenght_line)
{
	t_dots		*tmp;
	int			i;
	char		**s;
	static int	counter = 0;

	i = 0;
	s = ft_strsplit(line, ' ');
	if (!*ptr)
		*ptr = find_coord(i++, counter, s);
	tmp = *ptr;
	tmp->lenght_line = lenght_line;
	tmp->count_line = count_line;
	while (tmp->next)
		tmp = tmp->next;
	while (s[i])
	{
		tmp->next = find_coord(i++, counter, s);
		tmp = tmp->next;
	}
	while (i--)
		free(s[i]);
	free(s);
	counter++;
}
