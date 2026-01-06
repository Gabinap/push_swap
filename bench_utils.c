/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:45:48 by cobussie          #+#    #+#             */
/*   Updated: 2026/01/06 15:15:55 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(float disorder)
{
	int	num;
	int	decimals;

	disorder *= 100;
	num = (int)disorder;
	decimals = (int)((disorder - (float)num) * 100.0f);
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd(num, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(decimals, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_strategy(char strategy, float disorder)
{
	char	*adapt_complexity;

	ft_putstr_fd("[bench] strategy:  ", 2);
	if (strategy & SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (strategy & MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (strategy & COMPLEX)
		ft_putstr_fd("Complex / O(n log(n))", 2);
	else
	{
		if (disorder < 0.2f)
			adapt_complexity = "O(n^2)";
		else if (disorder >= 0.5f)
			adapt_complexity = "O(n log(n))";
		else
			adapt_complexity = "O(n√n)";
		ft_putstr_fd("Adaptive / ", 2);
		ft_putstr_fd(adapt_complexity, 2);
	}
	ft_putstr_fd("\n", 2);
}

static void	print_first_ops_line(t_ops_counter counter)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("sa:  ", 2);
	ft_putnbr_fd(counter.sa, 2);
	ft_putstr_fd(" sb:  ", 2);
	ft_putnbr_fd(counter.sb, 2);
	ft_putstr_fd(" ss:  ", 2);
	ft_putnbr_fd(counter.ss, 2);
	ft_putstr_fd(" pa:  ", 2);
	ft_putnbr_fd(counter.pa, 2);
	ft_putstr_fd(" pb:  ", 2);
	ft_putnbr_fd(counter.pb, 2);
}

static void	print_second_ops_line(t_ops_counter counter)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("ra:  ", 2);
	ft_putnbr_fd(counter.ra, 2);
	ft_putstr_fd(" rb:  ", 2);
	ft_putnbr_fd(counter.rb, 2);
	ft_putstr_fd(" rr:  ", 2);
	ft_putnbr_fd(counter.rr, 2);
	ft_putstr_fd(" rra:  ", 2);
	ft_putnbr_fd(counter.rra, 2);
	ft_putstr_fd(" rrb:  ", 2);
	ft_putnbr_fd(counter.rrb, 2);
	ft_putstr_fd(" rrr:  ", 2);
	ft_putnbr_fd(counter.rrr, 2);
}

void	print_ops(t_ops_counter counter)
{
	int	total_ops;

	total_ops = counter.sa + counter.sb + counter.ss + counter.ra + counter.rb;
	total_ops += counter.rr + counter.rra + counter.rrb + counter.rrr;
	total_ops += counter.pa + counter.pb;
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total_ops, 2);
	ft_putstr_fd("\n", 2);
	print_first_ops_line(counter);
	ft_putchar_fd('\n', 2);
	print_second_ops_line(counter);
}
