/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 13:06:46 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 19:15:57 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dest;
	const char		*sorc;
	size_t			i;

	dest = (char *)dst;
	sorc = (char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}
