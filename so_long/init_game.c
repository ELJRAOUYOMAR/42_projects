/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:26:12 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/25 15:13:40 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nThe connection to mlx failed\n");
		if (game->map)
			free_map(game->map);
		exit(1);
	}
	init_window_size(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "so_long");
	game->moves = 0;
	init_img(game);
	render_map(game);
}
