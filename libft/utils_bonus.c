/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:55:53 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:31:45 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	char_in_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	clamp(int a, int min, int max)
{
	if (a < min)
		return (min);
	if (a > max)
		return (max);
	return (a);
}

char	get_num_filler_char(t_fmt *format)
{
	if (format->zero && !format->has_precision)
		return ('0');
	return (' ');
}
