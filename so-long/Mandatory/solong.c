/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:39:03 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 04:09:42 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
	{
		ft_printf ("Erorr !!\n./solong  <Map name.ber>\n");
		return (0);
	}
	zeroos(&data);
	read_map(&data, av[1]);
	save_map(&data, av[1]);
	data.mlx_connect = mlx_init();
	if (!data.mlx_connect)
		err(25, "Error\nmlx connection failed\n");
	data.mlx_wind = mlx_new_window(data.mlx_connect, \
					data.colums * 50, data.rows * 50, "So-Long");
	if (!data.mlx_wind)
		err(25, "Error\nmlx connection failed\n");
	put_map(&data);
	mlx_hook(data.mlx_wind, 2, 0, key_handle, &data);
	mlx_hook(data.mlx_wind, 17, 0, free_mlx, &data);
	mlx_loop(data.mlx_connect);
	free_mlx(&data, 0);
}
