/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 15:17:46 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 19:03:12 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t begin;
	size_t leng;

	begin = 0;
	if (s == NULL)
		return (NULL);
	while (s[begin] == ' ' || s[begin] == '\n' || s[begin] == '\t')
		begin++;
	if (s[begin] == '\0')
		return (ft_strdup(s + begin));
	leng = ft_strlen(s) - 1;
	while ((s[leng] == ' ' || s[leng] == '\n' || s[leng] == '\t') && leng > 0)
		leng--;
	return (ft_strsub(s, begin, leng - begin + 1));
}
