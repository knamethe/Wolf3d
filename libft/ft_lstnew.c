/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:49:25 by knamethe          #+#    #+#             */
/*   Updated: 2018/08/28 12:49:29 by knamethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = NULL;
	list->next = NULL;
	if (content == NULL)
		list->content_size = 0;
	else
	{
		list->content_size = content_size;
		if ((list->content = (void *)malloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy((list->content), content, content_size);
	}
	return (list);
}
