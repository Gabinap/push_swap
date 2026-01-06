/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:17:13 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 16:33:36 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

void	order_maker_rra(t_list **a)
{
	t_list	*last;
	t_list	*prev;

	if (ft_lstsize(*a) < 2)
		return ;
	last = *a;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *a;
	*a = last;
	prev->next = NULL;
}

void	order_maker_rrb(t_list **b)
{
	t_list	*last;
	t_list	*prev;

	if (ft_lstsize(*b) < 2)
		return ;
	last = *b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *b;
	*b = last;
	prev->next = NULL;
}

void	order_maker_rrr(t_list **a, t_list **b)
{
	order_maker_rra(a);
	order_maker_rrb(b);
}
