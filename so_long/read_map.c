/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:02 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/31 00:29:10 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_gnl(int fd)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			return ;
		free(tmp);
	}
}

static int	is_line_empty(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static char	*loop_over_map(int fd)
{
	char	*line;
	char	*holder_map;
	char	*tmp;

	holder_map = ft_strdup("");
	if (!holder_map)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_line_empty(line))
		{
			clear_gnl(fd);
			return (free(line), free(holder_map), NULL);
		}
		tmp = holder_map;
		holder_map = ft_strjoin(holder_map, line);
		free(tmp);
		free(line);
		if (!holder_map)
			return (NULL);
	}
	return (holder_map);
}

char	**read_map(char *path)
{
	int		fd;
	char	*holder_map;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFailed to read file\n");
		exit(1);
	}
	holder_map = loop_over_map(fd);
	close(fd);
	if (!holder_map || !*holder_map)
	{
		free(holder_map);
		return (NULL);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	if (!map)
		return (NULL);
	return (map);
}
