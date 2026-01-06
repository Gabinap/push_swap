/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 09:11:00 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/06 08:50:26 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	nb;

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
			return (INT_MAX);
		if (nb > ((long long )INT_MAX + 1) && sign == -1)
			return (INT_MIN);
	}
	return (sign * (int)nb);
}

/*
#include <stdio.h>
int main()
{
	printf("%i\n", ft_atoi((void *)0));
	printf("%i", atoi(NULL));
}*/