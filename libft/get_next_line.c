/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 04:35:05 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/05/26 16:04:23 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*read_line(const int fd, char **keep_str)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*temp;

	if (keep_str == NULL || fd < 0)
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(*keep_str, buf);
		free(*keep_str);
		*keep_str = temp;
		if (ft_strchr(*keep_str, '\n'))
			break ;
	}
	if (ret == -1)
	{
		free(*keep_str);
		return (0);
	}
	return (*keep_str);
}

static int		check_fd_create_l(const int *fd, char **keep_str, char **line)
{
	static int	temp_fd = 0;

	if (temp_fd != *fd)
	{
		temp_fd = *fd;
		if (keep_str)
			ft_strdel(keep_str);
	}
	if (*fd < 0 || *fd > 4096 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (*keep_str == NULL)
		if (!(*keep_str = ft_strnew(BUFF_SIZE)))
			return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				i;
	char			*temp;
	static char		*keep_str = NULL;

	if (check_fd_create_l(&fd, &keep_str, line) == -1)
		return (-1);
	if (keep_str)
		if ((keep_str = read_line(fd, &keep_str)) == 0)
			return (-1);
	i = 0;
	if (keep_str[i] != '\0')
	{
		while (keep_str[i] != '\n' && keep_str[i] != '\0')
			i++;
		(*line) = ft_strsub(keep_str, 0, i);
		if (keep_str[i] == '\n')
			i++;
		temp = ft_strsub(keep_str, i, (int)ft_strlen(keep_str) - i);
		free(keep_str);
		keep_str = temp;
		return (1);
	}
	return (0);
}
