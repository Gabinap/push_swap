/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagulhon <gagulhon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:17:18 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:17:19 by gagulhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	order_maker_rra(t_list **a, t_ops_counter *counter, int write)
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
	if (write)
		ft_printf("rra\n");
	if (counter)
		counter->rra++;
}

void	order_maker_rrb(t_list **b, t_ops_counter *counter, int write)
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
	if (write)
		ft_printf("rrb\n");
	if (counter)
		counter->rrb++;
}

void	order_maker_rrr(t_list **a, t_list **b, t_ops_counter *counter,
		int write)
{
	order_maker_rra(a, counter, 0);
	order_maker_rrb(b, counter, 0);
	if (write)
		ft_printf("rrr\n");
	if (counter)
		counter->rrr++;
}
