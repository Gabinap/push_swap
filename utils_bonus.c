/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:54:24 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:55:00 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	is_sorted(t_list *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if ((*(int *)(stack->content)) > (*(int *)(stack->next->content)))
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	recursive_rank(t_list *node, t_list *head)
{
	t_list	*scan;
	int		rank;

	if (!node)
		return ;
	rank = 0;
	scan = head;
	while (scan)
	{
		if (*(int *)scan->content < *(int *)node->content)
			rank++;
		scan = scan->next;
	}
	recursive_rank(node->next, head);
	*(int *)node->content = rank;
}

void	convert_to_ranked(t_list *a)
{
	recursive_rank(a, a);
}

int	find_max_pos(t_list *b)
{
	int	max;
	int	max_pos;
	int	pos;

	if (!b)
		return (0);
	max = *(int *)b->content;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (*(int *)b->content > max)
		{
			max = *(int *)b->content;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}
