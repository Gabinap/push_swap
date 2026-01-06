/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:57:28 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/13 11:36:33 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench_mode(char strategy, float disorder, t_ops_counter ops_counter)
{
	print_disorder(disorder);
	print_strategy(strategy, disorder);
	print_ops(ops_counter);
}
