/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:45:04 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/04 02:31:23 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

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
	put_map(data);
	mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
			data->txt.player, data->ply_y * 50, data->ply_x * 50);
	return (0);
}

void	set_img_to_ptr(t_game *data)
{
	static int	n;
	int			x;
	int			y;

	if (n == 99)
		return ;
	n = 99;
	x = 50;
	y = x;
	data->txt.player = mlx_xpm_file_to_image(data->mlx_connect, \
		"./Mandatory/textures/player.xpm", &x, &y);
	data->txt.wall = mlx_xpm_file_to_image(data->mlx_connect, \
	"./Mandatory/textures/wall.xpm", &x, &y);
	data->txt.exit = mlx_xpm_file_to_image(data->mlx_connect, \
	"./Mandatory/textures/exit.xpm", &x, &y);
	data->txt.collectible = mlx_xpm_file_to_image(data->mlx_connect, \
	"./Mandatory/textures/coins.xpm", &x, &y);
	data->txt.floor = mlx_xpm_file_to_image(data->mlx_connect, \
	"./Mandatory/textures/floor.xpm", &x, &y);
	if (!data->txt.player || !data->txt.wall || !data->txt.exit \
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
	if (type != '1' && type != '0')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
			data->txt.floor, x, y);
	if (type == 'E')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
								data->txt.exit, x, y);
	if (type == 'P')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
							data->txt.player, x, y);
	if (type == 'C')
		mlx_put_image_to_window(data->mlx_connect, data->mlx_wind, \
								data->txt.collectible, x, y);
}

void	put_map(t_game	*data)
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
			put_img(data->map[y][x], x * 50, y * 50, data);
			x++;
		}
		y++;
	}
}
