/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akernot <akernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 09:17:08 by akernot           #+#    #+#             */
/*   Updated: 2023/03/30 09:18:05 by akernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

typedef struct s_list
{
	void	*buffer;
	t_list	*next;
}	t_list;
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new_lst);
#endif