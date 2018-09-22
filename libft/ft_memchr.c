/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:09:28 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 19:11:58 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*newstr;

	i = 0;
	newstr = (char *)s;
	while (i < n)
	{
		if ((unsigned char)newstr[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
