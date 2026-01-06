/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:08:28 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 12:01:48 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	lenght1;
	size_t	lenght2;
	char	*ptr;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s1 || !s2)
	{
		return (NULL);
	}
	lenght1 = ft_strlen(s1);
	lenght2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (lenght1 + lenght2 + 1));
	if (!ptr)
		return (NULL);
	while (++i < lenght1)
		ptr[i] = s1[i];
	j = -1;
	while (++j < lenght2)
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	return (ptr);
}

/*
#include <stdio.h>
int main()
{
	char *joined = ft_strjoin(" ","awdawdawd");
	printf("%s\n",joined );
}*/