/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:59:27 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/18 14:51:37 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_list **a, t_list **b, int chunk_nb,
		t_ops_counter *counter)
{
	t_medium_sort	vars;

	vars.size = ft_lstsize(*a);
	vars.chunk_size = vars.size / chunk_nb;
	vars.limit = 0;
	vars.b_size = 0;
	while (*a)
	{
		vars.limit += vars.chunk_size;
		if (!(*a)->next || vars.b_size >= vars.size - 1)
			vars.limit = vars.size + 100;
		while (vars.b_size < vars.limit && *a)
		{
			vars.rank = *(int *)(*a)->content;
			if (vars.rank < vars.limit)
			{
				order_maker_pb(a, b, counter, 1);
				vars.b_size++;
				if (vars.rank < vars.limit - vars.chunk_size / 2)
					order_maker_rb(b, counter, 1);
			}
			else
				order_maker_ra(a, counter, 1);
		}
	}
}

static void	push_back_to_a(t_list **a, t_list **b, t_ops_counter *counter)
{
	int	pos;

	while (*b)
	{
		pos = find_max_pos(*b);
		bring_to_top_b(b, pos, ft_lstsize(*b), counter);
		order_maker_pa(a, b, counter, 1);
	}
}

void	medium_sort(t_list **a, t_list **b, t_ops_counter *counter)
{
	int	chunk_nb;
	int	size;

	convert_to_ranked(*a);
	if (is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	chunk_nb = root(size);
	push_chunks_to_b(a, b, chunk_nb, counter);
	push_back_to_a(a, b, counter);
}
