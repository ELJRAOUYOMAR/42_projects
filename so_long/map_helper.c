/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:09 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/25 14:49:51 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map_copy, int row, int col)
{
	if (map_copy[row] == NULL || map_copy[row][col] == '\0'
		|| map_copy[row][col] == '1' || map_copy[row][col] == 'V')
		return ;
	map_copy[row][col] = 'V';
	flood_fill(map_copy, row + 1, col);
	flood_fill(map_copy, row - 1, col);
	flood_fill(map_copy, row, col + 1);
	flood_fill(map_copy, row, col - 1);
}

static char	**copy_map(char **map)
{
	char	**map_copy;
	int		row_count;
	int		i;

	row_count = 0;
	while (map[row_count] != NULL)
		row_count++;
	map_copy = (char **)malloc(sizeof(char *) * (row_count + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < row_count)
	{
		map_copy[i] = ft_strdup(map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[row_count] = NULL;
	return (map_copy);
}

void	find_player_position(char **map, int *p_row, int *p_col)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
			{
				*p_row = row;
				*p_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

static int	is_path_valid(char **map_copy)
{
	int	row;
	int	col;

	row = 0;
	while (map_copy[row] != NULL)
	{
		col = 0;
		while (map_copy[row][col] != '\0')
		{
			if (map_copy[row][col] == 'C' || map_copy[row][col] == 'E')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	has_valid_solution(t_game *game)
{
	char	**map_copy;
	int		p_row;
	int		p_col;
	int		result;

	map_copy = copy_map(game->map);
	if (!map_copy)
		return (0);
	find_player_position(game->map, &p_row, &p_col);
	flood_fill(map_copy, p_row, p_col);
	result = is_path_valid(map_copy);
	free_map(map_copy);
	return (result);
}
