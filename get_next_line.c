/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akernot <akernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:41:05 by akernot           #+#    #+#             */
/*   Updated: 2023/03/30 09:28:30 by akernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "get_next_line_utils.h"

char	*get_next_line(int fd)
{
	int		i;
	t_list	*buffer_list;

	buffer_list = ft_lstnew(malloc(sizeof(char) * BUFFER_SIZE));
	while (1)
	{
		if (i == BUFFER_SIZE)
			allocate_new(&buffer_list, &i);
		read(fd, &buffer_list->buffer[i], 1);
		if (&buffer_list->buffer[i] == '\n')
			break ;
		i++;
	}
}
