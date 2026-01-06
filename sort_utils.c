/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:00:00 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/12 17:00:00 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	root(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
		i++;
	return (i);
}

int	find_in_chunk(t_list *a, int min_rank, int max_rank)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (*(int *)a->content >= min_rank && *(int *)a->content <= max_rank)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	bring_to_top(t_list **a, int pos, int size, t_ops_counter *counter)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			order_maker_ra(a, counter, 1);
	}
	else
	{
		while (pos++ < size)
			order_maker_rra(a, counter, 1);
	}
}

void	bring_to_top_b(t_list **b, int pos, int size, t_ops_counter *counter)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			order_maker_rb(b, counter, 1);
	}
	else
	{
		while (pos++ < size)
			order_maker_rrb(b, counter, 1);
	}
}
