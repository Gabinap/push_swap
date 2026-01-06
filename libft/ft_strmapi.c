/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:08:18 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 16:07:38 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*ptr;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
char f(unsigned int i, char c)
{
	return (c + 32  +i-i);
}
#include <stdio.h>
int main()
{
	char *str = ft_strmapi("DDDDDDDDDDD", &f);
	printf("%s\n", str);
}*/