/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:17:21 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 16:33:41 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

void	order_maker_ra(t_list **a)
{
	t_list	*first;

	if (ft_lstsize(*a) == 0)
		return ;
	first = *a;
	ft_lstadd_back(a, first);
	*a = first->next;
	first->next = NULL;
}

void	order_maker_rb(t_list **b)
{
	t_list	*first;

	if (ft_lstsize(*b) == 0)
		return ;
	first = *b;
	ft_lstadd_back(b, first);
	*b = first->next;
	first->next = NULL;
}

void	order_maker_rr(t_list **a, t_list **b)
{
	order_maker_ra(a);
	order_maker_rb(b);
}
