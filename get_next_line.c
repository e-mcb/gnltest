/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:41:03 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/16 22:42:32 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_next_line(int fd, char *storage, char *buffer)
{
	char	*str;
	ssize_t	read_value;

	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value < 0)
		{
			free(storage);
			return (NULL);
		}
		else if (read_value == 0)
			break ;
		buffer[read_value] = 0;
		if (!storage)
			storage = ft_strdup("");
		str = storage;
		storage = ft_strjoin(str, buffer);
		free (str);
		str = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (storage);
}

static char	*check_line(char *buffer)
{
	char	*storage;
	ssize_t	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != 0)
		i++;
	if (buffer[i] == 0 || buffer[i + 1] == 0)
		return (NULL);
	storage = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (!storage)
	{
		free(storage);
		storage = NULL;
	}
	buffer[i + 1] = 0;
	return (storage);
}

static char *free_buf(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return(ptr);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*next_line;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free_buf(buffer);
		free(storage);
		storage = NULL;
		return (NULL);
	}
	next_line = find_next_line(fd, storage, buffer);
	free(buffer);
	if (!next_line)
		return (NULL);
	storage = check_line(next_line);
	return (next_line);
}
