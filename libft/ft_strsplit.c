/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 17:42:43 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 19:13:00 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int				counter;
	unsigned int	i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (counter);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char *newstr;

	newstr = (char *)malloc(sizeof(char) * n + 1);
	if (newstr == NULL)
		return (NULL);
	newstr = ft_strncpy(newstr, (char *)s, n);
	newstr[n] = '\0';
	return (newstr);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		n;
	int		j;
	char	**tab;

	i = 0;
	n = 0;
	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c)) + 1);
	if (tab == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tab[n++] = ft_strndup(s + j, i - j);
	}
	tab[n] = NULL;
	return (tab);
}
