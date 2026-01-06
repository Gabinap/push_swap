/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:08:35 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 12:03:39 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	charc;

	charc = (char)c;
	if (!s)
		return (0);
	while (*s != charc)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

/*
#include <stdio.h>
int main()
{
	char *s = ft_strchr("salut,ZS",'2');
	printf("%s\n", s);
}
*/