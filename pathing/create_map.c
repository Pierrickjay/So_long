/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:34:48 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 14:56:38 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**ft_mapped(int fd)
{
	char	*mappedmap;
	char	*bufferstr;
	char	**splitted;
	int		i;

	i = 0;
	mappedmap = malloc(sizeof(char));
	mappedmap[0] = '\0';
	while (i == 0 || mappedmap != NULL)
	{
		bufferstr = get_next_line(fd);
		if (bufferstr == NULL)
			break ;
		mappedmap = ft_strjoin_2(mappedmap, bufferstr);
		i++;
	}
	splitted = ft_split(mappedmap, '\n');
	i = 0;
	free(mappedmap);
	free(bufferstr);
	return (splitted);
}
