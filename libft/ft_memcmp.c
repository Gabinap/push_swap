/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:02:02 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 16:28:48 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n != 0 && (*ptr1 == *ptr2))
	{
		ptr1++;
		ptr2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*ptr1 - *ptr2);
}

/*
int main()
{
	char s1[] = "helo";
	char s2[] = "hello";
	__builtin_printf("%d\n", ft_memcmp(s1, s2, 4));
}*/