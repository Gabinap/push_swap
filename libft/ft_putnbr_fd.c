/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:48:44 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 11:49:20 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	digit = n % 10 + '0';
	write(fd, &digit, 1);
}

/*
int main()
{
	ft_putnbr_fd(123456789,1);
	write(1,"\n",1);
	ft_putnbr_fd(-123456789,1);
		write(1,"\n",1);

	ft_putnbr_fd(0,1);
		write(1,"\n",1);

	ft_putnbr_fd(0x001,1);
		write(1,"\n",1);

}*/