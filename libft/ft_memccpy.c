/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:26:40 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 19:15:05 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*sorc2;
	char	*dest2;

	i = 0;
	sorc2 = (char *)src;
	dest2 = (char *)dst;
	while (i < n)
	{
		dest2[i] = sorc2[i];
		if ((unsigned char)sorc2[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (NULL);
}
