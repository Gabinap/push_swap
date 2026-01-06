/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:38:22 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/13 13:33:10 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **a, t_list **b, t_ops_counter *counter)
{
	int	i;
	int	size;

	i = 0;
	convert_to_ranked(*a);
	while (!is_sorted(*a))
	{
		size = ft_lstsize(*a);
		while (size--)
		{
			if (!((*(int *)((*a)->content)) & (1 << i)))
				order_maker_pb(a, b, counter, 1);
			else
				order_maker_ra(a, counter, 1);
		}
		while (*b)
			order_maker_pa(a, b, counter, 1);
		i++;
	}
}
