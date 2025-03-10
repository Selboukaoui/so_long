/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stuff_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:41:47 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 03:32:50 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	read_map(t_game *data, char *path)
{
	int		fd;
	char	*line;

	if (!path || !ft_strcmp(path + ft_strlen(path) - 4, ".ber" ))
		map_err(25, -1, "Error\nPath is invalid\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		err(25, "Error\nOpen failed\n");
	line = get_next_line(fd);
	if (!line)
		map_err(25, fd, "Error\nMap is Invalid\n");
	data->colums = ft_strlen(line) - 1;
	while (line)
	{
		if (!lines_equal(line, data->colums))
			map_err(25, fd, "Error\nMap is Invalid\nCheck lines\n");
		line = get_next_line(fd);
		data->rows++;
	}
	close (fd);
	if (data->rows > 45 || data->colums > 80)
		map_err(25, -1, "Error\nMap size is Invalid\n");
}

void	characters_check(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->colums)
		{
			if (data->map[i][j] == 'P')
			{
				1 && (data->ply_x = i, data->ply_y = j);
				data->player++;
			}
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] == 'C')
				data->total_collec++;
			else if (data->map[i][j] != '1' && \
				data->map[i][j] != '0' && data->map[i][j] != 'N')
				map_err(25, -1, "Error\nOnly '0' '1' 'P' 'E' 'C' 'N'\n");
			j++;
		}
		i++;
	}
}

void	corners_check(t_game *data)
{
	int	i;	
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->colums)
		{
			if (data->map[0][j] != '1' || data->map[data->rows - 1][j] != '1')
				map_err(25, -1, "Error\nMap is Invalid\n");
			if (data->map[i][data->colums - 1] != '1' || data->map[i][0] != '1')
				map_err(25, -1, "Error\nMap is Invalid\n");
			j++;
		}
		i++;
	}
	characters_check(data);
	if (data->exit != 1 || data->player != 1 || data->total_collec <= 0)
		map_err(25, -1, "Error\nMap is Invalid arg needed\n");
}

void	route_check(t_game	*data)
{
	char	**map_cpy;
	int		i;

	map_cpy = ft_malloc(sizeof(char *) * data->rows, 1);
	i = 0;
	while (i < data->rows)
	{
		map_cpy[i] = ft_strdup(data->map[i]);
		i++;
	}
	flood_fill(map_cpy, data->ply_x, data->ply_y, data);
	if (data->collec != data->total_collec || data->exit_valid != 1)
		map_err(25, -1, "Error\nMap is invalid\nYou can't WIN\n");
	data->collec = 0;
}

void	save_map(t_game	*data, char *av)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	data->map = ft_malloc(sizeof(char *) * data->rows, 1);
	if (!data->map)
		err(25, "Error\nAllocation failed\n");
	fd = open(av, O_RDONLY);
	if (fd < 0)
		err(25, "Error\nError\nOpne fd failed\n");
	while (i < data->rows)
	{
		line = get_next_line(fd);
		if (!line)
			map_err(25, fd, "Error\nAllocation failed\n");
		data->map[i] = ft_malloc(data->colums + 1, 1);
		if (!data->map[i])
			err(25, "Error\nAllocation failed\n");
		ft_strlcpy(data->map[i], line, data->colums + 1);
		i++;
	}
	close(fd);
	corners_check(data);
	route_check(data);
}
