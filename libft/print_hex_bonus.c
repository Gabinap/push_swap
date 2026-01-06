/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:28:39 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:44:08 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr_hex(unsigned int nb, int upper, t_counter *counter)
{
	char	digit;

	if (nb >= 16)
		ft_putnbr_hex(nb / 16, upper, counter);
	if (upper)
		digit = UPPER_HEX[(nb % 16)];
	else
		digit = HEX[(nb % 16)];
	ft_putchar_counter(digit, counter);
}

static void	set_fillers_hex(unsigned int nb, int len,
		t_print_number_vars *vars, t_fmt *fmt)
{
	int	actual_precision;

	if (fmt->has_precision)
		vars->filler_0 = clamp(fmt->precision - len, 0, fmt->precision);
	if (fmt->width == -1)
		vars->filler = 0;
	else
	{
		actual_precision = vars->filler_0 + len + 2 * (fmt->hash && (nb != 0));
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

static void	print_minus_format(unsigned int nb, t_fmt *fmt,
	t_print_number_vars *vars, t_counter *counter)
{
	if (fmt->hash && !(nb == 0 && fmt->has_precision && fmt->precision == 0))
	{
		if (fmt->type == 'X')
			ft_putstr_counter("0X", counter);
		else
			ft_putstr_counter("0x", counter);
	}
	while (vars->filler_0-- > 0)
		ft_putchar_counter('0', counter);
	if (!(fmt->has_precision && fmt->precision == 0 && nb == 0))
		ft_putnbr_hex(nb, fmt->type == 'X', counter);
	while (vars->filler-- > 0)
		ft_putchar_counter(' ', counter);
}

static void	print_normal_format(unsigned int nb, t_fmt *fmt,
			t_print_number_vars *vars, t_counter *counter)
{
	while (vars->filler-- > 0)
		ft_putchar_counter(' ', counter);
	if (fmt->hash && !(nb == 0))
	{
		if (fmt->type == 'X')
			ft_putstr_counter("0X", counter);
		else
			ft_putstr_counter("0x", counter);
	}
	while (vars->filler_0-- > 0)
		ft_putchar_counter('0', counter);
	if (!(fmt->has_precision && fmt->precision == 0 && nb == 0))
		ft_putnbr_hex(nb, fmt->type == 'X', counter);
}

void	handle_print_hex(unsigned int nb, t_fmt *fmt, t_counter *counter)
{
	t_print_number_vars	vars;

	ft_memset(&vars, 0, sizeof(t_print_number_vars));
	vars.filler_char = get_num_filler_char(fmt);
	vars.len = get_hex_length(nb);
	set_fillers_hex(nb, vars.len, &vars, fmt);
	if (!fmt->minus)
		print_normal_format(nb, fmt, &vars, counter);
	else
		print_minus_format(nb, fmt, &vars, counter);
}
