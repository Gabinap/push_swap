/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gagulhon <gagulhon@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:16:54 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:16:55 by gagulhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\v');
}

long	ft_atol(const char *str)
{
	int		sign;
	int		i;
	long	nb;

	sign = 1;
	i = 0;
	nb = 0;
	if (!str)
		return (0);
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - '0';
		if (nb > INT_MAX && sign == 1)
			return (LONG_MAX);
		if (nb > ((long long)INT_MAX + 1) && sign == -1)
			return (LONG_MIN);
	}
	return (sign * nb);
}

int	free_split(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (0);
}

int	free_args(char **list, long *val)
{
	free_split(list);
	free(val);
	return (0);
}
