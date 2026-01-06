/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:08:37 by cobussie          #+#    #+#             */
/*   Updated: 2025/11/10 15:24:55 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_list_until(char **list, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static char	*malloc_word(const char *s, char sep)
{
	int		length;
	char	*word;
	int		i;

	length = 0;
	i = 0;
	while (s[length] && s[length] != sep)
		length++;
	word = malloc(sizeof(char) * (length + 1));
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static size_t	count_words(const char	*s, char c)
{
	size_t	count;
	size_t	i;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (i == 0 && s[i] != c)
			count++;
		if (i != 0 && s[i] != c && s[i - 1] == c)
			count++;
	}
	return (count);
}

char	**ft_split(const char	*s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (count_words((const char *)s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			str[i] = malloc_word(s, c);
			if (!str[i])
				return (free_list_until(str, i));
			while (*s && (*s != c))
				s++;
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}

/*
int main()
{
	int i =-1; 
	while (str[++i] != NULL)
		__builtin_printf("%s\n",str[i]);

}*/