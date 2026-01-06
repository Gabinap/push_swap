/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:11:20 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 11:48:24 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	while (*str)
	{
		write(fd, str++, 1);
	}
}
/*
int main()
{
	ft_putstr_fd("salut\n", 0);
}*/