/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:51:57 by cobussie          #+#    #+#             */
/*   Updated: 2025/12/12 09:32:41 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>

# define FORMATS "cspdiuxX%"
# define BETWEEN_FORMAT_CHARS " +#-.0123456789"
# define HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

typedef struct s_print_number_vars
{
	int		len;
	int		filler;
	int		filler_0;
	char	filler_char;
}	t_print_number_vars;

typedef struct s_fmt
{
	int		minus;
	int		zero;
	int		precision;
	int		has_precision;
	int		plus;
	int		hash;
	int		space;
	int		width;
	char	type;
}	t_fmt;

typedef struct s_counter
{
	size_t	num_printed;
	int		error_happened;
}	t_counter;

t_fmt	get_fmt(const char *after_percent_ptr);

void	ft_putchar_counter(char c, t_counter *counter);

void	ft_putstr_counter(char *str, t_counter *counter);

int		char_in_charset(char c, char *charset);

int		min(int a, int b);

int		clamp(int a, int min, int max);

char	get_int_filler_char(t_fmt *format);

int		get_int_length(int nb);

int		get_hex_length(unsigned int nb);

char	get_num_filler_char(t_fmt *format);

void	handle_print_int(int nb, t_fmt *fmt, t_counter *counter);

void	handle_print_str(const char *str, t_fmt *format, t_counter *counter);

void	handle_print_unsigned(unsigned int nb, t_fmt *fmt, t_counter *counter);

void	handle_print_char(char c, t_fmt *format, t_counter *counter);

void	handle_print_hex(unsigned int nb, t_fmt *format, t_counter *counter);

void	handle_print_percent(t_counter *counter);

void	handle_print_pointer(void *ptr, t_fmt *format, t_counter *counter);

int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));

char	*print_without_format(const char *str, t_counter *counter);

#endif
