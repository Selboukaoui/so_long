/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:42:05 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/03 04:07:02 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	zeroos(t_game *d)
{
	d->collec = 0;
	d->rows = 0;
	d->colums = 0;
	d->exit = 0;
	d->ply_x = 0;
	d->ply_y = 0;
	d->total_collec = 0;
	d->player = 0;
	d->exit_valid = 0;
	d->move = 0;
	d->frame = 0;
	d->frame_count = 0;
	d->pos = 0;
	d->door = 0;
	d->txt.anm[0] = NULL;
	d->txt.anm[1] = NULL;
	d->txt.anm[2] = NULL;
	d->txt.player[0] = NULL;
	d->txt.player[1] = NULL;
	d->txt.player[2] = NULL;
	d->txt.player[3] = NULL;
	d->txt.exit[0] = NULL;
	d->txt.exit[1] = NULL;
}

void	flood_fill(char **mtrx, int x, int y, t_game *data)
{
	if (x < 0 || y < 0 || x >= data->rows || y >= data->colums)
		return ;
	if (mtrx[x][y] == '1' || mtrx[x][y] == 'X')
		return ;
	if (mtrx[x][y] == 'C')
		data->collec++;
	if (mtrx[x][y] == 'E')
	{
		data->exit_valid = 1;
		return ;
	}
	mtrx[x][y] = 'X';
	flood_fill(mtrx, x + 1, y, data);
	flood_fill(mtrx, x - 1, y, data);
	flood_fill(mtrx, x, y + 1, data);
	flood_fill(mtrx, x, y - 1, data);
}

int	lines_equal(char *line, int size)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	return (len == size);
}
