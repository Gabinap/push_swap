/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:53:33 by gagulhon          #+#    #+#             */
/*   Updated: 2026/01/06 15:16:33 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "operations.h"

# define SIMPLE 0b0001
# define MEDIUM 0b0010
# define COMPLEX 0b0100
# define ADAPTIVE 0b1000
# define BENCH 0b10000

typedef struct s_medium_sort
{
	int	chunk_size;
	int	limit;
	int	size;
	int	rank;
	int	b_size;
}		t_medium_sort;

// parse / parse_utils.c
int		parse_arg(char *arg, t_list **stack_a);
int		free_split(char **list);
int		free_args(char **list, long *val);
long	ft_atol(const char *str);

// disorder.c
float	compute_disorder(t_list **a);

// utils.c

void	convert_to_ranked(t_list *a);
int		is_sorted(t_list *stack);
int		find_max_pos(t_list *b);
int		ft_strcmp(const char *s1, const char *s2);

// sort_utils.c
int		root(int nb);
int		find_in_chunk(t_list *a, int min_rank, int max_rank);
void	bring_to_top(t_list **a, int pos, int size, t_ops_counter *counter);
void	bring_to_top_b(t_list **b, int pos, int size, t_ops_counter *counter);

// chunk_sort.c
void	chunk_sort(t_list **a, t_list **b, t_ops_counter *counter);

// radix.c
void	radix_sort(t_list **a, t_list **b, t_ops_counter *counter);

// medium_sort
void	medium_sort(t_list **a, t_list **b, t_ops_counter *counter);

// bench_utils.c
void	print_disorder(float disorder);
void	print_strategy(char strategy, float disorder);
void	print_ops(t_ops_counter ops_counter);

// bench_mode.c
void	bench_mode(char strategy, float disorder, t_ops_counter ops_counter);

#endif