/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:11:58 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/02 02:38:38 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	do_move(t_game *data, int r, int c)
{
	if (r == data->ply_x && c == data->ply_y)
		return ;
	if (data->map[r][c] != '1' && data->map[r][c] != 'E')
	{
		if (data->map[r][c] == 'C')
		{
			data->map[r][c] = '0';
			data->collec++;
		}
		data->ply_x = r;
		data->ply_y = c;
	}
	else if (data->map[r][c] == 'E' && data->collec == data->total_collec)
	{
		ft_printf("Moves = %d\nYou won\n", data->move);
		free_mlx(data, 0);
	}
	if (r == data->ply_x && c == data->ply_y)
		ft_printf("Moves = %d\n", data->move++);
}
