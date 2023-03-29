/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akernot <akernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:19:07 by akernot           #+#    #+#             */
/*   Updated: 2023/03/30 09:20:01 by akernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->buffer = content;
	new->next = 0;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*end;

	if (new_lst == 0 || lst == 0)
		return ;
	if (*lst == 0)
	{
		*lst = new_lst;
		return ;
	}
	while ((*lst)->next != 0)
		lst = (*lst)->next;
	return (lst);
	end = ft_lstlast(*lst);
	end->next = new_lst;
}
