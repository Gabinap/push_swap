/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:40:39 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 12:22:49 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	if (lst)
		printf("%d\n", *(int *)ft_lstlast(lst)->content);
	return (0);
}*/