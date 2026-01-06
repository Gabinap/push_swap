/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagulhon <gagulhon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:16:44 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:16:45 by gagulhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (*(int *)(stack->content) == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static char	**create_tab(char *arg)
{
	char	**tab;

	if (ft_strchr(arg, ' '))
	{
		tab = ft_split(arg, ' ');
		if (!tab)
			return (NULL);
	}
	else
	{
		tab = malloc(sizeof(char *) * 2);
		if (!tab)
			return (NULL);
		tab[0] = ft_strdup(arg);
		tab[1] = NULL;
	}
	return (tab);
}

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_arg(char *arg, t_list **stack_a)
{
	char	**tab;
	int		i;
	long	*val;

	tab = create_tab(arg);
	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
	{
		if (!is_valid_number(tab[i]))
			return (free_split(tab));
		val = malloc(sizeof(long));
		if (!val)
			return (free_split(tab));
		*val = ft_atol(tab[i]);
		if (*val < -2147483648 || *val > 2147483647)
			return (free_args(tab, val));
		if (has_duplicate(*stack_a, (int)*val))
			return (free_args(tab, val));
		ft_lstadd_back(stack_a, ft_lstnew(val));
	}
	free_split(tab);
	return (1);
}
