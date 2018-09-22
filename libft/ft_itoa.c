/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 14:11:31 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 16:54:48 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *newstr;

	newstr = (char *)malloc(sizeof(char) * 2);
	if (newstr == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		newstr[0] = '-';
		newstr[1] = '\0';
		newstr = ft_strjoin(newstr, ft_itoa(-n));
	}
	else if (n >= 0 && n < 10)
	{
		newstr[0] = n + '0';
		newstr[1] = '\0';
	}
	else if (n >= 10)
		newstr = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	return (newstr);
}
