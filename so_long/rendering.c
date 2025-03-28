/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:00 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/25 15:15:47 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * 32, y * 32);
}

static void	render_player(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	render_img(game, image, x, y);
}

static void	render_exit(t_game *game, int x, int y)
{
	if (game->n_colect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"textures/E2.xpm", &game->img_w, &game->img_h);
	}
	render_img(game, game->img_exit, x, y);
}

int	render_map(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[col])
	{
		row = 0;
		while (game->map[col][row])
		{
			if (game->map[col][row] == '1')
				render_img(game, game->img_wall, row, col);
			else if (game->map[col][row] == '0')
				render_img(game, game->img_backg, row, col);
			else if (game->map[col][row] == 'P')
				render_player(game, game->img_player, row, col);
			else if (game->map[col][row] == 'C')
				render_img(game, game->img_colect, row, col);
			else if (game->map[col][row] == 'E')
				render_exit(game, row, col);
			row++;
		}
		col++;
	}
	return (0);
}
