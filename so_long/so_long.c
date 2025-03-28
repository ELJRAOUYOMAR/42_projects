/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-jrao <oel-jrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 03:25:58 by oel-jrao          #+#    #+#             */
/*   Updated: 2025/03/25 15:12:48 by oel-jrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_err(t_game *game, char *message)
{
	if (game->map)
		free_map(game->map);
	ft_printf("Error\n");
	ft_printf("%s", message);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (!is_valid_argv(argv[1]))
			print_err(&game, "Check the file extension!\n");
		else if (!is_valide_map(&game))
			print_err(&game, "Invalid Map!\n");
		else
		{
			init_game(&game);
			game_start(&game);
			mlx_loop(game.mlx);
		}
	}
	else
	{
		printf("Error\nInvalid Sytax");
		exit(1);
	}
	return (0);
}
