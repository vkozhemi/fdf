/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:59:37 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 18:41:06 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*newstr;
	unsigned int	i;

	if (f && s)
	{
		i = 0;
		newstr = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
		if (newstr == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			newstr[i] = f(s[i]);
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
