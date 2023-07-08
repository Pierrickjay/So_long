/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:39:43 by pjay              #+#    #+#             */
/*   Updated: 2022/11/17 11:57:36 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	for_c_and_s(va_list args, char pos)
{
	char	c;
	char	*s;

	if (pos == 'c')
	{
		c = (char)va_arg(args, int);
		write(1, &c, 1);
		return (1);
	}
	else
	{
		s = va_arg(args, char *);
		return (ft_putstr(s));
	}
}

int	for_p_and_di(va_list args, char pos)
{
	uintptr_t	p;
	int			d;

	if (pos == 'p')
	{
		p = (uintptr_t) va_arg(args, void *);
		return (checkptr(p));
	}
	else
	{
		d = va_arg(args, int);
		ft_putnbr_int(d);
		return (ft_countnb(d));
	}
}

int	for_xux(va_list args, char pos)
{
	unsigned int	u;
	unsigned int	d;
	int				count;

	count = 0;
	if (pos == 'x')
	{
		d = va_arg(args, unsigned int);
		return (ft_putnbr_base(d, "0123456789abcdef", count));
	}
	else if (pos == 'u')
	{
		u = va_arg(args, unsigned int);
		return (printunsigned(u));
	}
	else
	{
		d = va_arg(args, unsigned int);
		return (ft_putnbr_base(d, "0123456789ABCDEF", count));
	}
}

int	find(char pos, va_list args)
{
	if (pos == 'c' || pos == 's')
		return (for_c_and_s(args, pos));
	if (pos == 'p' || pos == 'd' || pos == 'i')
		return (for_p_and_di(args, pos));
	if (pos == 'x' || pos == 'u' || pos == 'X')
		return (for_xux(args, pos));
	else
		return (ft_putchar1('%'));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	parametersinfo;

	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(parametersinfo, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += find(str[i + 1], parametersinfo);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(parametersinfo);
	return (count);
}
