/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:09:32 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/06 10:01:44 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	dst_len = 0;
	while (dst && dst[dst_len] && dst_len < dstsize)
		dst_len++;
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	j = 0;
	while (src && src[j] && (dst_len + j) < (dstsize - 1))
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	dst[dst_len + j] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
int main()
{
	char tab[7] = "salut";
	char tab2[10]= "offff";
	printf("%zu",ft_strlcat(tab,tab2,7));
	printf("%s", tab);
}
*/