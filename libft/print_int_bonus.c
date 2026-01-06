/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:11:34 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:46:59 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_putnbr_no_sign(int nb, t_counter *counter)
{
	char	digit;

	if (nb == -2147483648)
	{
		ft_putstr_counter("2147483648", counter);
		return ;
	}
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		ft_putnbr_no_sign(nb / 10, counter);
	digit = (nb % 10) + '0';
	ft_putchar_counter(digit, counter);
}

static void	write_needed_char(t_fmt *fmt, int nb, t_counter *counter)
{
	if (nb < 0)
		ft_putchar_counter('-', counter);
	else if (fmt->plus)
		ft_putchar_counter('+', counter);
	else if (fmt->space)
		ft_putchar_counter(' ', counter);
}

static void	set_fillers(int nb, int len, t_print_number_vars *vars, t_fmt *fmt)
{
	int	actual_precision;
	int	has_sign;

	has_sign = (nb < 0 || fmt->plus || fmt->space);
	if (fmt->has_precision)
		vars->filler_0 = clamp(fmt->precision - len, 0, fmt->precision);
	if (fmt->width == -1)
		vars->filler = 0;
	else
	{
		actual_precision = vars->filler_0 + len + has_sign;
		if (nb == 0 && fmt->has_precision && fmt->precision == 0)
			actual_precision = has_sign;
		vars->filler = clamp(fmt->width - actual_precision, 0, fmt->width);
	}
	if (fmt->zero && !fmt->has_precision && !fmt->minus)
	{
		vars->filler_0 = vars->filler;
		vars->filler = 0;
	}
}

static void	handle_print(int nb, t_fmt *fmt,
			t_print_number_vars *vars, t_counter *counter)
{
	if (!fmt->minus)
	{
		while (vars->filler-- > 0)
			ft_putchar_counter(' ', counter);
		write_needed_char(fmt, nb, counter);
		while (vars->filler_0-- > 0)
			ft_putchar_counter('0', counter);
		if (!(fmt->has_precision && fmt->precision == 0 && nb == 0))
			ft_putnbr_no_sign(nb, counter);
	}
	else
	{
		write_needed_char(fmt, nb, counter);
		while (vars->filler_0-- > 0)
			ft_putchar_counter('0', counter);
		if (!(fmt->has_precision && fmt->precision == 0 && nb == 0))
			ft_putnbr_no_sign(nb, counter);
		while (vars->filler-- > 0)
			ft_putchar_counter(' ', counter);
	}
}

void	handle_print_int(int nb, t_fmt *fmt, t_counter *counter)
{
	t_print_number_vars	vars;

	ft_bzero(&vars, sizeof(t_print_number_vars));
	vars.filler_char = get_num_filler_char(fmt);
	vars.len = get_int_length(nb);
	set_fillers(nb, vars.len, &vars, fmt);
	handle_print(nb, fmt, &vars, counter);
}
