/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:17:05 by gagulhon          #+#    #+#             */
/*   Updated: 2026/01/06 15:16:19 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **stack_a, t_list **stack_b, char strategy)
{
	float			disorder;
	char			adapt;
	t_ops_counter	ops_counter;

	ft_bzero(&ops_counter, sizeof(t_ops_counter));
	if (!(strategy & (SIMPLE | MEDIUM | COMPLEX)))
		strategy |= ADAPTIVE;
	adapt = (strategy & ADAPTIVE);
	disorder = compute_disorder(stack_a);
	if ((disorder >= 0.5f && adapt) || (strategy & COMPLEX))
		radix_sort(stack_a, stack_b, &ops_counter);
	else if ((disorder < 0.2f && adapt) || (strategy & SIMPLE))
		chunk_sort(stack_a, stack_b, &ops_counter);
	else if (adapt || (strategy & MEDIUM))
		medium_sort(stack_a, stack_b, &ops_counter);
	if (strategy & BENCH)
		bench_mode(strategy, disorder, ops_counter);
}

static void	set_strategy(char *strategy, char **av, int *i)
{
	if (av[*i] && ft_strcmp(av[*i], "--bench") == 0)
	{
		(*strategy) |= BENCH;
		(*i)++;
	}
	if (av[*i] && ft_strcmp(av[*i], "--simple") == 0)
	{
		*strategy |= SIMPLE;
		(*i)++;
	}
	else if (av[*i] && ft_strcmp(av[*i], "--medium") == 0)
	{
		*strategy |= MEDIUM;
		(*i)++;
	}
	else if (av[*i] && ft_strcmp(av[*i], "--complex") == 0)
	{
		*strategy |= COMPLEX;
		(*i)++;
	}
	else if (av[*i] && ft_strcmp(av[*i], "--adaptive") == 0)
	{
		*strategy |= ADAPTIVE;
		(*i)++;
	}
}

int	clear_return(t_list *a)
{
	ft_lstclear(&a, &free);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	strategy;

	stack_a = NULL;
	stack_b = NULL;
	strategy = 0;
	i = 1;
	set_strategy(&strategy, argv, &i);
	while (i < argc)
	{
		if (!parse_arg(argv[i++], &stack_a))
			return (clear_return(stack_a));
	}
	push_swap(&stack_a, &stack_b, strategy);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
