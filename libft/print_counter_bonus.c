/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:04:17 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:55:04 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar_counter(char c, t_counter *counter)
{
	int	write_status;

	write_status = write(1, &c, 1);
	if (write_status == -1)
		counter->error_happened = 1;
	else
		counter->num_printed++;
}

void	ft_putstr_counter(char *str, t_counter *counter)
{
	int	write_status;

	write_status = write(1, str, ft_strlen(str));
	if (write_status == -1)
		counter->error_happened = 1;
	else
		counter->num_printed += write_status;
}
