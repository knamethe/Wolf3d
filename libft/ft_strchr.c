/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 09:25:49 by knamethe          #+#    #+#             */
/*   Updated: 2018/06/05 08:01:28 by knamethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*st;

	st = (char *)s;
	while (*st != c)
	{
		if (*st == '\0')
		{
			return (NULL);
		}
		st++;
	}
	return (st);
}
