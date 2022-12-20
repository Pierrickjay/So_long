/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:27:31 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 11:11:02 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_rectangle(char **str)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == NULL)
			break ;
		tmp = ft_strlen(str[i]);
		if (tmp != ft_strlen(str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}
