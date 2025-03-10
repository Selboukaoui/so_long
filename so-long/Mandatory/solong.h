/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:48:44 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 02:31:54 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../ft_printf/ft_printf.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
char	*joining(char const *s1, char const *s2);
char	*search(const char *str, int c);
int		len(const char *str);
char	*duplicate(const char *src);
void	*ft_malloc(size_t size, int mode);

typedef struct img
{
	void		*wall;
	void		*player;
	void		*collectible;
	void		*exit;
	void		*floor;
	struct img	*next;
}	t_img;

typedef struct game_obj
{
	char	**map;
	int		rows;
	int		colums;
	int		ply_x;
	int		ply_y;
	int		collec;
	int		total_collec;
	int		exit;
	int		player;
	int		exit_valid;
	void	*img;
	void	*mlx_connect;
	void	*mlx_wind;
	int		move;
	t_img	txt;
}	t_game;

typedef struct garbage_c
{
	void				*data;
	struct garbage_c	*next;
}	t_collect;

// Utils
long	ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(const char *str);
void	*ft_malloc(size_t size, int mode);
int		ft_strlcpy(char *dst, const char *src, int size);
char	*ft_strdup(const char *src);
void	flood_fill(char **matrice, int x, int y, t_game *data);
int		lines_equal(char *line, int size);

// Map stuff
void	read_map(t_game *data, char *path);
void	save_map(t_game	*data, char *av);
void	zeroos(t_game *d);
int		key_handle(int key, t_game *data);

// Error
void	err(int i, char *msg);
void	map_err(int i, int fd, char *msg);

// mlx stuff
void	put_map(t_game	*data);

// mlx movement
void	do_move(t_game *data, int x, int y);
int		free_mlx(t_game *data, int mode);
char	*ft_itoa(int n);
#endif
