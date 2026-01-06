/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:07:29 by gagulhon          #+#    #+#             */
/*   Updated: 2025/12/12 15:48:14 by cobussie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_extract_line(char *stash)
{
	size_t	len;

	if (!stash || !stash[0])
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	return (ft_substr(stash, 0, len));
}

static char	*ft_clean_stash(char *stash)
{
	size_t	start;
	char	*new_stash;

	if (!stash)
		return (NULL);
	start = 0;
	while (stash[start] && stash[start] != '\n')
		start++;
	if (stash[start] == '\n')
		start++;
	if (!stash[start])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, start, ft_strlen(stash) - start);
	free(stash);
	return (new_stash);
}

static void	*ft_free_for_space(char *buffer, char *stash)
{
	if (buffer)
		free(buffer);
	if (stash)
		free(stash);
	return (NULL);
}

static char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free_for_space(buffer, stash));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer, bytes_read);
		if (!stash)
			return (ft_free_for_space(buffer, NULL));
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (line);
	}
	stash[fd] = ft_clean_stash(stash[fd]);
	return (line);
}
