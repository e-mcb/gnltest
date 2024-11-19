/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzutter <mzutter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:41:03 by mzutter           #+#    #+#             */
/*   Updated: 2024/11/19 06:28:26 by mzutter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_storage(int fd, char *storage, char *buffer)
{
	char	*str;
	ssize_t	read_value;

	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value < 0) // check for read errors
		{
			free(storage);
			return (NULL);
		}
		else if (read_value == 0) // exit loop if nothing else to read
			break ;
		buffer[read_value] = 0; // appends \0 to non null-terminated buf
		if (!storage) // if it doesnt exist already, creates the storage that will be return to gnl
			storage = ft_strdup("");
		str = storage; // temp ptr to be able to free storage after appending buf to it
		storage = ft_strjoin(str, buffer); // appends buf to storage
		free (str); //free the initial storage
		str = NULL;
		if (ft_strchr(buffer, '\n')) //check for \n, checking in buf for faster execution
			break ;
	}
	return (storage);
}

static char	*extract_line(char *next_line)
{
	char	*storage;
	ssize_t	i;

	i = 0;
	while (next_line[i] != '\n' && next_line[i] != 0) //sets its position at the end of the next_line
		i++;
	if (next_line[i] == 0 || next_line[i + 1] == 0) // checks for eof
		return (NULL);
	storage = ft_substr(next_line, i + 1, ft_strlen(next_line) - i); // recreates storage to only keep what comes after \n
	if (!storage)
	{
		free(storage);
		storage = NULL;
	}
	next_line[i + 1] = 0;
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*next_line;

	buffer = malloc((size_t)BUFFER_SIZE + 1); 
	if (!buffer)
		return (NULL);
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0) //check if file can be read, if 
														  //fd is valid, and if buf size is valid
														  //frees everything if not
	{
		free(buffer);
		buffer = NULL;
		free(storage);
		storage = NULL;
		return (NULL);
	}
	next_line = set_storage(fd, storage, buffer); // creates and modifies the storage by appending buf to it
	free(buffer); //no need for buffer after appending it to storage
	if (!next_line) // returns null at the end of the file
		return (NULL);
	storage = extract_line(next_line);// extracts the next_line and modifies storage to remove the extracted part
	return (next_line);
}
