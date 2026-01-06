/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:08:33 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/05 18:02:01 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;
	int		i ;

	i = -1 ;
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (++i < len)
	{
		ptr[i] = (char)s[i];
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
int main()
{
	char	*str = ft_strdup("");
	free(str);
}*/