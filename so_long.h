/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:36:50 by pjay              #+#    #+#             */
/*   Updated: 2022/12/16 15:13:30 by pjay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <time.h>
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "./pathing/get_next_line.h"
# include "./ft_printf/libftprintf.h"

# define L_WIN 1152
# define H_WIN 240

typedef struct s_hero
{
	void	*ptr[4];
	int		spr_h;
	int		spr_l;
	int		pos_x;
	int		pos_y;
	int		collectible;
}	t_hero;

typedef struct s_sprits
{
	void	*ptr;
	int		spr_h;
	int		spr_l;
	int		pos_x;
	int		pos_y;
	int		collectible;

}	t_sprits;

typedef struct s_img
{
	t_sprits	floor;
	t_hero		player_1;
	t_sprits	door;
	t_sprits	fiole;
	t_sprits	empty;
	t_sprits	background;

}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	char	**map;
	int		collectible;
	int		size_l;
	int		size_h;

}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_a_square(t_data *data, int size_l, int size_h, int color);
int		key_press_hook(int keycode, t_data *data);
int		mouse_hook(int keycode, t_data*data);
void	set_hooks(t_data *data);
void	set_image(t_data *data);
int		init_map(char *av, t_data *data);
void	init_game(t_data *data);
void	set_wall_player(t_data *data, char **map);
void	set_moove_player(int keycode, t_data *data);
void	set_exit_collectible(t_data *data, char **map);
int		moove_up(t_data *data, int i);
int		moove_down(t_data *data, int i);
int		moove_left(t_data *data, int i);
int		moove_right(t_data *data, int i);
void	make_the_moove(t_data *data, int to_add, char c, int i);
void	hollywood_free(t_data *data);

#endif
