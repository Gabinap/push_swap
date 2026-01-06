/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:36:30 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/11 11:53:38 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*print_format(const char *str, va_list args, t_fmt *format
						, t_counter *counter)
{
	if (format->type == 's')
		handle_print_str(va_arg(args, char *), format, counter);
	else if (format->type == 'c')
		handle_print_char(va_arg(args, int), format, counter);
	else if (format->type == 'd' || format->type == 'i')
		handle_print_int(va_arg(args, int), format, counter);
	else if (format->type == 'u')
		handle_print_unsigned(va_arg(args, unsigned int), format, counter);
	else if (format->type == 'x' || format->type == 'X')
		handle_print_hex(va_arg(args, unsigned int), format, counter);
	else if (format->type == 'p')
		handle_print_pointer(va_arg(args, void *), format, counter);
	else if (format->type == '%')
		handle_print_percent(counter);
	while (*str && !char_in_charset(*str, FORMATS))
		str++;
	if (!(*str))
		return ((char *)(str - 1));
	return ((char *)(str));
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	t_fmt		current_format;
	t_counter	counter;

	ft_bzero(&counter, sizeof(t_counter));
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			current_format = get_fmt(str + 1);
			if (current_format.type == 'E')
				str = print_without_format(str, &counter);
			else
				str = print_format(str + 1, args, &current_format, &counter);
		}
		else
			ft_putchar_counter(*str, &counter);
		str++;
	}
	va_end(args);
	if (counter.error_happened)
		return (-1);
	return (counter.num_printed);
}

/*
int main(void)
{

}
*/