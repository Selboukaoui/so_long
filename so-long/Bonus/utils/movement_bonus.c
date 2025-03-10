/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:11:58 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 02:37:06 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	do_move(t_game *data, int r, int c)
{
	if (r == data->ply_x && c == data->ply_y)
		return ;
	if (data->map[r][c] == '0' || data->map[r][c] == 'C')
	{
		if (data->map[r][c] == 'C')
		{
			data->map[r][c] = '0';
			data->collec++;
		}
		check_ply_position(data, r, c);
		data->ply_x = r;
		data->ply_y = c;
	}
	if (data->collec == data->total_collec)
		data->door = 1;
	if (data->map[r][c] == 'N')
		(1 && ft_printf("You Lose \n"), free_mlx(data, 0));
	else if (data->map[r][c] == 'E' && data->collec == data->total_collec)
	{
		ft_printf("You Win \n");
		free_mlx(data, 0);
	}
	if (r == data->ply_x && c == data->ply_y)
		data->move++;
}

void	move2(t_game *data, int *x, int *y, int nbr)
{
	if (nbr == 2)
	{
		if (*y - 1 == data->ply_x && *x == data->ply_y)
		{
			ft_printf("You Lose \n");
			free_mlx(data, 0);
		}
		data->map[*y][*x] = '0';
		data->map[*y - 1][*x] = 'N';
	}
	else if (nbr == 3)
	{
		if (*y + 1 == data->ply_x && *x == data->ply_y)
		{
			ft_printf("You Lose \n");
			free_mlx(data, 0);
		}
		data->map[*y][*x] = '0';
		data->map[*y + 1][*x] = 'N';
		*y = *y + 1;
	}
}

void	move(t_game *data, int *x, int *y, int nbr)
{
	if (nbr == 0)
	{
		if (*y == data->ply_x && *x + 1 == data->ply_y)
		{
			ft_printf("You Lose \n");
			free_mlx(data, 0);
		}
		data->map[*y][*x] = '0';
		data->map[*y][*x + 1] = 'N';
		*x = *x + 1;
	}
	else if (nbr == 1)
	{
		if (*y == data->ply_x && *x - 1 == data->ply_y)
		{
			ft_printf("You Lose \n");
			free_mlx(data, 0);
		}
		data->map[*y][*x] = '0';
		data->map[*y][*x - 1] = 'N';
	}
	move2(data, x, y, nbr);
}

void	init_nbr(t_game *data, int x, int y, int *nbr)
{
	if (y < data->ply_x && data->map[y + 1][x] != '1' \
	&& data->map[y + 1][x] != 'N' && \
	data->map[y + 1][x] != 'C' && data->map[y + 1][x] != 'E')
		*nbr = 3;
	else if (y > data->ply_x && data->map[y - 1][x] != '1' \
	&& data->map[y - 1][x] != 'N' && data->map[y - 1][x] != 'C' \
	&& data->map[y - 1][x] != 'E')
		*nbr = 2;
	else if (x < data->ply_y && data->map[y][x + 1] != '1' \
	&& data->map[y][x + 1] != 'N' && data->map[y][x + 1] != 'C' \
	&& data->map[y][x + 1] != 'E')
		*nbr = 0;
	else if (x > data->ply_y && data->map[y][x - 1] != '1' \
	&& data->map[y][x - 1] != 'N' && data->map[y][x - 1] != 'C' \
	&& data->map[y][x - 1] != 'E')
		*nbr = 1;
	else
		*nbr = 69;
}

void	move_enmey(t_game *data)
{
	int			nbr;
	static int	c ;
	int			x;
	int			y;

	if (c == 50)
	{
		y = 0;
		while (y < data->rows)
		{
			x = 0;
			while (x < data->colums)
			{
				if (data->map[y][x] == 'N')
				{
					init_nbr(data, x, y, &nbr);
					move(data, &x, &y, nbr);
				}
				x++;
			}
			y++;
		}
		c = 0;
	}
	c++;
}
