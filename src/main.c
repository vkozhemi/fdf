/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:08:51 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/06/14 16:11:46 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	read_file(char **argv, int count_line, int lenght_line)
{
	t_dots	*ptr;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	ptr = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		create_struct(line, &ptr, count_line, lenght_line);
		free(line);
	}
	close(fd);
	find_next_link(ptr);
}

int		count_elements(const char *str, int j, int res)
{
	char	**s;
	int		i;

	j = 0;
	s = ft_strsplit(str, ' ');
	while (s[res] != NULL)
		res++;
	while (s[j] != NULL)
	{
		i = 0;
		while (s[j][i] != '\0')
		{
			if ((!ft_isdigit(s[j][i]) && s[j][i] != 45 &&
				!ft_isdigit(s[j][i + 1]) && !ft_isalpha(s[j][i])) ||
				(s[j][i] == 44 && s[j][i + 1] != '0' && s[j][i + 2] != 'x'))
				return (-1);
			i++;
		}
		j++;
	}
	while (j--)
		free(s[j]);
	free(s);
	return (res);
}

int		ft_gnl(int fd, int *count_line, int *lenght_line, int temp)
{
	int		gnl;
	char	*line;

	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		*lenght_line = count_elements(line, 0, 0);
		if (*lenght_line == -1)
			exit_error(2);
		if (temp != *lenght_line && *count_line != 0)
			exit_error(1);
		temp = *lenght_line;
		(*count_line)++;
		free(line);
	}
	if (gnl == -1)
		exit_error(3);
	return (0);
}

void	exit_error(int flag)
{
	if (flag == 1)
		ft_putendl("ERROR: invalid lenght of line in map");
	else if (flag == 2)
		ft_putendl("ERROR: invalid char in map");
	else if (flag == 3)
		ft_putendl("Usage: ./fdf [file]");
	else if (flag == 4)
		ft_putendl("Open error");
	else if (flag == 5)
		ft_putendl("Empty file");
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		temp;
	char	*line;
	int		count_line;
	int		lenght_line;

	temp = 0;
	count_line = 0;
	lenght_line = 0;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	if (!line)
		exit_error(5);
	ft_gnl(fd, &count_line, &lenght_line, temp);
	close(fd);
	read_file(argv, count_line, lenght_line);
	if (argc != 2)
		exit_error(3);
	if (fd == -1)
		exit_error(4);
	return (0);
}
