/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:35:57 by pjay              #+#    #+#             */
/*   Updated: 2023/07/08 15:51:39 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_search_string(char *str, char *cmp)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (cmp[y] == '\0' && str[i] == '\0')
		return (1);
	while (str[i])
	{
		while (str[i + y] == cmp[y] && str[i + y] && cmp[y])
			y++;
		if (cmp[y] == '\0' && str[i + y] == '\0')
			return (1);
		else
			y = 0;
		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	if (ac != 2 || *env == NULL || env == NULL)
		return (0);
	if (ft_search_string(av[1], ".ber") != 1)
	{
		ft_printf("La map n'a pas le format valide\n");
		ft_printf("La map doit avoir le format .ber");
		return (0);
	}
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	if (init_map(av[1], data) == 0)
	{
		free(data);
		return (0);
	}
	init_game(data);
	mlx_loop(data->mlx);
}
