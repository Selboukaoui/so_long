/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:43:55 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 02:31:43 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	err(int i, char *msg)
{
	if (i == 25)
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
	err(0, msg);
}

int	free_mlx(t_game *data, int mode)
{
	if (data->txt.collectible)
		mlx_destroy_image(data->mlx_connect, data->txt.collectible);
	else if (data->txt.exit)
		mlx_destroy_image(data->mlx_connect, data->txt.exit);
	else if (data->txt.floor)
		mlx_destroy_image(data->mlx_connect, data->txt.floor);
	else if (data->txt.player)
		mlx_destroy_image(data->mlx_connect, data->txt.player);
	else if (data->txt.wall)
		mlx_destroy_image(data->mlx_connect, data->txt.wall);
	if (mode == 69)
	{
		if (data->mlx_wind)
			mlx_destroy_window(data->mlx_connect, data->mlx_wind);
		err(25, "Error\nMlx function failed\n");
	}
	if (data->mlx_wind)
		mlx_destroy_window(data->mlx_connect, data->mlx_wind);
	err(25, NULL);
	return (0);
}
