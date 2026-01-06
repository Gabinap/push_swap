/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_maker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:51:18 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/12 16:33:55 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

void	order_maker_sa(t_list **a)
{
	void	*temp;

	if (!*a || !(*a)->content || !(*a)->next)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
}

void	order_maker_sb(t_list **b)
{
	void	*temp;

	if (!*b || !(*b)->content || !(*b)->next)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
}

void	order_maker_ss(t_list **a, t_list **b)
{
	order_maker_sa(a);
	order_maker_sb(b);
}

void	order_maker_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
}

void	order_maker_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
}
