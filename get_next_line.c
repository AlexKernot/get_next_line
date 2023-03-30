/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akernot <akernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:41:05 by akernot           #+#    #+#             */
/*   Updated: 2023/03/30 16:51:39 by akernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "get_next_line_utils.h"

char	*merge_strings(t_list *buffer_list, int i, int list_length)
{
	int		progress;
	int		full_size;
	char	*string;
	t_list	*next_node;

	full_size = (list_length * BUFFER_SIZE) + i + 1;
	string = (char *)malloc(sizeof(char) * full_size);
	while (buffer_list != 0)
	{
		ft_strncpy(buffer_list->buffer, &string[BUFFER_SIZE * progress], BUFFER_SIZE);
		next_node = buffer_list->next;
		free(next_node->buffer);
		free(next_node);
		buffer_list = next_node;
		progress++;
	}
	return (string);
}

void	allocate_new(t_list **buffer_list, int *i, int *list_length)
{

}

char	*get_next_line(int fd)
{
	int		i;
	int		read_return;
	int		list_length;
	t_list	*buffer_list;
	t_list	*head_node;

	list_length = 0;
	buffer_list = ft_lstnew(malloc(sizeof(char) * BUFFER_SIZE));
	head_node = buffer_list;
	while (1)
	{
		if (i == BUFFER_SIZE)
		{
			i = 0;
			buffer_list->next = ft_lstnew((char *)malloc(sizeof(char) * BUFFER_SIZE));
			buffer_list = buffer_list->next;
			list_length++;
		}
		read_return = read(fd, &buffer_list->buffer[i], 1);
		if (buffer_list->buffer[i] == '\n' || read_return == 0)
			break ;
		i++;
	}
	return (merge_strings(buffer_list, i, list_length));
}
