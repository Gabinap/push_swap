/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:17:28 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:50:18 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	order_maker_ra(t_list **a, t_ops_counter *counter, int write)
{
	t_list	*first;

	if (ft_lstsize(*a) == 0)
		return ;
	first = *a;
	ft_lstadd_back(a, first);
	*a = first->next;
	first->next = NULL;
	if (write)
		ft_printf("ra\n");
	if (counter)
		counter->ra++;
}

void	order_maker_rb(t_list **b, t_ops_counter *counter, int write)
{
	t_list	*first;

	if (ft_lstsize(*b) == 0)
		return ;
	first = *b;
	ft_lstadd_back(b, first);
	*b = first->next;
	first->next = NULL;
	if (write)
		ft_printf("rb\n");
	if (counter)
		counter->rb++;
}

void	order_maker_rr(t_list **a, t_list **b, t_ops_counter *counter,
		int write)
{
	order_maker_ra(a, counter, 0);
	order_maker_rb(b, counter, 0);
	if (write)
		ft_printf("rr\n");
	if (counter)
		counter->rr++;
}
