/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 19:23:59 by vkozhemi          #+#    #+#             */
/*   Updated: 2018/04/03 14:55:51 by vkozhemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newlisty;

	newlisty = (t_list *)malloc(sizeof(*newlisty));
	if (newlisty == NULL)
		return (NULL);
	if (content == NULL)
	{
		newlisty->content = NULL;
		newlisty->content_size = 0;
	}
	else
	{
		newlisty->content = malloc(content_size);
		if (newlisty->content == NULL)
		{
			free(newlisty);
			return (NULL);
		}
		ft_memcpy(newlisty->content, content, content_size);
		newlisty->content_size = content_size;
	}
	newlisty->next = NULL;
	return (newlisty);
}
