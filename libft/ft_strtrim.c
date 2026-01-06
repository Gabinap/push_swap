/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:07:43 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 11:56:05 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	end_index = ft_strlen(s1) - 1;
	while (s1[start_index] && char_in_set(s1[start_index], set))
		start_index++;
	while (s1[end_index] && char_in_set(s1[end_index], set))
		end_index--;
	ptr = ft_substr(s1, start_index, end_index - start_index + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

/*
#include <stdio.h>
int main()
{
	char *str = ft_strtrim("s   salut la team! !!!   ","salut ");  // sans le "s"
	printf("%s\n",str );
}*/