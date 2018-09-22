/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:18:43 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 19:09:04 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		leng;
	int		j;
	char	*newstr;

	leng = 0;
	while (s1[leng] != '\0')
		leng++;
	newstr = (char *)malloc(sizeof(char) * (leng + 1));
	if (newstr == NULL)
		return (NULL);
	j = 0;
	while (j < leng)
	{
		newstr[j] = s1[j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
