/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:54:11 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 14:35:09 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	handle_flags(const char carac, t_fmt *format)
{
	if (char_in_charset(carac, "- +#")
		&& (format->width != -1 || format->has_precision != 0))
	{
		format->type = 'E';
		return ;
	}
	if (carac == '-')
	{
		format->minus = 1;
		format->zero = 0;
	}
	else if (carac == '+')
	{
		format->plus = 1;
		format->space = 0;
	}
	else if (carac == '#')
		format->hash = 1;
	else if (carac == ' ' && !format->plus)
		format->space = 1;
	else if (carac == '0' && !format->minus
		&& format->width == -1 && !format->has_precision)
		format->zero = 1;
}

static void	handle_width(const char *position, t_fmt *format)
{
	if (format->has_precision)
		return ;
	if (format->width == -1 && char_in_charset(*position, "123456789"))
		format->width = ft_atoi(position);
}

static void	handle_precision(const char *position, t_fmt *format)
{
	if (*position == '.')
	{
		if (format->has_precision)
			format->type = 'E';
		else
		{
			format->has_precision = 1;
			format->precision = ft_atoi(++position);
		}
	}
}

static void	handle_carac(const char *position, t_fmt *format)
{
	handle_precision(position, format);
	handle_width(position, format);
	handle_flags(*position, format);
}

t_fmt	get_fmt(const char *after_percent_ptr)
{
	t_fmt	format;

	ft_bzero(&format, sizeof(t_fmt));
	format.width = -1;
	while (*after_percent_ptr
		&& char_in_charset(*after_percent_ptr, BETWEEN_FORMAT_CHARS))
	{
		handle_carac(after_percent_ptr, &format);
		if (format.type == 'E')
			return (format);
		after_percent_ptr++;
	}
	if (*after_percent_ptr && char_in_charset(*after_percent_ptr, FORMATS))
		format.type = *after_percent_ptr;
	else
		format.type = 'E';
	return (format);
}
