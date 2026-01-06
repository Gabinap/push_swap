/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:06:12 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 12:25:10 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>
int main(void)
{
	int i = 1920102;
	t_list *lst;
	lst = ft_lstnew(&i);
	ft_lstadd_front(&lst, lst);
	ft_lstadd_front(&lst, lst);
		int j = 23;
	t_list *lst2;
	lst2 = ft_lstnew(&j);
	ft_lstadd_front(&lst, lst2);
	printf("%d\n", *(int *)lst->content);
	printf("%d\n", *(int *)lst->next->content);
	printf("%d\n", *(int *)lst->next->next->content);
	return (0);
}*/