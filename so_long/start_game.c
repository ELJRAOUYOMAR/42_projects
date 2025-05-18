/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:25:55 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/31 00:57:40 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->y_player -= 1;
		move_w(game);
	}
	else if (keycode == KEY_S)
	{
		game->y_player += 1;
		move_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->x_player += 1;
		move_d(game);
	}
	else if (keycode == KEY_A)
	{
		game->x_player -= 1;
		move_a(game);
	}
}

static int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, 0);
	game_events(keycode, game);
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_A)
		ft_printf("Moves: %d\n", game->moves);
	return (0);
}

void	game_start(t_game *game)
{
	mlx_hook(game->win, KEYPRESS, 1L, key_press, game);
	mlx_hook(game->win, DESTROYNOTIFY, 0, exit_game, game);
}
