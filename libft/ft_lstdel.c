/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 16:52:37 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 14:38:39 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *temper;

	temper = *alst;
	if (del != NULL && alst && *alst)
	{
		while (temper != NULL)
		{
			next = temper->next;
			del(temper->content, temper->content_size);
			free(temper);
			temper = next;
		}
		*alst = NULL;
	}
}
