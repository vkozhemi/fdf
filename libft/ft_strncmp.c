/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:42:14 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 17:43:50 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t j;

	j = 0;
	if (n == 0)
		return (0);
	while ((s1[j] != '\0' || s2[j] != '\0') && s1[j] == s2[j] && j < n)
		j++;
	if (j == n)
		return ((unsigned char)s1[j - 1] - (unsigned char)s2[j - 1]);
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
