/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grb_coll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbouka <selbouka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:32:10 by selbouka          #+#    #+#             */
/*   Updated: 2025/03/05 02:30:26 by selbouka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	free_all(t_collect **head)
{
	t_collect	*current;
	t_collect	*next;

	if (!*head || !head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	*head = NULL;
}

void	*ft_malloc(size_t size, int mode)
{
	static t_collect	*head;
	void				*data;
	t_collect			*node;

	data = NULL;
	node = NULL;
	if (mode == 1)
	{
		data = malloc(size);
		if (!data)
			err(25, "Error\nAllocaton failed\n");
		node = malloc(sizeof(t_collect));
		if (!node)
			(free(data), err(25, "Error\nAllocaton failed\n"));
		node->data = data;
		node->next = head;
		head = node;
	}
	else if (mode == 0)
	{
		free_all(&head);
		head = NULL;
	}
	return (data);
}
