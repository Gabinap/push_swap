/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:47:42 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/12 15:47:43 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list **a)
{
	int		mistakes;
	int		total_pairs;
	t_list	*tmp;
	t_list	*tmp2;

	if (!*a || !(*a)->next)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	tmp = *a;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			total_pairs++;
			if (*(int *)tmp->content > *(int *)tmp2->content)
				mistakes++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (total_pairs == 0 || mistakes == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}
