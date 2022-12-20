/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:56:51 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 11:44:27 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		hollywood_free(data);
	if (keycode == 119 || keycode == 65362 || keycode == 115 || keycode == 65364
		|| keycode == 97 || keycode == 65361 || keycode == 100
		|| keycode == 65363)
		set_moove_player(keycode, data);
	return (0);
}

void	set_moove_player(int keycode, t_data *data)
{
	static int	i = 0;
	static int	mvcount = 0;

	if (i == 4)
			i = 0;
	if (keycode == 119 || keycode == 65362)
		mvcount += moove_up(data, i++);
	if (keycode == 115 || keycode == 65364)
		mvcount += moove_down(data, i++);
	if (keycode == 97 || keycode == 65361)
		mvcount += moove_left(data, i++);
	if (keycode == 100 || keycode == 65363)
		mvcount += moove_right(data, i++);
	ft_printf("Nombre de deplacement = %d\n", mvcount);
}

int	exit_hook(t_data *data)
{
	hollywood_free(data);
	return (0);
}

void	set_hooks(t_data *data)
{
	mlx_key_hook(data->mlx_win, &key_press_hook, data);
	mlx_hook(data->mlx_win, 17, 0, &exit_hook, data);
}
