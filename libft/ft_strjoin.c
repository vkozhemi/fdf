/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 18:47:52 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 19:08:58 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2)) + 1));
	if (nstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		nstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		nstr[i + j] = s2[j];
		j++;
	}
	nstr[i + j] = '\0';
	return (nstr);
}
