/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:08:15 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 18:17:54 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 1 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*
int main()
{
	char s1[] = "hll";
	int tab = 0;
	//char s2[] = "hel";
	tab++;
	__builtin_printf("%d\n", ft_strncmp(s1, s1+1, 1));
}*/