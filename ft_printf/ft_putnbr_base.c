/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:36:32 by pjay              #+#    #+#             */
/*   Updated: 2022/11/17 11:21:13 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printit(unsigned int nbr, char *base, unsigned int baselen, int count)
{
	if (nbr > baselen - 1)
	{
		count = ft_printit(nbr / baselen, base, baselen, count);
		nbr %= baselen;
	}
	write(1, &base[nbr], 1);
	return (count + 1);
}

int	ft_putnbr_base(unsigned int nbr, char *base, int count)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	return (ft_printit(nbr, base, i, count));
}
