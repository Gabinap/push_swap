/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:47:40 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:50:13 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr_long(size_t nb, t_counter *counter)
{
	char	digit;

	if (nb >= 16)
		ft_putnbr_long(nb / 16, counter);
	digit = HEX[(nb % 16)];
	ft_putchar_counter(digit, counter);
}

static void	ft_print_number(size_t nb, t_counter *counter)
{
	if (nb == 0)
		ft_putstr_counter("(nil)", counter);
	else
	{
		ft_putstr_counter("0x", counter);
		ft_putnbr_long(nb, counter);
	}
}

static int	get_number_length(size_t nb)
{
	int	length;

	length = 1;
	if (!nb)
		return (3);
	while (nb / 16 != 0)
	{
		length++;
		nb /= 16;
	}
	return (length);
}

void	handle_print_pointer(void *ptr, t_fmt *format, t_counter *counter)
{
	size_t	casted_ptr;
	int		filler_count;
	int		len;

	casted_ptr = (size_t)ptr;
	len = get_number_length(casted_ptr);
	filler_count = 0;
	if (format->width == -1)
		format->width = 0;
	else
		filler_count = clamp(format->width - len - 2, 0, format->width);
	if (!format->minus)
	{
		while (filler_count-- != 0)
			ft_putchar_counter(' ', counter);
		ft_print_number(casted_ptr, counter);
	}
	else
	{
		ft_print_number(casted_ptr, counter);
		while (filler_count-- != 0)
			ft_putchar_counter(' ', counter);
	}
}
