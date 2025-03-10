/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:04 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/04 03:18:27 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

int	key_handle(int key, t_game *data)
{
	int	x;
	int	y;

	x = data->ply_x;
	y = data->ply_y;
	data->map[data->ply_x][data->ply_y] = '0';
	if (key == 0 || key == 123)
		y--;
	else if (key == 2 || key == 124)
		y++;
	else if (key == 13 || key == 126)
		x--;
	else if (key == 1 || key == 125)
		x++;
	else if (key == 53)
		free_mlx(data, 0);
	do_move(data, x, y);
	return (0);
}

void	set2(t_game *data, int x, int y)
{
	data->txt.anm[0] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/left1.xpm", &x, &y);
	data->txt.anm[1] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/front1.xpm", &x, &y);
	data->txt.anm[2] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/player_right.xpm", &x, &y);
	data->txt.player[0] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/player.xpm", &x, &y);
	data->txt.player[1] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/player_left.xpm", &x, &y);
	data->txt.player[2] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/player_up.xpm", &x, &y);
	data->txt.player[3] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/player_down.xpm", &x, &y);
	if (!data->txt.player[0] || !data->txt.anm[0] || \
		!data->txt.anm[1] || !data->txt.anm[2] || \
		!data->txt.player[1] || !data->txt.player[2] || \
		!data->txt.player[3])
	{
		free_mlx(data, 69);
	}
}

void	set_img_to_ptr(t_game *data)
{
	static int	n;
	int			x;
	int			y;

	if (n == 99)
		return ;
	n = 99;
	x = 32;
	y = x;
	data->txt.collectible = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/coin.xpm", &x, &y);
	data->txt.wall = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/wall.xpm", &x, &y);
	data->txt.exit[0] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/close.xpm", &x, &y);
	data->txt.exit[1] = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/open.xpm", &x, &y);
	data->txt.floor = mlx_xpm_file_to_image(data->mlx_connect, \
		"./bonus/textures/floor.xpm", &x, &y);
	set2(data, x, y);
	if (!data->txt.wall || !data->txt.exit[0] || !data->txt.exit[1] \
		|| !data->txt.collectible || !data->txt.floor)
	{
		free_mlx(data, 69);
	}
}

void	put_img(char type, int x, int y, t_game *data)
{
	if (type == '1')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
								data->txt.wall, x, y);
	if (type == '0')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
			data->txt.floor, x, y);
	if (type == 'E')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
								data->txt.exit[data->door], x, y);
	if (type == 'P')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
							data->txt.player[data->pos], x, y);
	if (type == 'C')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
								data->txt.collectible, x, y);
	if (type == 'N')
	{
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
			data->txt.anm[data->frame], x, y);
		move_enmey(data);
	}
	frame(data);
}

int	put_map(t_game	*data)
{
	int	x;
	int	y;

	y = 0;
	set_img_to_ptr(data);
	while (y < data->rows)
	{
		x = 0;
		while (x < data->colums)
		{
			mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
				data->txt.floor, x * SZ, y * SZ);
			put_img(data->map[y][x], x * SZ, y * SZ, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
		data->txt.player[data->pos], data->ply_y * SZ, data->ply_x * SZ);
	draw_move_counter(data);
	return (0);
}
