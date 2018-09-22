/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:10:20 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 18:39:28 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int j;

	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (s1[j] != '\0' && s2[j] != '\0' && s1[j] == s2[j])
		j++;
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
