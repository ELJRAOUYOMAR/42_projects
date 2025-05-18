/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:14 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/30 22:26:47 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game, int exit_type)
{
	if (!game || !game->mlx)
		exit(1);
	if (game->img_backg)
		mlx_destroy_image(game->mlx, game->img_backg);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_colect)
		mlx_destroy_image(game->mlx, game->img_colect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->map)
		free_map(game->map);
	exit(exit_type);
	return (0);
}

void	finish_game_with_success(t_game *game)
{
	ft_printf("Moves: %d\n", game->moves);
	ft_printf("You have collected all items and exited successfully! 🎉\n");
	exit_game(game, 0);
}
