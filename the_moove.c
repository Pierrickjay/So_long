/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_moove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:02:04 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 11:15:21 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_collectible(t_data *data)
{
	if (data->map[data->img.player_1.pos_x / 48]
		[data->img.player_1.pos_y / 48] == 'C')
	{
		data->img.player_1.collectible++;
		data->map[data->img.player_1.pos_x / 48]
		[data->img.player_1.pos_y / 48] = '0';
	}
}

int	moove_up(t_data *data, int i)
{
	int	count;

	count = 0;
	if (data->map[(data->img.player_1.pos_x - 48) / 48]
		[data->img.player_1.pos_y / 48] != '1')
	{
		if (data->map[(data->img.player_1.pos_x - 48) / 48]
			[data->img.player_1.pos_y / 48] == 'E'
			&& data->img.player_1.collectible != data->collectible)
			return (0);
		make_the_moove(data, -48, 'x', i);
		add_collectible(data);
		count++;
	}
	if (data->map[data->img.player_1.pos_x / 48]
		[data->img.player_1.pos_y / 48] == 'E'
		&& data->img.player_1.collectible == data->collectible)
	{
		ft_printf("You finished the game !!!!\n");
		ft_printf("thx to @ansimuz && @o_lobster for the sprites\n");
		hollywood_free(data);
	}
	return (count);
}

int	moove_down(t_data *data, int i)
{
	int	count;

	count = 0;
	if (data->map[(data->img.player_1.pos_x + 48) / 48]
		[data->img.player_1.pos_y / 48] != '1' )
	{
		if (data->map[(data->img.player_1.pos_x + 48) / 48]
			[data->img.player_1.pos_y / 48] == 'E'
			&& data->img.player_1.collectible != data->collectible)
			return (0);
		make_the_moove(data, 48, 'x', i);
		add_collectible(data);
		count++;
	}
	if (data->map[data->img.player_1.pos_x / 48]
		[data->img.player_1.pos_y / 48] == 'E'
		&& data->img.player_1.collectible == data->collectible)
	{
		ft_printf("You finished the game !!!!\n");
		ft_printf("thx to @ansimuz && @o_lobster for the sprites\n");
		hollywood_free(data);
	}
	return (count);
}

int	moove_left(t_data *data, int i)
{
	int	count;

	count = 0;
	if (data->map[data->img.player_1.pos_x / 48]
		[(data->img.player_1.pos_y - 48) / 48] != '1')
	{
		if (data->map[data->img.player_1.pos_x / 48]
			[(data->img.player_1.pos_y - 48) / 48] == 'E'
			&& data->img.player_1.collectible != data->collectible)
			return (0);
		make_the_moove(data, -48, 'y', i);
		add_collectible(data);
		count++;
	}
	if (data->map[data->img.player_1.pos_x / 48]
		[data->img.player_1.pos_y / 48] == 'E'
		&& data->img.player_1.collectible == data->collectible)
	{
		ft_printf("You finished the game !!!!\n");
		ft_printf("thx to @ansimuz && @o_lobster for the sprites\n");
		hollywood_free(data);
	}
	return (count);
}

int	moove_right(t_data *data, int i)
{
	int	count;

	count = 0;
	if (data->map[data->img.player_1.pos_x / 48]
		[(data->img.player_1.pos_y + 48) / 48] != '1')
	{
		if (data->map[data->img.player_1.pos_x / 48]
			[(data->img.player_1.pos_y + 48) / 48] == 'E'
			&& data->img.player_1.collectible != data->collectible)
			return (0);
		make_the_moove(data, +48, 'y', i);
		add_collectible(data);
		count++;
	}
	if (data->map[data->img.player_1.pos_x / 48]
		[data->img.player_1.pos_y / 48] == 'E'
		&& data->img.player_1.collectible == data->collectible)
	{
		ft_printf("You finished the game !!!!\n");
		ft_printf("thx to @ansimuz && @o_lobster for the sprites\n");
		hollywood_free(data);
	}
	return (count);
}
