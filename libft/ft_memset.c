/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:48:12 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 19:17:01 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *j;

	j = (unsigned char *)b;
	while (len > 0)
	{
		j[len - 1] = c;
		len--;
	}
	return (b);
}
