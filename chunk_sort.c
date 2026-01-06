/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:45:08 by cobussie          #+#    #+#             */
/*   Updated: 2026/01/06 15:16:07 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_max_and_pos(t_list *b, int *max, int *pos)
{
	t_list	*tmp;

	*max = -1;
	tmp = b;
	*pos = 0;
	while (tmp)
	{
		if (*(int *)tmp->content > *max)
			*max = *(int *)tmp->content;
		tmp = tmp->next;
	}
	tmp = b;
	while (tmp && *(int *)tmp->content != *max && ++(*pos))
		tmp = tmp->next;
}

static void	rotate_to_top(t_list **b, int max, int pos, t_ops_counter *counter)
{
	int	size;

	size = ft_lstsize(*b);
	while (*(int *)(*b)->content != max)
	{
		if (pos <= size / 2)
			order_maker_rb(b, counter, 1);
		else
			order_maker_rrb(b, counter, 1);
	}
}

static void	push_back_to_a(t_list **a, t_list **b, t_ops_counter *counter)
{
	int	max;
	int	pos;

	while (*b)
	{
		find_max_and_pos(*b, &max, &pos);
		rotate_to_top(b, max, pos, counter);
		order_maker_pa(a, b, counter, 1);
	}
}

static void	push_chunks(t_list **a, t_list **b, t_ops_counter *counter)
{
	int	i;
	int	range;

	i = 0;
	range = ft_lstsize(*a) / 3;
	while (*a)
	{
		if (*(int *)(*a)->content <= i)
		{
			order_maker_pb(a, b, counter, 1);
			order_maker_rb(b, counter, 1);
			i++;
		}
		else if (*(int *)(*a)->content <= i + range)
		{
			order_maker_pb(a, b, counter, 1);
			i++;
		}
		else
			order_maker_ra(a, counter, 1);
	}
}

void	chunk_sort(t_list **a, t_list **b, t_ops_counter *counter)
{
	convert_to_ranked(*a);
	if (is_sorted(*a))
		return ;
	push_chunks(a, b, counter);
	push_back_to_a(a, b, counter);
}
