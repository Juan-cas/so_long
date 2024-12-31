/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:16:16 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 08:07:54 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/*a function that uses the read function to read buffer_size from the file
 * and checks for new line*/
char	*reader(int fd, char *saver)
{
	char	*storage;
	int		bytesread;

	bytesread = BUFFER_SIZE;
	storage = NULL;
	while (search_n(saver, '\n') < 0 && bytesread == BUFFER_SIZE)
	{
		storage = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!storage)
			return (free(saver), NULL);
		bytesread = read(fd, storage, BUFFER_SIZE);
		if (bytesread < 0)
			return (free(storage), NULL);
		if (bytesread > 0)
		{
			saver = append(saver, storage);
			if (!saver)
				return (NULL);
		}
		if (bytesread == 0)
			return (free(storage), saver);
	}
	return (saver);
}

/*this function was made to protect all the mallocs made when returning a line*/
char	*mprotect(char *line, char **saver, int i)
{
	char	*oldptr;

	oldptr = *saver;
	line = ft_substr(*saver, 0, i + 1);
	if (!line)
		return (NULL);
	*saver = ft_substr(*saver, i + 1, ft_strlen(*saver) - i);
	if (!*saver)
		return (free(line), free(oldptr), NULL);
	if (*saver[0] == '\0')
	{
		free(*saver);
		*saver = NULL;
	}
	free(oldptr);
	return (line);
}

/*this function is used to return the final line of the file*/
char	*finalline(char *line, char **saver)
{
	int	i;

	i = search_n(*saver, '\n');
	if (i >= 0)
	{
		line = mprotect(line, saver, i);
		if (!line)
			return (free(*saver), *saver = NULL, NULL);
	}
	else if (line == NULL && *saver[0] != '\0')
	{
		line = ft_substr(*saver, 0, ft_strlen(*saver));
		if (!line)
			return (free(*saver), *saver = NULL, NULL);
		free(*saver);
		*saver = NULL;
	}
	else
		return (free(*saver), *saver = NULL, NULL);
	return (line);
}

/**
 * @brief function gets a line from the fd.
 * @param fd the file descriptor that contains the
 * opened file that will be read.
 */
char	*get_next_line(int fd)
{
	static char	*saver = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0)
	{
		perror("Invadlid buffersize");
		exit(1);
	}
	line = NULL;
	saver = reader(fd, saver);
	if (!saver)
		return (NULL);
	line = finalline(line, &saver);
	if (!line)
		return (NULL);
	return (line);
}
