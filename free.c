/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <pjay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:47:19 by pjay              #+#    #+#             */
/*   Updated: 2023/07/08 16:21:12 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	del_img(t_data *data)
{
	if (data->img.floor.ptr)
		mlx_destroy_image(data->mlx, data->img.floor.ptr);
	if (data->img.door.ptr)
		mlx_destroy_image(data->mlx, data->img.door.ptr);
	if (data->img.fiole.ptr)
		mlx_destroy_image(data->mlx, data->img.fiole.ptr);
	if (data->img.empty.ptr)
		mlx_destroy_image(data->mlx, data->img.empty.ptr);
	if (data->img.player_1.ptr[0])
		mlx_destroy_image(data->mlx, data->img.player_1.ptr[0]);
	if (data->img.player_1.ptr[1])
		mlx_destroy_image(data->mlx, data->img.player_1.ptr[1]);
	if (data->img.player_1.ptr[2])
		mlx_destroy_image(data->mlx, data->img.player_1.ptr[2]);
	if (data->img.player_1.ptr[3])
		mlx_destroy_image(data->mlx, data->img.player_1.ptr[3]);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		printf("freeing %d\n", i);
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	if (data->map)
		free(data->map);
	del_img(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data);
	exit(0);
}

void	hollywood_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	del_img(data);
	free(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	exit(0);
}
