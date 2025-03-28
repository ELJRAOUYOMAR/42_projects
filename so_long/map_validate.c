/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:07 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/25 02:14:19 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_map_retangular(char **map)
{
	int	row;

	row = 1;
	if (!map)
		return (0);
	while (map[row] != NULL)
	{
		if (ft_strlen(map[row]) != ft_strlen(map[0]))
			return (0);
		row++;
	}
	return (1);
}

static int	is_surrounded_by_wall(char **map)
{
	int	row;
	int	col;
	int	row_lenght;

	col = 0;
	row = 0;
	while (map[row] != NULL)
		row++;
	while (map[0][col] != '\0' && map[row - 1][col] != '\0')
	{
		if (map[0][col] != '1' || map[row - 1][col] != '1')
			return (0);
		col++;
	}
	row = 1;
	row_lenght = ft_strlen(map[row]);
	while (map[row] != NULL)
	{
		if (map[row][0] != '1' || map[row][row_lenght - 1] != '1')
			return (0);
		row++;
	}
	return (1);
}

static int	is_valide_map_element(t_game *game)
{
	int	row;
	int	col;

	game->n_colect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	row = 0;
	while (game->map[row] != NULL)
	{
		col = 0;
		while (game->map[row][col] != '\0')
		{
			if (game->map[row][col] == 'P')
				game->n_player++;
			else if (game->map[row][col] == 'E')
				game->n_exit++;
			else if (game->map[row][col] == 'C')
				game->n_colect++;
			col++;
		}
		row++;
	}
	if (game->n_player != 1 || game->n_exit != 1 || game->n_colect < 1)
		return (0);
	return (1);
}

static int	is_validate_items(char **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] != 'P' && map[row][col] != 'E'
				&& map[row][col] != 'C' && map[row][col] != '0'
				&& map[row][col] != '1')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

int	is_valide_map(t_game *game)
{
	if (is_map_retangular(game->map) && is_surrounded_by_wall(game->map)
		&& is_valide_map_element(game) && is_validate_items(game->map)
		&& has_valid_solution(game) && has_valid_solution_2(game))
		return (1);
	return (0);
}
