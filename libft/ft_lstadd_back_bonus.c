/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:31:33 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 12:26:04 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_last;

	if (!lst)
		return ;
	current_last = ft_lstlast(*lst);
	if (!current_last)
		*lst = new;
	else
		current_last->next = new;
}

/*
#include <stdio.h>
int main(void)
{
	int i = 1920102;
	int j = 5;
	t_list *lst;
	t_list *lst2;
	lst = ft_lstnew(&i);
	lst2 = ft_lstnew(&j);
	lst->next = lst2;
	ft_lstadd_back(&lst,ft_lstnew(&i));
	if (lst)
		printf("%d\n", *(int *)(lst)->content);
	return (0);
}*/