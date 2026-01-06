/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:24:39 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/06 09:55:51 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = (unsigned char)c;
	return (s);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	void *ptr;
	ptr = malloc(4 * sizeof(int));
	ft_memset(ptr, -1, 4*sizeof(int));
	printf("%i",*((char *)ptr + 0));
	printf("%i",*((char *)ptr + 1));
	printf("%i",*((char *)ptr + 2));
	printf("%i",*((char *)ptr + 3));
}*/
