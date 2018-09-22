/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 13:21:47 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/02 19:21:05 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char *sorc;
	char *dest;

	dest = (char *)s1;
	sorc = (char *)s2;
	while (*dest)
		dest++;
	while (*sorc)
	{
		*dest = *sorc;
		dest++;
		sorc++;
	}
	*dest = '\0';
	return (s1);
}
