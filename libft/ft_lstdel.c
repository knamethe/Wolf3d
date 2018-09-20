/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 12:46:44 by knamethe          #+#    #+#             */
/*   Updated: 2018/08/28 12:46:48 by knamethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*lnext;

	list = *alst;
	while (list)
	{
		lnext = list->next;
		del(list->content, list->content_size);
		free(list);
		list = lnext;
	}
	*alst = NULL;
}
