/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:43:55 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 02:32:47 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	err(int i, char *msg)
{
	if (i == 25 || i == -1)
		ft_malloc(0, 0);
	if (msg)
		ft_printf("%s", msg);
	exit(0);
}

void	map_err(int i, int fd, char *msg)
{
	if (fd != -1)
		close(fd);
	if (i == 25)
		err(25, msg);
	err(0, NULL);
}

void	free2(t_game *data)
{
	if (data->txt.player[0])
		mlx_destroy_image(data->mlx_connect, data->txt.player[0]);
	if (data->txt.player[1])
		mlx_destroy_image(data->mlx_connect, data->txt.player[1]);
	if (data->txt.player[2])
		mlx_destroy_image(data->mlx_connect, data->txt.player[2]);
	if (data->txt.player[3])
		mlx_destroy_image(data->mlx_connect, data->txt.player[3]);
	if (data->txt.exit[0])
		mlx_destroy_image(data->mlx_connect, data->txt.exit[0]);
	if (data->txt.exit[1])
		mlx_destroy_image(data->mlx_connect, data->txt.exit[1]);
}

int	free_mlx(t_game *data, int mode)
{
	if (data->txt.collectible)
		mlx_destroy_image(data->mlx_connect, data->txt.collectible);
	if (data->txt.floor)
		mlx_destroy_image(data->mlx_connect, data->txt.floor);
	if (data->txt.wall)
		mlx_destroy_image(data->mlx_connect, data->txt.wall);
	if (data->txt.anm[0])
		mlx_destroy_image(data->mlx_connect, data->txt.anm[0]);
	if (data->txt.anm[1])
		mlx_destroy_image(data->mlx_connect, data->txt.anm[1]);
	if (data->txt.anm[2])
		mlx_destroy_image(data->mlx_connect, data->txt.anm[2]);
	free2(data);
	if (mode == 69)
	{
		if (data->mlx_wind)
			mlx_destroy_window(data->mlx_connect, data->mlx_wind);
		err(25, "Error\nMlx function failed\n");
	}
	if (data->mlx_wind)
		mlx_destroy_window(data->mlx_connect, data->mlx_wind);
	ft_malloc(0, 0);
	exit(0);
}
