/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copysign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamethe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:58:48 by knamethe          #+#    #+#             */
/*   Updated: 2018/08/28 09:58:53 by knamethe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_copysign(double n1, double n2)
{
	if (n2 < 0 || (1.0 / n2) < 0)
		n1 *= -1;
	return (n1);
}