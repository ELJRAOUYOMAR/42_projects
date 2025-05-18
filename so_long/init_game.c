/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:12 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/30 22:26:43 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	failed_to_load_img(t_game *game)
{
	if (!game->img_backg || !game->img_wall || !game->img_player
		|| !game->img_colect || !game->img_exit)
	{
		ft_printf("Error\n");
		ft_printf("You edited a file name or it's missing!\n");
		exit_game(game, 1);
	}
}

static void	init_img(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm",
			&game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm",
			&game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/PD.xpm", &game->img_w, &game->img_h);
	game->img_colect = mlx_xpm_file_to_image(game->mlx, "textures/C.xpm",
			&game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/E1.xpm",
			&game->img_w, &game->img_h);
	failed_to_load_img(game);
}

static void	init_window_size(t_game *game)
{
	int	i;

	i = 0;
	game->map_w = ft_strlen(game->map[0]) * 32;
	while (game->map[i] != NULL)
		i++;
	game->map_h = i * 32;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img_backg = NULL;
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_colect = NULL;
	game->img_exit = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nThe connection to mlx failed\n");
		if (game->map)
			free_map(game->map);
		exit(1);
	}
	init_window_size(game);
	init_img(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	render_map(game);
}
