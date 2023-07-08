/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointeur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:53:13 by pjay              #+#    #+#             */
/*   Updated: 2022/11/17 11:20:25 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	countnb16(uintptr_t p)
{
	int	i;

	i = 0;
	while (p)
	{
		i++;
		p /= 16;
	}
	return (i);
}

void	printptr(uintptr_t p)
{
	if (p >= 16)
	{
		printptr(p / 16);
		printptr(p % 16);
	}
	else if (p <= 9)
	{
		ft_putchar(p + '0');
	}
	else
		ft_putchar(p + 'a' - 10);
}

int	checkptr(uintptr_t p)
{
	int	count;

	count = 0;
	if (!p)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		count = 2;
		printptr(p);
		count += countnb16(p);
		return (count);
	}
}
