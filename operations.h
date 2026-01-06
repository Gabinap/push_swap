/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:53:15 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:49:33 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft/libft.h"

typedef struct s_ops_counter
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_ops_counter;

void	order_maker_rra(t_list **a, t_ops_counter *counter, int write);
void	order_maker_rrb(t_list **b, t_ops_counter *counter, int write);
void	order_maker_rrr(t_list **a, t_list **b, t_ops_counter *counter,
			int write);

void	order_maker_ra(t_list **a, t_ops_counter *counter, int write);
void	order_maker_rb(t_list **b, t_ops_counter *counter, int write);
void	order_maker_rr(t_list **a, t_list **b, t_ops_counter *counter,
			int write);

void	order_maker_sa(t_list **a, t_ops_counter *counter, int w);
void	order_maker_sb(t_list **a, t_ops_counter *counter, int w);
void	order_maker_ss(t_list **a, t_list **b, t_ops_counter *counter,
			int write);
void	order_maker_pa(t_list **a, t_list **b, t_ops_counter *counter,
			int write);
void	order_maker_pb(t_list **a, t_list **b, t_ops_counter *counter,
			int write);

#endif
