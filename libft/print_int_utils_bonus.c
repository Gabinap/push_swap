/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:07:31 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 17:49:58 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_int_length(int nb)
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
