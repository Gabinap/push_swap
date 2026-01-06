/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:54:00 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 18:58:01 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*print_without_format(const char *str, t_counter *counter)
{
	ft_putchar_counter('%', counter);
	str++;
	while (*str && !char_in_charset(*str, FORMATS))
	{
		ft_putchar_counter(*str, counter);
		str++;
	}
	if (char_in_charset(*str, FORMATS))
	{
		ft_putchar_counter(*str, counter);
	}
	if (!(*str))
		str--;
	return ((char *)(str));
}
