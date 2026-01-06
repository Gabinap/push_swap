/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:04:40 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:45:00 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_hex_length(unsigned int nb)
{
	int	length;

	length = 1;
	while (nb / 16 != 0)
	{
		length++;
		nb /= 16;
	}
	return (length);
}
