/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:52:55 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:42:47 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	handle_print_char(char c, t_fmt *format, t_counter *counter)
{
	int	filler_count;

	filler_count = 0;
	if (format->width == -1)
		format->width = 0;
	else
		filler_count = clamp(format->width - 1, 0, format->width);
	if (!format->minus)
	{
		while (filler_count-- != 0)
			ft_putchar_counter(' ', counter);
		ft_putchar_counter(c, counter);
	}
	else
	{
		ft_putchar_counter(c, counter);
		while (filler_count-- != 0)
			ft_putchar_counter(' ', counter);
	}
}
