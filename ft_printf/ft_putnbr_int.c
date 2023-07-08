/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:48:42 by pjay              #+#    #+#             */
/*   Updated: 2022/11/16 17:43:20 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_int(int nb)
{
	unsigned int	b;

	if (nb < 0)
	{
		b = nb * -1;
		ft_putchar('-');
	}
	else
	{
		b = nb;
	}
	if (b >= 10)
	{
		ft_putnbr_int(b / 10);
		ft_putnbr_int(b % 10);
	}
	else
	{
		ft_putchar(b + 48);
	}
}
