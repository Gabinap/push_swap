/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:36:56 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:54:54 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr_unsigned(unsigned int nb, t_counter *counter)
{
	char	digit;

	if (nb >= 10)
		ft_putnbr_unsigned(nb / 10, counter);
	digit = (nb % 10) + '0';
	ft_putchar_counter(digit, counter);
}

static void	set_fillers_unsigned(unsigned int nb,
				int len, t_print_number_vars *vars, t_fmt *fmt)
{
	int	actual_precision;

	if (fmt->has_precision)
		vars->filler_0 = clamp(fmt->precision - len, 0, fmt->precision);
	if (fmt->width == -1)
		vars->filler = 0;
	else
	{
		actual_precision = vars->filler_0 + len;
		if (nb == 0 && fmt->has_precision && fmt->precision == 0)
			actual_precision = 0;
		vars->filler = clamp(fmt->width - actual_precision, 0, fmt->width);
	}
	if (fmt->zero && !fmt->has_precision && !fmt->minus)
	{
		vars->filler_0 = vars->filler;
		vars->filler = 0;
	}
}

static int	get_number_length(unsigned int nb)
{
	int	length;

	length = 1;
	while (nb / 10 != 0)
	{
		length++;
		nb /= 10;
	}
	return (length);
}

void	handle_print_unsigned(unsigned int nb, t_fmt *fmt, t_counter *counter)
{
	t_print_number_vars	vars;

	ft_memset(&vars, 0, sizeof(t_print_number_vars));
	vars.filler_char = get_num_filler_char(fmt);
	vars.len = get_number_length(nb);
	set_fillers_unsigned(nb, vars.len, &vars, fmt);
	if (!fmt->minus)
	{
		while (vars.filler-- > 0)
			ft_putchar_counter(' ', counter);
		while (vars.filler_0-- > 0)
			ft_putchar_counter('0', counter);
		if (!(fmt->has_precision && fmt->precision == 0 && nb == 0))
			ft_putnbr_unsigned(nb, counter);
	}
	else
	{
		while (vars.filler_0-- > 0)
			ft_putchar_counter('0', counter);
		if (!(fmt->has_precision && fmt->precision == 0 && nb == 0))
			ft_putnbr_unsigned(nb, counter);
		while (vars.filler-- > 0)
			ft_putchar_counter(' ', counter);
	}
}
