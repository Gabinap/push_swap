/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:43:36 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/10 11:30:35 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*not_new(t_list *new, t_list *p, void *content, void (*del)(void *))
{
	if (!new && del)
	{
		del(content);
		ft_lstclear(&p, del);
	}
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new;
	void	*content;

	ptr = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		new = ft_lstnew(content);
		if (!not_new(new, ptr, content, del))
			return (0);
		ft_lstadd_back(&ptr, new);
		lst = lst->next;
	}
	return (ptr);
}
