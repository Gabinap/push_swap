/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:53:23 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/12 16:36:01 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	exec_swap_push(t_list **a, t_list **b, char *ac)
{
	if (!ft_strcmp("sa\n", ac))
		order_maker_sa(a);
	else if (!ft_strcmp("sb\n", ac))
		order_maker_sb(b);
	else if (!ft_strcmp("ss\n", ac))
		order_maker_ss(a, b);
	else if (!ft_strcmp("pa\n", ac))
		order_maker_pa(a, b);
	else if (!ft_strcmp("pb\n", ac))
		order_maker_pb(a, b);
	else
		return (0);
	return (1);
}

static int	exec_rotate_reverse(t_list **a, t_list **b, char *ac)
{
	if (!ft_strcmp("ra\n", ac))
		order_maker_ra(a);
	else if (!ft_strcmp("rb\n", ac))
		order_maker_rb(b);
	else if (!ft_strcmp("rr\n", ac))
		order_maker_rr(a, b);
	else if (!ft_strcmp("rra\n", ac))
		order_maker_rra(a);
	else if (!ft_strcmp("rrb\n", ac))
		order_maker_rrb(b);
	else if (!ft_strcmp("rrr\n", ac))
		order_maker_rrr(a, b);
	else
		return (0);
	return (1);
}

int	exec_action(t_list **a, t_list **b, char *ac)
{
	if (exec_swap_push(a, b, ac))
		return (0);
	if (exec_rotate_reverse(a, b, ac))
		return (0);
	return (1);
}

void	checker(t_list **a, t_list **b)
{
	char	*action;

	action = get_next_line(0);
	while (action)
	{
		if (exec_action(a, b, action) != 0)
		{
			free(action);
			write(2, "Error\n", 6);
			return ;
		}
		free(action);
		action = get_next_line(0);
	}
	if (!is_sorted(*a) || ft_lstsize(*b))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!parse_arg(argv[i++], &stack_a))
		{
			ft_lstclear(&stack_a, &free);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
	}
	checker(&stack_a, &stack_b);
	ft_lstclear(&stack_a, &free);
	ft_lstclear(&stack_b, &free);
	return (0);
}
