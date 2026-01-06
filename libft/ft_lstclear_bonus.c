/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:06:11 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 16:25:07 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*to_free;

	if (!lst)
	{
		return ;
	}
	if (!(*lst))
	{
		return ;
	}
	list = *lst;
	while (list)
	{
		to_free = list;
		del(list->content);
		list = list->next;
		free(to_free);
	}
	*lst = NULL;
}
