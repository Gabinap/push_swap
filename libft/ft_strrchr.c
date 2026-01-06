/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:08:10 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 17:44:22 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if (*s == (char)c)
		ptr = (char *)s;
	return (ptr);
}

/*
#include <stdio.h>
int main()
{
	char *s = ft_strrchr("salut jjjj'ai 25 ans",'j');
	printf("%s\n", s);
}*/