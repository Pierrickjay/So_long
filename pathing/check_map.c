/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:21:38 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 11:11:52 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_wall(char **str)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (str[count])
		count++;
	while (str[++i])
	{
		j = 0;
		if (i == 0 || i == count)
		{
			while (j < ft_strlen(str[i]))
			{
				if (str[i][j] != '1')
					return (1);
				j++;
			}
		}
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
			return (1);
	}
	return (0);
}

int	check_door(char **str)
{
	int	i;
	int	j;
	int	count;
	int	diff;

	i = -1;
	count = 0;
	diff = 0;
	while (str[count])
		count++;
	while (str[++i])
	{
		j = -1;
		while (++j < ft_strlen(str[i]))
			if (str[i][j] == 'E')
				diff++;
	}
	if (diff != 1)
		return (1);
	return (0);
}

int	check_player_p(char **str)
{
	int	i;
	int	j;
	int	count;
	int	diff;

	i = -1;
	count = 0;
	diff = 0;
	while (str[count])
		count++;
	while (str[++i])
	{
		j = -1;
		while (++j < ft_strlen(str[i]))
			if (str[i][j] == 'P')
				diff++;
	}
	if (diff != 1)
		return (1);
	return (0);
}

int	check_object(char **str)
{
	int	i;
	int	j;
	int	count;
	int	diff;

	i = -1;
	count = 0;
	diff = 0;
	while (str[count])
		count++;
	while (str[++i])
	{
		j = -1;
		while (++j < ft_strlen(str[i]))
			if (str[i][j] == 'C')
				diff++;
	}
	if (diff < 1)
		return (1);
	return (0);
}

int	ft_check_map(char **str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	count += check_wall(str);
	count += check_door(str);
	count += check_object(str);
	count += check_player_p(str);
	count += check_rectangle(str);
	if (count != 0)
	{
		write(1, "Error\nThe map is not valid\nPlease do something\n", 47);
		return (1);
	}
	else
		ft_printf("ok it's valid dude\n");
	return (0);
}
