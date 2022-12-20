/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:47:19 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 11:17:27 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hollywood_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	mlx_destroy_image(data->mlx, data->img.floor.ptr);
	mlx_destroy_image(data->mlx, data->img.door.ptr);
	mlx_destroy_image(data->mlx, data->img.fiole.ptr);
	mlx_destroy_image(data->mlx, data->img.empty.ptr);
	mlx_destroy_image(data->mlx, data->img.player_1.ptr[0]);
	mlx_destroy_image(data->mlx, data->img.player_1.ptr[1]);
	mlx_destroy_image(data->mlx, data->img.player_1.ptr[2]);
	mlx_destroy_image(data->mlx, data->img.player_1.ptr[3]);
	free(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}
