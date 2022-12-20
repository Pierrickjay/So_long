/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:26:25 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 11:16:00 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	deal_w_x(t_data *data, int to_add, int i)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img.empty.ptr,
		data->img.player_1.pos_y, data->img.player_1.pos_x);
	data->img.player_1.pos_x += to_add;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img.player_1.ptr[i],
		data->img.player_1.pos_y, data->img.player_1.pos_x);
}

void	deal_w_y(t_data *data, int to_add, int i)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img.empty.ptr,
		data->img.player_1.pos_y, data->img.player_1.pos_x);
	data->img.player_1.pos_y += to_add;
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img.player_1.ptr[i],
		data->img.player_1.pos_y, data->img.player_1.pos_x);
}

void	make_the_moove(t_data *data, int to_add, char c, int i)
{
	if (c == 'x')
		deal_w_x(data, to_add, i);
	if (c == 'y')
		deal_w_y(data, to_add, i);
}
