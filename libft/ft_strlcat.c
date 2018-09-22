/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:29:47 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 18:59:26 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t j;
	size_t i;

	j = 0;
	while (j < dstsize && dst[j])
		j++;
	i = 0;
	while ((src[i]) && ((j + i + 1) < dstsize))
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j != dstsize)
		dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
