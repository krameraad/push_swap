/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ekramer <ekramer@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/21 17:08:11 by ekramer       #+#    #+#                 */
/*   Updated: 2025/12/23 23:50:16 by ekramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*grow_buffer(char **buf, int fd, ssize_t *readcount)
{
	char	*chunk;
	char	*joined;

	chunk = malloc(BUFFER_SIZE + 1);
	if (chunk == NULL)
		return (free(*buf), NULL);
	*readcount = read(fd, chunk, BUFFER_SIZE);
	if (*readcount < 0)
		return (free(*buf), free(chunk), NULL);
	chunk[*readcount] = '\0';
	if (*buf == NULL)
		return (chunk);
	joined = ft_strjoin(*buf, chunk);
	free(*buf);
	free(chunk);
	return (joined);
}

static void	free_and_null(char **s)
{
	free(*s);
	*s = NULL;
}

static char	*extract_line(char **buf, ssize_t *readcount, size_t offset)
{
	char	*line;
	char	*tail;
	size_t	len;

	if (*buf == NULL)
		return (NULL);
	line = NULL;
	len = (size_t)ft_strchr(*buf + offset, '\n');
	if (len > 0)
	{
		len = (len - (size_t)(*buf)) + 1;
		line = ft_substr(*buf, 0, len);
		tail = ft_substr(*buf, len, __SIZE_MAX__);
		free(*buf);
		*buf = tail;
	}
	else if (*readcount < BUFFER_SIZE)
	{
		line = ft_substr(*buf, 0, __SIZE_MAX__);
		if (line != NULL && *line == '\0')
			free_and_null(&line);
		free_and_null(buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;
	ssize_t		readcount;
	size_t		offset;

	readcount = BUFFER_SIZE;
	offset = 0;
	line = extract_line(&buf[fd], &readcount, offset);
	if (line != NULL)
		return (line);
	while (readcount > 0)
	{
		buf[fd] = grow_buffer(&buf[fd], fd, &readcount);
		if (buf[fd] == NULL)
			return (NULL);
		line = extract_line(&buf[fd], &readcount, offset);
		if (line != NULL)
			return (line);
		offset += readcount;
	}
	return (NULL);
}
