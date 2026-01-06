/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:47:52 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/06 10:00:05 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = 0;
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	void *ptr;
	ptr = malloc(4 * sizeof(int));
	ft_bzero(ptr,4*sizeof(int));
	printf("%i",*((char *)ptr + 0));
	printf("%i",*((char *)ptr + 1));
	printf("%i",*((char *)ptr + 2));
	printf("%i",*((char *)ptr + 3));
}
*/