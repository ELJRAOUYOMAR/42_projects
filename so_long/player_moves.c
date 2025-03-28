/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:04 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/25 14:41:56 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_img(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w' || key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"textures/PD.xpm", &game->img_w, &game->img_h);
	else if (key == 's' || key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx,
				"textures/PA.xpm", &game->img_w, &game->img_h);
}

void	move_w(t_game *game)
{
	update_player_img('w', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->moves++;
		finish_game_with_success(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		render_map(game);
	}
}

void	move_s(t_game *game)
{
	update_player_img('s', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->moves++;
		finish_game_with_success(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		render_map(game);
	}
}

void	move_d(t_game *game)
{
	update_player_img('d', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->moves++;
		finish_game_with_success(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		render_map(game);
	}
}

void	move_a(t_game *game)
{
	update_player_img('a', game);
	if (game->map[game->y_player][game->x_player] == 'E' && game->n_colect == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->moves++;
		finish_game_with_success(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
		|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_colect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		render_map(game);
	}
}
