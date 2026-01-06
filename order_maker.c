/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:06:04 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:51:37 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	order_maker_sa(t_list **a, t_ops_counter *counter, int w)
{
	void	*temp;

	if (!*a || !(*a)->content || !(*a)->next)
		return ;
	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
	if (w)
		ft_printf("sa\n");
	if (counter)
		counter->sa++;
}

void	order_maker_sb(t_list **b, t_ops_counter *counter, int w)
{
	void	*temp;

	if (!*b || !(*b)->content || !(*b)->next)
		return ;
	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
	if (w)
		ft_printf("sb\n");
	if (counter)
		counter->sb++;
}

void	order_maker_ss(t_list **a, t_list **b, t_ops_counter *counter,
		int write)
{
	order_maker_sa(a, counter, 0);
	order_maker_sb(b, counter, 0);
	if (write)
		ft_printf("ss\n");
	if (counter)
		counter->ss++;
}

void	order_maker_pa(t_list **a, t_list **b, t_ops_counter *counter,
		int write)
{
	t_list	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
	if (write)
		ft_printf("pa\n");
	if (counter)
		counter->pa++;
}

void	order_maker_pb(t_list **a, t_list **b, t_ops_counter *counter,
		int write)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
	if (write)
		ft_printf("pb\n");
	if (counter)
		counter->pb++;
}
