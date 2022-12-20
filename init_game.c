/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:59:42 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 14:59:02 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_data *data)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	data->mlx = mlx_init();
	set_image(data);
	data->mlx_win = mlx_new_window(data->mlx, data->size_l, data->size_h,
			"SOOOOOOLONGGG!");
	set_hooks(data);
	set_wall_player(data, data->map);
	set_exit_collectible(data, data->map);
}

int	init_map(char *av, t_data *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(av, O_RDWR);
	if (fd == -1)
		return (0);
	data->map = ft_mapped(fd);
	if (ft_check_map(data->map) == 1 || close(fd) == -1)
	{
		i = 0;
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		return (0);
	}
	i = 0;
	return (1);
}
