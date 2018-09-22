/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:09:51 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 16:34:16 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			newstr[i] = f(i, s[i]);
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
	return (NULL);
}
