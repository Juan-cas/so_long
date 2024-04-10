
#include "../solong.h"


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

char	*lets_rolls(char *line, char **saver, int i)
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

char	*finalline(char *line, char **saver)
{
	int	i;

	i = search_n(*saver, '\n');
	if (i >= 0)
	{
		line = lets_rolls(line, saver, i);
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



char	*get_next_line(int fd)
{
	static char	*saver = NULL;
	char		*line;

	if (BUFFER_SIZE <= 0)
	{
		perror("Invadlid buffersize");
		exit (1);
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
