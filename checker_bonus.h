/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:53:33 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 14:43:23 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line_bonus.h"
# include "operations_bonus.h"

// utils.c

void	convert_to_ranked(t_list *a);
int		is_sorted(t_list *stack);
int		find_max_pos(t_list *b);
int		ft_strcmp(const char *s1, const char *s2);

// parse / parse_utils.c
int		parse_arg(char *arg, t_list **stack_a);
int		free_split(char **list);
int		free_args(char **list, long *val);
long	ft_atol(const char *str);

#endif
