/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 14:42:25 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 17:41:50 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*sorc1;
	char	*dest1;

	sorc1 = (char *)src;
	dest1 = (char *)dst;
	if (sorc1 < dest1)
	{
		while (len--)
			dest1[len] = sorc1[len];
	}
	else
		ft_memcpy(dest1, sorc1, len);
	return (dest1);
}
