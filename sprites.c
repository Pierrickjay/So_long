/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:27:11 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 11:15:36 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_hero(t_data *data)
{
	data->img.player_1.ptr[0] = mlx_xpm_file_to_image(data->mlx,
			"./sprites/hero_run_0.xpm", &data->img.player_1.spr_h,
			&data->img.player_1.spr_l);
	data->img.player_1.ptr[1] = mlx_xpm_file_to_image(data->mlx,
			"./sprites/hero_run_1.xpm",
			&data->img.player_1.spr_h, &data->img.player_1.spr_l);
	data->img.player_1.ptr[2] = mlx_xpm_file_to_image(data->mlx,
			"./sprites/hero_run_2.xpm",
			&data->img.player_1.spr_h, &data->img.player_1.spr_l);
	data->img.player_1.ptr[3] = mlx_xpm_file_to_image(data->mlx,
			"./sprites/hero_run_3.xpm", &data->img.player_1.spr_h,
			&data->img.player_1.spr_l);
}

void	set_image(t_data *data)
{
	int	count;

	count = 0;
	set_hero(data);
	data->img.floor.ptr = mlx_xpm_file_to_image(data->mlx,
			"./sprites/sol.xpm",
			&data->img.floor.spr_h, &data->img.floor.spr_l);
	data->img.door.ptr = mlx_xpm_file_to_image(data->mlx,
			"./sprites/door_close.xpm", &data->img.door.spr_h,
			&data->img.door.spr_l);
	data->img.fiole.ptr = mlx_xpm_file_to_image(data->mlx,
			"./sprites/fiole_mini.xpm",
			&data->img.fiole.spr_h, &data->img.fiole.spr_l);
	data->img.empty.ptr = mlx_xpm_file_to_image(data->mlx,
			"./sprites/empty.xpm",
			&data->img.empty.spr_h, &data->img.empty.spr_l);
	data->img.player_1.collectible = 0;
	data->collectible = 0;
	while (data->map[count])
		count++;
	data->size_h = count * 48;
	data->size_l = (ft_strlen(data->map[0]) * 48);
}

void	set_wall_player(t_data *data, char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img.floor.ptr, y * 48, x * 48);
			if (map[x][y] == 'P')
			{
				data->img.player_1.pos_x = x * 48;
				data->img.player_1.pos_y = y * 48;
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img.player_1.ptr[0], data->img.player_1.pos_y,
					data->img.player_1.pos_x);
			}
		}
	}
}

void	set_exit_collectible(t_data *data, char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img.door.ptr, y * 48, x * 48);
			if (map[x][y] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->img.fiole.ptr, (y * 48) + 24, (x * 48) + 24);
				data->collectible++;
			}
		}
	}
}
