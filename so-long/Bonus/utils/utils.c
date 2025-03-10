/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:00:26 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/04 00:30:32 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	draw_move_counter(t_game *data)
{
	int			i;
	char		*move_text;

	i = 7;
	move_text = ft_itoa(data->move);
	while (i <= 9)
	{
		mlx_put_image_to_window(data->mlx_connect, \
			data->mlx_wind, data->txt.floor, i * 10, 0);
		i++;
	}
	mlx_string_put(data->mlx_connect, data->mlx_wind, 10, 0, \
		0xFFFFFF, "Moves:");
	mlx_string_put(data->mlx_connect, data->mlx_wind, 75, 0, \
		0xFFFFFF, move_text);
}

int	frame(t_game *data)
{
	data->frame_count++;
	if (data->frame_count > 5000)
	{
		data->frame = (data->frame + 1) % 3;
		data->frame_count = 0;
	}
	return (0);
}

void	check_ply_position(t_game *data, int r, int c)
{
	if (data->ply_x < r)
		data->pos = 3;
	else if (data->ply_x > r)
		data->pos = 2;
	else if (data->ply_y < c)
		data->pos = 0;
	else if (data->ply_y > c)
		data->pos = 1;
}
