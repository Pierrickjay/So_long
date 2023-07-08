/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:21:08 by pjay              #+#    #+#             */
/*   Updated: 2022/11/17 11:57:13 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_countnb(int nb)
{
	int				i;
	unsigned int	a;

	i = 0;
	if (nb < 0)
	{
		i++;
		a = nb * -1;
	}
	else
		a = nb;
	if (a == 0)
		return (1);
	while (a)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	countnb_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
