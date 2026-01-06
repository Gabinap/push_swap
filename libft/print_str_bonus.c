/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:13:34 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/11 12:42:02 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	reversed_print(int len, const char *str,
					int filler_count, t_counter *counter)
{
	while (len-- != 0)
		ft_putchar_counter(*(str++), counter);
	while (filler_count-- != 0)
		ft_putchar_counter(' ', counter);
}

static void	normal_print(int len, const char *str,
					int filler_count, t_counter *counter)
{
	while (filler_count-- != 0)
		ft_putchar_counter(' ', counter);
	while (len-- != 0)
		ft_putchar_counter(*(str++), counter);
}

void	handle_print_str(const char *str, t_fmt *format, t_counter *counter)
{
	int	filler_count;
	int	len;

	filler_count = 0;
	if (!str)
	{
		if (format->has_precision && format->precision < 6)
			str = "";
		else
			str = "(null)";
	}
	len = ft_strlen(str);
	if (format->has_precision)
		len = min(len, format->precision);
	if (format->width == -1)
		format->width = 0;
	else
		filler_count = clamp(format->width - len, 0, format->width);
	if (!format->minus)
		normal_print(len, str, filler_count, counter);
	else
		reversed_print(len, str, filler_count, counter);
}
