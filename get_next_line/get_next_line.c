/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:09:32 by oel-jrao          #+#    #+#             */
/*   Updated: 2024/11/30 17:23:30 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}

static char	*update_remaining_text(char *current_buffer)
{
	char		*remaining_text;
	ssize_t		i;

	i = 0;
	while (current_buffer[i] != '\n' && current_buffer[i] != '\0')
		i++;
	if (current_buffer[i] == 0)
		return (NULL);
	remaining_text = ft_substr(current_buffer, i + 1,
			ft_strlen(current_buffer) - i);
	if (!remaining_text[0])
	{
		free(remaining_text);
		remaining_text = NULL;
	}
	current_buffer[i + 1] = 0;
	return (remaining_text);
}

static char	*f_remaining(char *remaining_text)
{
	free(remaining_text);
	remaining_text = NULL;
	return (NULL);
}

static char	*read_and_build_line(int fd, char *remaining_text, char *buffer)
{
	ssize_t	byte_read;
	char	*temp;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (f_remaining(remaining_text));
		if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		if (!remaining_text)
			remaining_text = ft_strdup("");
		temp = remaining_text;
		remaining_text = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remaining_text);
}

char	*get_next_line(int fd)
{
	static char	*remaining_text;
	char		*current_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remaining_text);
		remaining_text = NULL;
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	current_line = read_and_build_line(fd, remaining_text, buffer);
	free(buffer);
	buffer = NULL;
	if (!current_line)
		return (NULL);
	remaining_text = update_remaining_text(current_line);
	return (current_line);
}
