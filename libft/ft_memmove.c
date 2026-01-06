/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:32:45 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/06 09:50:55 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dst_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (!dst_ptr && !src_ptr)
		return ((void *)0);
	if (dst_ptr < src_ptr)
	{
		i = -1;
		while (++i < len)
			dst_ptr[i] = src_ptr[i];
	}
	else
	{
		i = len;
		while (i-- > 0)
			dst_ptr[i] = src_ptr[i];
	}
	return (dest);
}

/*
#include <string.h>
int main()
{
	int src[] = {1,2,3,4,5,6,7,8};

	ft_memmove(src + 1, src, 3 * sizeof(int));
	for (int i = 0; i < sizeof(src)/sizeof(int); i++)
	{
		__builtin_printf("%d\n", src[i]);
	}
}*/