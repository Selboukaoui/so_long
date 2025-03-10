/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:32:49 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 02:10:35 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

char	*reading(int fd, char *buffer, ssize_t *counter)
{
	*counter = read(fd, buffer, BUFFER_SIZE);
	if (*counter == -1)
	{
		close (fd);
		err(25, "Error\nReading failed\n");
	}
	else
		buffer[*counter] = '\0';
	return (buffer);
}

char	*outline(char *saveline, int i, int fd)
{
	char	*str;
	int		j;

	j = 0;
	if (saveline[j] == '\0')
		return (NULL);
	while (saveline[i] != '\0' && saveline[i] != '\n')
		i++;
	if (saveline[i] == '\n')
		i++;
	str = ft_malloc (i + 1, 1);
	if (!str)
	{
		close(fd);
		err(25, "Error\nAllocation failed\n");
	}
	while (saveline[j] && saveline[j] != '\n')
	{
		str[j] = saveline[j];
		j++;
	}
	if (saveline[j] == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

char	*cleaning(char *saveline, int fd)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (saveline[j] && saveline[j] != '\n' )
		j++;
	if (saveline[j] == '\0')
		return (NULL);
	if (saveline[j] == '\n')
		j++;
	str = ft_malloc (sizeof(char) * (len(saveline) - j + 1), 1);
	if (!str)
	{
		close(fd);
		err(25, "Error\nAllocation failed\n");
	}
	while (saveline[j])
		str[i++] = saveline[j++];
	str[i] = '\0';
	return (str);
}

char	*looping(char *saveline, int fd)
{
	ssize_t			counter;
	char			*tmp;
	char			*buffer;

	counter = 0;
	buffer = ft_malloc ((size_t)BUFFER_SIZE + 1, 1);
	if (!buffer)
	{
		close (fd);
		err(25, "Error\nAllocation failed\n");
	}
	while (1)
	{
		buffer = reading(fd, buffer, &counter);
		tmp = saveline;
		saveline = joining(tmp, buffer);
		if (!saveline)
			return (NULL);
		if (search(saveline, '\n') || counter == 0)
			return (saveline);
	}
	return (saveline);
}

char	*get_next_line(int fd)
{
	static char		*saveline;
	char			*output;
	int				i;

	if (fd < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE > INT_MAX || BUFFER_SIZE <= 0)
	{
		if (fd > 0)
			close (fd);
		err(25, "Error\nfrom gnl");
	}
	saveline = looping(saveline, fd);
	if (!saveline)
	{
		close (fd);
		err(25, "Error\nAllocation failed\n");
	}
	i = 0;
	output = outline(saveline, i, fd);
	saveline = cleaning(saveline, fd);
	return (output);
}
